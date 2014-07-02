<?php
/**
 * @file
 * adefcamps_taxonomy.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function adefcamps_taxonomy_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-educational_goals-field_icon'
  $field_instances['taxonomy_term-educational_goals-field_icon'] = array(
    'bundle' => 'educational_goals',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'icon' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'icon_small',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_icon',
    'label' => 'الايقونة',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/icons',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '32x32',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-fields-field_color'
  $field_instances['taxonomy_term-fields-field_color'] = array(
    'bundle' => 'fields',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'colorfield',
        'settings' => array(
          'height' => 20,
          'width' => 20,
        ),
        'type' => 'colorfield_color_swatch',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_color',
    'label' => 'اللون',
    'required' => 0,
    'settings' => array(
      'colorfield_colorpicker_type' => 'farbtastic',
      'colorfield_enable_colorpicker' => TRUE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'colorfield',
      'settings' => array(
        'colorfield_colorpicker_type' => 'farbtastic',
        'colorfield_enable_colorpicker' => TRUE,
        'colorfield_options' => array(
          'colorfield_colorpicker_type' => 'farbtastic',
          'colorfield_enable_colorpicker' => 1,
        ),
      ),
      'type' => 'colorfield_unified_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-locations-field_location_description'
  $field_instances['taxonomy_term-locations-field_location_description'] = array(
    'bundle' => 'locations',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_location_description',
    'label' => 'وصف',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('الايقونة');
  t('اللون');
  t('وصف');

  return $field_instances;
}
