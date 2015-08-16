<?php
/**
 * @file
 * adef_camps_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function adef_camps_roles_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
    'machine_name' => 'administrator',
  );

  // Exported role: رائد.
  $roles['رائد'] = array(
    'name' => 'رائد',
    'weight' => 5,
    'machine_name' => 'supervisor',
  );

  // Exported role: مدرب.
  $roles['مدرب'] = array(
    'name' => 'مدرب',
    'weight' => 3,
    'machine_name' => 'trainer',
  );

  // Exported role: مدير مستخدمين.
  $roles['مدير مستخدمين'] = array(
    'name' => 'مدير مستخدمين',
    'weight' => 6,
    'machine_name' => 'user_manager',
  );

  // Exported role: مشارك.
  $roles['مشارك'] = array(
    'name' => 'مشارك',
    'weight' => 4,
    'machine_name' => 'participant',
  );

  return $roles;
}
