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

  // Exported role: رائد.
  $roles['رائد'] = array(
    'name' => 'رائد',
    'weight' => 5,
  );

  // Exported role: مدرب.
  $roles['مدرب'] = array(
    'name' => 'مدرب',
    'weight' => 3,
  );

  // Exported role: مدير مستخدمين.
  $roles['مدير مستخدمين'] = array(
    'name' => 'مدير مستخدمين',
    'weight' => 6,
  );

  // Exported role: مشارك.
  $roles['مشارك'] = array(
    'name' => 'مشارك',
    'weight' => 4,
  );

  return $roles;
}
