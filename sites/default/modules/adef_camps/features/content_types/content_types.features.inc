<?php
/**
 * @file
 * content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function content_types_image_default_styles() {
  $styles = array();

  // Exported image style: icon_large.
  $styles['icon_large'] = array(
    'label' => 'icon_large',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 128,
          'height' => 128,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: icon_medium.
  $styles['icon_medium'] = array(
    'label' => 'icon_medium',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 64,
          'height' => 64,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: icon_small.
  $styles['icon_small'] = array(
    'label' => 'icon_small',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 16,
          'height' => 16,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_header.
  $styles['profile_header'] = array(
    'label' => 'profile_header',
    'effects' => array(
      13 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 1200,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => -10,
      ),
      12 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 385,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: profile_thumb_large.
  $styles['profile_thumb_large'] = array(
    'label' => 'profile_thumb_large',
    'effects' => array(
      14 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: profile_thumb_small.
  $styles['profile_thumb_small'] = array(
    'label' => 'profile_thumb_small',
    'effects' => array(
      15 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function content_types_node_info() {
  $items = array(
    'participant' => array(
      'name' => t('مشارك'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('الاسم الكامل'),
      'help' => '',
    ),
    'register_entry' => array(
      'name' => t('قيد سجل المشاركين'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'session' => array(
      'name' => t('جلسة'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('عنوان'),
      'help' => t('اترك العنوان خاليا لينشأ تلقائيا'),
    ),
    'timespace' => array(
      'name' => t('زمكان'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('عنوان'),
      'help' => '',
    ),
    'workshop' => array(
      'name' => t('ورشة'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('اسم'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
