<?php

function adef_camps_register($node) {
  $period_date = adef_camps_get_period_date();
  $days_to_show = $period_date['days_to_show'];
  drupal_add_js(
          "var adefCampsDaysToShow = " . $days_to_show . ";\n" . 
          "var adefCampsStartDate = new Date('" . $period_date['year'] . "-" . $period_date['month'] . "-" . $period_date['day'] . "');",
          'inline');
  drupal_add_js(array(
      'adef_camps' => array(
          'ignoreFullWorkshop' => variable_get('adef_camps_ignore_full_workshop', FALSE)
          ),
      ),
          'setting');
  drupal_add_js(drupal_get_path('module', 'adef_camps') . '/js/adef_camps_ui_common.js');
  drupal_add_js(drupal_get_path('module', 'adef_camps') . '/js/adef_camps_registration_interface.js');
  $views_date_arg = $period_date['year'] . '-' . $period_date['month'] . '-' . $period_date['day'] . '--P'. $days_to_show .'D'; //--P8D for 2014 only to show all days of camp
  $sessions = views_get_view_result('content_blocks', 'block_sessions', $views_date_arg);
  $user_sessions = views_get_view_result('content_blocks', 'block_sessions', $views_date_arg, $node->nid);
  //user_sessrions[i]->nid
  $selected = array();
  foreach ($user_sessions as $timespace) {
    $selected[] = $timespace->nid;
  }
  $selected_string = implode(',', $selected);
  $form = drupal_get_form('adef_camps_registration_form', $node, $selected_string);
//  $page['registered'] = array(
//      '#type' => 'markup',
//      '#markup' => '<div id="registered-sessions">' . views_embed_view('content_blocks', 'block_sessions', $views_date_arg, $node->nid) . '</div>',
//  );
  $page['available'] = array(
      '#type' => 'markup',
      '#markup' => '<div id="available-sessions">' . views_embed_view('content_blocks', 'block_sessions', $views_date_arg) . '</div>',
  );
  $page['form'] = $form;
  $page['attended'] = array(
      '#type' => 'markup',
      '#markup' => '<div id="attended">' . views_embed_view('content_blocks', 'block_participant_attendance', $node->nid) . '</div>',
  );
  return $page;
}

function adef_camps_registry($node, $type) {
  drupal_add_js(drupal_get_path('module', 'adef_camps') . '/js/adef_camps_registry_entry_interface.js');

  switch ($type) {
    case 'achievement':
      $title_suffix = t('Achievments');
      break;
    case 'incident':
      $title_suffix = t('Incidents');
      break;
  }
  drupal_set_title(drupal_get_title() . ": " . $title_suffix, CHECK_PLAIN);

  $page['form'] = drupal_get_form('adef_camps_registery_entry_form', $node, $type);
  $page['log'] = array(
      '#type' => 'markup',
      '#markup' => '<div id="l">' . views_embed_view('content_blocks', 'block_participant_registry', $node->nid, $type) . '</div>',
  );
  return $page;
}

/*
 * Return page array with schedule for the participant.
 */
function adef_camps_schedule($node) {
  $period_date = adef_camps_get_period_date();
  $views_date_arg = $period_date['year'] . '-' . $period_date['month'] . '-' . $period_date['day'] . '--P2D';
  $page['schedule'] = array(
      '#type' => 'markup',
      '#markup' => '<div id="participant-schedule">' . views_embed_view('content_blocks', 'block_participant_schedule', $node->nid) . '</div>',
  );
  return $page;
}

function adef_camps_registration_form($form, &$form_state, $node, $selected) {
  $form = array(
      'timespace' => array(
          '#type' => 'hidden',
          '#default_value' => $selected,
      ),
      'old_timespace' => array(
          '#type' => 'hidden',
          '#value' => $selected,
      ),
      'participant_id' => array(
          '#type' => 'hidden',
          '#value' => $node->nid,
      ),
      'submit' => array(
          '#type' => 'submit',
          '#value' => t('Submit'),
      )
  );
  return $form;
}

function adef_camps_registration_form_submit($form, &$form_state) {
  $participant_nid = $form_state['values']['participant_id'];
  $timespace = $form_state['values']['timespace'] != '' ? explode(',', $form_state['values']['timespace']) : array();
  $old_timespace = $form_state['values']['old_timespace'] != '' ? explode(',', $form_state['values']['old_timespace']) : array();
  $timespace_add = array_diff($timespace, $old_timespace);
  $timespace_remove = array_diff($old_timespace, $timespace);
  foreach ($timespace_add as $nid) {
    $node = node_load($nid);
    //check max participnats
    $session = node_load($node->field_session[LANGUAGE_NONE][0]['target_id']);
    $workshop = node_load($session->field_workshop[LANGUAGE_NONE][0]['target_id']);
    $max = $workshop->field_max_participants[LANGUAGE_NONE][0]['value'];
    $participants = 0;
    if (!empty($node->field_participants)) {
      $participants = count($node->field_participants[LANGUAGE_NONE]);
    }
    if ($participants < $max) {
      $node->field_participants[LANGUAGE_NONE][] = array(
          'target_id' => $participant_nid,
          'target_type' => 'node',
      );
      node_submit($node);
      node_save($node);
    } else {
      drupal_set_message(t('No more space in @session', array('@session' => $session->title)), 'warning');
    }
  }
  foreach ($timespace_remove as $nid) {
    $node = node_load($nid);
    $participants = $node->field_participants[LANGUAGE_NONE];
    foreach ($participants as $key => $item) {
      if ($item['target_id'] == $participant_nid) {
        unset($node->field_participants[LANGUAGE_NONE][$key]);
      }
    }
    if (count($node->field_participants[LANGUAGE_NONE]) == 0) {
      unset($node->field_participants[LANGUAGE_NONE]);
    }
    node_submit($node);
    node_save($node);
  }
  drupal_set_message(t('Registration is done.'));
}

function adef_camps_attendance($node) {
  $page['form'] = drupal_get_form('adef_camps_attendance_form', $node);
  return $page;
}

function adef_camps_attendance_form($form, &$form_state, $node) {
  //get registered attendance cases for the timespace
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'attendance')
          ->fieldCondition('field_timespace', 'target_id', $node->nid, '=');
  $result = $query->execute();
  $nodes = array_keys($result['node']);

  $selected = array();
  foreach ($nodes as $nid) {
    $attendance_node = node_load($nid);
    $selected[] = $attendance_node->field_participants[LANGUAGE_NONE][0]['target_id'];
  }

  $form = array();

  //build participants options
  $form['participants'] = array(
      '#default_value' => $selected, //check registered cases
      '#required' => '0',
      '#key_type_toggled' => '0',
      '#type' => 'checkboxes',
      '#options' => array(),
      '#title' => t('Participants'),
  );
  $node_render = node_view($node);
  foreach ($node_render['field_participants']['#items'] as $participant) {
    $form['participants']['#options'][$participant['entity']->nid] = $participant['entity']->title;
  }
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
  );
  return $form;
}

function adef_camps_attendance_form_submit($form, &$form_state) {
  drupal_goto('node/6');
}

function adef_camps_registery_entry_form($form, &$form_state, $node, $type) {
  $form = array();
  $form['new'] = array(
      '#title' => t('Add new'),
      '#collapsed' => '1',
      '#type' => 'fieldset',
      '#collapsible' => '1',
  );
  $vid = _adef_camps_get_vid_byname('fields');
  $form['new']['track'] = array(
      '#required' => '0',
      '#multiple' => '0',
      '#key_type_toggled' => '0',
      '#type' => 'select',
      '#options' => _adef_camps_voc_to_array($vid),
      '#multiple_toggle' => '1',
      '#title' => t('In Track'),
  );
  $vid = _adef_camps_get_vid_byname('educational_goals');
  $form['new']['goal'] = array(
      '#required' => '0',
      '#multiple' => '0',
      '#key_type_toggled' => '0',
      '#type' => 'select',
      '#options' => _adef_camps_voc_to_array($vid),
      '#multiple_toggle' => '1',
      '#title' => t('Educational Goal'),
  );
  $form['new']['notes'] = array(
      '#required' => '1',
      '#type' => 'textarea',
      '#title' => t('Notes'),
  );
  $form['type'] = array(
      '#type' => 'hidden',
      '#value' => $type,
  );
  $form['participant_id'] = array(
      '#type' => 'hidden',
      '#value' => $node->nid,
  );
  $form['new']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
  );
  return $form;
}

function adef_camps_registery_entry_form_validate(&$form, &$form_state) {
  //drupal_set_message(print_r($form_state['values'], TRUE));
  if ($form_state['values']['track'] == '0' && $form_state['values']['goal'] == '0') {
    form_error($form['new']['goal'], t('Either "In Track" or "Educational Goal" needs to be set.'));
    form_error($form['new']['track']);
    $form['new']['#collapsed'] = '0';
  }
}

function adef_camps_registery_entry_form_submit($form, &$form_state) {
  global $user;
  $langcode = LANGUAGE_NONE;
  $node = new stdClass();
  $node->type = "register_entry";
  node_object_prepare($node); // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
  $node->language = $langcode; // Or e.g. 'en' if locale is enabled
  $node->uid = $user->uid;
  $node->status = 1; //(1 or 0): published or not
  $node->promote = 0; //(1 or 0): promoted to front page

  $node->body[LANGUAGE_NONE][0]['value'] = $form_state['values']['notes'];
  $node->field_register_type[LANGUAGE_NONE][]['value'] = $form_state['values']['type'];
  $node->field_register_participant[LANGUAGE_NONE][] = array(
      'target_id' => $form_state['values']['participant_id'],
      'target_type' => 'node',
  );
  if ($form_state['values']['goal'] != '0') {
    $node->field_register_edu_goal[LANGUAGE_NONE][]['tid'] = $form_state['values']['goal'];
  } else {
    $node->field_register_track[LANGUAGE_NONE][]['tid'] = $form_state['values']['track'];
  }
  $node = node_submit($node); // Prepare node for saving
  node_save($node);
  drupal_set_message(t('Registery entry added.'));
}

function _adef_camps_voc_to_array($vid, $add_blank = TRUE) {
  $terms = taxonomy_get_tree($vid);
  if ($add_blank) {
    $output[0] = '';
  }
  foreach ($terms as $data) {
    $output[$data->tid] = $data->name;
  }
  return $output;
}

function _adef_camps_get_vid_byname($vocabulary) {
  $v = taxonomy_vocabulary_machine_name_load($vocabulary);
  return $v->vid;
}
