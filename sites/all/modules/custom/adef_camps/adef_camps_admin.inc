<?php

function adef_camps_configure() {
  return drupal_get_form('adef_camps_configure_form');
}

function adef_camps_configure_form($form, &$form_state) {
  $form['start_date'] = array(
      '#type' => 'date',
      '#title' => t('Camps start date'),
      '#default_value' => variable_get('adef_camps_start_date', array(
          'year' => getdate()['year'],
          'month' => getdate()['mon'],
          'day' => getdate()['mday'],
      )),
  );
  $form['day_breakpoints'] = array(
      '#type' => 'textfield',
      '#title' => t('Day breakpoints'),
      '#description' => t('Session registartion takes place at every breakpoint showing number of days until next breakpoint. Separate breakpoints by comma. If you enter one breakpoint only it will apply uniformly to the camp. Example: "2,4,3,2" will show 4 days from day 2, 3 days from day 4, and 2 days from day 3 (assuming they are the last 2 days). "3" will show 3 days to register every 3 days.'),
      '#default_value' => strval(variable_get('adef_camps_daybreakpoints', '2')),
  );
  $form['ignore_full_workshop'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow sessions of any workshop to be registered regardless of other sessions in the same workshop.'),
      '#default_value' => variable_get('adef_camps_ignore_full_workshop', FALSE),
  );
  $form['switch_hour'] = array(
      '#type' => 'textfield',
      '#title' => t('Switch hour'),
      '#description' => t('Which hour should the system use to switch to the next set of days schedule. Use 24 hour format. Example: "22" for 10:00 PM.'),
      '#default_value' => strval(variable_get('adef_camps_switch_hour', 21)),
      '#size' => 2,
  );
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
  );
  return $form;
}

function adef_camps_configure_form_submit($form, &$form_state) {
  variable_set('adef_camps_start_date', $form_state['values']['start_date']);
  variable_set('adef_camps_switch_hour', intval($form_state['values']['switch_hour']));
  variable_set('adef_camps_daybreakpoints', $form_state['values']['day_breakpoints']);
  variable_set('adef_camps_ignore_full_workshop', $form_state['values']['ignore_full_workshop']);
  drupal_set_message(t('Configuration was saved.'));
}

function adef_camps_configure_form_validate($form, &$form_state) {
  $switch_hour = $form_state['values']['switch_hour'];
  $pass = TRUE;
  if (!is_numeric($switch_hour)) {
    $pass = FALSE;
  } else {
    $switch_hour = intval($switch_hour);
    if ($switch_hour > 23 || $switch_hour < 0)
      $pass = FALSE;
  }
  if (!$pass) {
    form_set_error('switch_hour', t('You must enter a number between 0 and 23.'));
  }
}

function adef_camps_generate_slots() {
  require_once 'adef_camps.pages.inc';
  $voc = _adef_camps_voc_to_array(_adef_camps_get_vid_byname('locations'), FALSE);
  if (count($voc) > 0) {
    return drupal_get_form('adef_camps_generate_slots_form');
  } else {
    return t("No locations defined yet. Please add locations before attemting to create slots.");
  }
}

function adef_camps_generate_slots_form($form, &$form_state) {
  $form = array();
  $form['date_from'] = array(
      '#description' => t('Beginning date.'),
      '#weight' => '0',
      '#required' => '0',
      '#type' => 'date',
      '#title' => t('From'),
  );
  $form['date_to'] = array(
      '#description' => t('Ending date.'),
      '#weight' => '1',
      '#required' => '0',
      '#type' => 'date',
      '#title' => t('To'),
  );
  $form['hours'] = array(
      '#weight' => '2',
      '#required' => '0',
      '#description' => t('Type starting hours in 24hr format with decimals or minutes separated by commas. For example: 10,12:30,15.25,17 for 10:00am, 12:30p, 03:15pm, 05:00pm.'),
      '#type' => 'textfield',
      '#title' => t('Start Hours'),
  );
  $form['locations'] = array(
      '#weight' => '4',
      '#options' => _adef_camps_voc_to_array(_adef_camps_get_vid_byname('locations'), FALSE),
      '#type' => 'checkboxes',
      '#title' => t('Locations'),
      '#description' => t('Select locations to create slots for. If none are selected then slots will be created for all available locations.'),
  );
  $form['submit'] = array(
      '#weight' => '5',
      '#type' => 'submit',
      '#value' => t('Generate'),
  );
  return $form;
}

function adef_camps_generate_slots_form_validate($form, &$form_state) {
  
}

function adef_camps_generate_slots_form_submit($form, &$form_state) {
  $hours = explode(",", $form_state['values']['hours']);
  //validate hours
  foreach ($hours as $pos => $hour) {
    if (!is_numeric($hour) && strlen($hour) == 5) {
      if (strpos($hour, ":") == 2) {
        $hours[$pos] = intval(substr($hour, 0, 2)) + (intval(substr($hour, 3, 2)) / 60);
      } else {
        unset($hours[$pos]);
      }
    } else {
      unset($hours[$pos]);
    }
  }
  $date_from = $form_state['values']['date_from']['year'] . "-" . $form_state['values']['date_from']['month'] . "-" . $form_state['values']['date_from']['day'];
  $date_to = $form_state['values']['date_to']['year'] . "-" . $form_state['values']['date_to']['month'] . "-" . $form_state['values']['date_to']['day'];
  $diff = date_diff(new DateTime($date_from), new DateTime($date_to), TRUE);
  $locations = $form_state['values']['locations'];
  if (array_sum($form_state['values']['locations']) == 0) {
    $locations = array_fill_keys(array_keys($locations), 1);
  }
  global $user;
  foreach ($locations as $tid => $value) {
    if ($value != 0) {
      for ($i = 0; $i <= $diff->d; $i++) {
        $curdate = strtotime($date_from);
        $curdate += $i * 60 * 60 * 24;
        foreach ($hours as $hour) {
          if (is_numeric($hour)) {
            $slot_start = date('Y-m-d H:i', $curdate + ($hour * 60 * 60));
            //Create the node and save it
            $node = new stdClass();
            $node->type = "timespace";
            node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
            $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled
            $node->uid = $user->uid;
            $node->status = 1; //(1 or 0): published or not
            $node->promote = 0; //(1 or 0): promoted to front page
            // Term reference (taxonomy) field
            $node->field_location[$node->language][]['tid'] = $tid;
            $node->field_date_time[$node->language][]['value'] = $slot_start;
            $node = node_submit($node); // Prepare node for saving
            node_save($node);
          }
        }
      }
    }
  }
}
