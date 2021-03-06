<?php
/**
 * @file
 * content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function content_types_taxonomy_default_vocabularies() {
  return array(
    'location_description' => array(
      'name' => 'أوصاف الأماكن',
      'machine_name' => 'location_description',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'locations' => array(
      'name' => 'أماكن',
      'machine_name' => 'locations',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'participant_groups' => array(
      'name' => 'مجموعات المشاركين',
      'machine_name' => 'participant_groups',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
