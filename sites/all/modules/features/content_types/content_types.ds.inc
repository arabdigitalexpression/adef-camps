<?php
/**
 * @file
 * content_types.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function content_types_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'color';
  $ds_view_mode->label = 'لون';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['color'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'icon';
  $ds_view_mode->label = 'ايقونة';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['icon'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'schedule_cell';
  $ds_view_mode->label = 'خانة جدول';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['schedule_cell'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'text';
  $ds_view_mode->label = 'اسم';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['text'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'tooltip';
  $ds_view_mode->label = 'خانة معلومات اضافية';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['tooltip'] = $ds_view_mode;

  return $export;
}
