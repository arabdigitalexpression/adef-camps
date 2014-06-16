<?php
/**
 * @file
 * Handles user administrative settings.
 *
 * Administrators can choose which entities they wish to trigger a cascade
 * deletion and which entities are subject to it.
 *
 * @ingroup ercd
 */

/**
 * Menu callback.
 *
 * Displays a list of all referenced entities along with their
 * respective referencing entities.
 *
 * @see ercd_admin_menu()
 */
function ercd_admin_settings($form, $form_state) {
  $ercd_path = drupal_get_path('module', 'ercd');
  drupal_add_css($ercd_path . '/ercd.css');
  drupal_add_js($ercd_path . '/ercd.js');

  // Instructions to user.
  $form['preamble'] = array(
    '#markup' => '<p>' . t('<strong class="ercd-alert">Please choose carefully!</strong>: From the entities below, choose which referencing entities should be subject to cascade deletion. Users with proper !permissions_link will be able to override these default settings, effectively turning on or off cascade deletion on a per-entity basis.', array(
      '!permissions_link' => l(t('permissions'), 'admin/people/permissions', array('fragment' => 'module-entityreference_cascade_delete',
      )),
    )) . '</p>',
  );

  // Get the selected direction.
  $reference_direction = variable_get('ercd_reference_direction', NULL);

  $form['ercd_reference_direction_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Change entity reference direction'),
    '#collapsible' => TRUE,
    '#collapsed' => $reference_direction == NULL ? FALSE : TRUE,
  );

  $form['ercd_reference_direction_fieldset']['ercd_reference_direction'] = array(
    '#type' => 'radios',
    '#title' => t('Choose the model below the fits the situation in which you would like to trigger cascade deletion.'),
    '#default_value' => $reference_direction,
    '#options' => array(
      'desc' => theme('image', array(
        'path' => $ercd_path . '/images/parent_referencing_children.jpg',
        'alt' => t('Parent referencing children.'),
        'title' => t('Parent referencing children.'),
      )),
      'asc' => theme('image', array(
        'path' => $ercd_path . '/images/children_referencing_parent.jpg',
        'alt' => t('Children referencing parent.'),
        'title' => t('Children referencing parent.'),
      )),
    ),
    '#required' => TRUE,
    '#attributes' => array('class' => array('clearfix')),
    '#ajax' => array(
      'callback' => 'ercd_update_settings_reference_tree',
      'wrapper' => 'ercd-target-wrapper',
      'effect' => 'fade',
    ),
  );

  // Main wrapper.
  $form['ercd_wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('ercd-wrapper')),
    '#prefix' => '<div id="ercd-target-wrapper"><strong>' . t('Set up entities that will trigger a cascade deletion and which related entities will be effected.') . '</strong>',
    '#suffix' => '</div>',
  );

  $selected = isset($form_state['values']['ercd_reference_direction']) ? $form_state['values']['ercd_reference_direction'] : $form['ercd_reference_direction_fieldset']['ercd_reference_direction']['#default_value'];

  if ($selected != NULL) {
    ercd_build_settings_reference_tree($form, $selected);

    // Let user know they need to set up entity reference fields to see
    // anything here.
    if (!isset($form['ercd_wrapper']['ercd_row_0'])) {
      $form['ercd_wrapper']['no_entities_message'] = array('#markup' => '<div class="ercd-row odd"><p>' . t('No entities have been set up with entity reference fields.') . '</p></div>');
    }
  }
  else {
    // Let user know they need to choose a reference model before setting up.
    $form['ercd_wrapper']['no_entities_message'] = array('#markup' => '<div class="ercd-row odd"><p>' . t('Choose a reference model above to see entity reference relationships here.') . '</p></div>');
  }

  return system_settings_form($form);
}

/**
 * Ajax callback for the reference direction radios.
 *
 * This function will return the correct options depending on which of the
 * 2 radio buttons is selected.
 *
 * @return array
 *   The form element array we want returned by the ajax call.
 *
 * @see ercd_admin_settings()
 */
function ercd_update_settings_reference_tree($form, &$form_state) {
  return $form['ercd_wrapper'];
}

/**
 * Develops a tree of checkbox options.
 *
 * This function should drill down from a referenced entity down the various
 * referencing entity branches until it hits the bottom. Essentially, this
 * should develop a tree of checkbox options that drill down from a top-level
 * entity down to children, grandchildren, etc.
 *
 * @param array $form
 *   A form array passed by reference.
 * @param string $reference_direction
 *   A string containing the value either asc or desc to determine the type
 *   of reference relationship we are working with.
 */
function ercd_build_settings_reference_tree(&$form, $reference_direction) {
  $all_entities = field_info_bundles();
  $reference_type = 'Referenced';
  if ($reference_direction == 'asc') {
    $reference_type = 'Referencing';
  }

  $row_count = 0;

  foreach ($all_entities as $type => $type_info) {
    if (ercd_valid_entity($type)) {
      foreach ($type_info as $bundle => $bundle_info) {
        // Only display settings for entities that have an entity reference.
        $reference_entities = ercd_get_child_entities($type, $bundle, $reference_direction, $all_entities);

        if (count($reference_entities)) {
          // Get the entity info so we can have the label.
          $entity_info = entity_get_info($type);

          $entity_check_value = variable_get('ercd_trigger_' . $type . '__' . $bundle . '_' . $reference_direction, FALSE);

          $odd_even = 'even';
          if ($row_count % 2 == 0) {
            $odd_even = 'odd';
          }

          // Row.
          $form['ercd_wrapper']['ercd_row_' . $row_count] = array(
            '#type' => 'container',
            '#attributes' => array('class' => array('ercd-row ' . $odd_even)),
          );

          // Referenced entity checkbox.
          $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_trigger_' . $type . '__' . $bundle . '_' . $reference_direction] = array(
            '#type' => 'checkbox',
            '#title' => t('<strong>@type: @bundle - Trigger a cascade deletion when deleting this entity.</strong>', array(
              '@type' => $entity_info['label'],
              '@bundle' => $bundle_info['label'],
            )),
            '#default_value' => $entity_check_value,
            '#attributes' => array(
              'class' => array(
                'ercd-trigger',
                'ercd-setting',
              )),
          );

          // Container style setup.
          $style = array();
          if (!$entity_check_value) {
            $style[] = 'display: none;';
          }

          // Child container.
          $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count] = array(
            '#type' => 'container',
            '#attributes' => array(
              'class' => array('ercd-child'),
              'style' => $style,
            ),
          );

          // Fieldset.
          $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count]['ercd_' . $type . '_' . $bundle] = array(
            '#type' => 'fieldset',
            '#title' => t('Select Individual @referenceType Entities for @type: @bundle', array(
              '@referenceType' => $reference_type,
              '@type' => $entity_info['label'],
              '@bundle' => $bundle_info['label'],
            )),
            '#description' => t('Selected entities below may be deleted when a @type: @bundle is deleted.', array(
              '@type' => $entity_info['label'],
              '@bundle' => $bundle_info['label'],
            )),
            '#collapsible' => TRUE,
            '#collapsed' => TRUE,
            '#attributes' => array('class' => array('ercd-fieldset')),
          );

          // List referencing entity checkboxes.
          $wrapper_count = 0;
          foreach ($reference_entities as $reference_entity) {
            // Get entity info for the labels.
            $entity_info = entity_get_info($reference_entity['type']);

            // Wrapper.
            $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count]['ercd_' . $type . '_' . $bundle]['wrapper_' . $wrapper_count] = array(
              '#type' => 'container',
              '#attributes' => array('class' => array('ercd-sub-wrapper')),
            );

            // Checkbox.
            $child_check_value = variable_get('ercd_' . $reference_direction . '_' . $type . '__' . $bundle . '__' . $reference_entity['type'] . '__' . $reference_entity['bundle'], FALSE);
            $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count]['ercd_' . $type . '_' . $bundle]['wrapper_' . $wrapper_count]['ercd_' . $reference_direction . '_' . $type . '__' . $bundle . '__' . $reference_entity['type'] . '__' . $reference_entity['bundle']] = array(
              '#type' => 'checkbox',
              '#title' => t('Include in cascade deletion.'),
              '#prefix' => '<strong>' . t('@type: @bundle Settings', array(
                '@type' => $entity_info['label'],
                '@bundle' => $entity_info['bundles'][$reference_entity['bundle']]['label'],
              )) . '</strong>',
              '#default_value' => $child_check_value,
              '#attributes' => array('class' => array('ercd-trigger ercd-setting')),
            );

            $style = '';
            if (!$child_check_value) {
              $style = 'display: none;';
            }

            $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count]['ercd_' . $type . '_' . $bundle]['wrapper_' . $wrapper_count]['ercd_' . $reference_direction . '_' . $type . '__' . $bundle . '__' . $reference_entity['type'] . '__' . $reference_entity['bundle'] . '_default_state'] = array(
              '#type' => 'radios',
              '#title' => t('Default state on delete confirm pages'),
              '#title_display' => 'invisible',
              '#field_prefix' => '<div style="' . $style . '" class="ercd-default-state">' . t('Default state on delete confirm pages:'),
              '#field_suffix' => '</div>',
              '#options' => array(
                'unchecked' => t('Unchecked (Safest)'),
                'checked' => t('Checked (Safer)'),
                'forced' => t('Forced (CAUTION: users will not have a choice to select or unselect child entities <strong><em>OR</em></strong> their descendents <strong><em>regardless of permissions</em></strong>...they will just be deleted no matter what.)'),
              ),
              '#default_value' => variable_get('ercd_' . $reference_direction . '_' . $type . '__' . $bundle . '__' . $reference_entity['type'] . '__' . $reference_entity['bundle'] . '_default_state', 'unchecked'),
            );

            // Add role options if this is a user reference.
            if ($reference_entity['type'] == 'user') {
              $user_roles = user_roles();
              $immune_roles = variable_get('ercd_immune_roles', array());
              foreach ($user_roles as $id => $role) {
                if (in_array($id, $immune_roles)) {
                  unset($user_roles[$id]);
                }
              }

              if (count($user_roles)) {
                // Container style setup.
                $style = array();
                if (!$child_check_value) {
                  $style[] = 'display: none;';
                }

                // Child container.
                $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count]['ercd_' . $type . '_' . $bundle]['wrapper_' . $wrapper_count]['ercd_child_roles_' . $row_count] = array(
                  '#type' => 'container',
                  '#attributes' => array(
                    'class' => array('ercd-child'),
                    'style' => $style,
                  ),
                );

                $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count]['ercd_' . $type . '_' . $bundle]['wrapper_' . $wrapper_count]['ercd_child_roles_' . $row_count]['fieldset'] = array(
                  '#type' => 'fieldset',
                  '#title' => t('Select individual user roles'),
                  '#description' => t('Select individual user roles to be affected. User ID 1 and Administrator role users are all "safe".'),
                  '#collapsible' => TRUE,
                  '#collapsed' => TRUE,
                  '#attributes' => array('class' => array('ercd-fieldset ercd-user-roles')),
                );

                foreach ($user_roles as $rid => $role) {
                  if ($rid == 2) {
                    $user_roles[$rid] .= " (with no other role assignments)";
                  }
                }

                $form['ercd_wrapper']['ercd_row_' . $row_count]['ercd_child_' . $row_count]['ercd_' . $type . '_' . $bundle]['wrapper_' . $wrapper_count]['ercd_child_roles_' . $row_count]['fieldset']['ercd_' . $reference_direction . '_roles_' . $type . '__' . $bundle . '__' . $reference_entity['type'] . '__' . $reference_entity['bundle']] = array(
                  '#type' => 'checkboxes',
                  '#options' => $user_roles,
                  '#default_value' => variable_get('ercd_' . $reference_direction . '_roles_' . $type . '__' . $bundle . '__' . $reference_entity['type'] . '__' . $reference_entity['bundle'], array()),
                  '#attributes' => array('class' => array('ercd-trigger ercd-setting')),
                );
              }
            }

            $wrapper_count += 1;
          }

          $row_count += 1;
        }
      }
    }
  }
}
