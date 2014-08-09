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
