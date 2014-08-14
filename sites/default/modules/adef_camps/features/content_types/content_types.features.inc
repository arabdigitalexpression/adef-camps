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
    'name' => 'icon_large',
    'label' => 'icon_large',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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
    'name' => 'icon_medium',
    'label' => 'icon_medium',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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
    'name' => 'icon_small',
    'label' => 'icon_small',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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
    'name' => 'profile_header',
    'label' => 'profile_header',
    'effects' => array(
      10 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 2500,
          'height' => 1300,
          'anchor' => 'center-top',
        ),
        'weight' => -10,
      ),
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1400,
          'height' => 450,
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: profile_thumb_large.
  $styles['profile_thumb_large'] = array(
    'name' => 'profile_thumb_large',
    'label' => 'profile_thumb_large',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_thumb_small.
  $styles['profile_thumb_small'] = array(
    'name' => 'profile_thumb_small',
    'label' => 'profile_thumb_small',
    'effects' => array(
      5 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
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
    'badge' => array(
      'name' => t('شارة تحفيزية'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('الاسم'),
      'help' => '',
    ),
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
