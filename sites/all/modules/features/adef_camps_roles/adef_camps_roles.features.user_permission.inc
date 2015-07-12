<?php
/**
 * @file
 * adef_camps_roles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function adef_camps_roles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add achievements'.
  $permissions['add achievements'] = array(
    'name' => 'add achievements',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'adef_camps',
  );

  // Exported permission: 'add incidents'.
  $permissions['add incidents'] = array(
    'name' => 'add incidents',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'adef_camps',
  );

  // Exported permission: 'add terms in 1'.
  $permissions['add terms in 1'] = array(
    'name' => 'add terms in 1',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in 2'.
  $permissions['add terms in 2'] = array(
    'name' => 'add terms in 2',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in 3'.
  $permissions['add terms in 3'] = array(
    'name' => 'add terms in 3',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in 4'.
  $permissions['add terms in 4'] = array(
    'name' => 'add terms in 4',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in 5'.
  $permissions['add terms in 5'] = array(
    'name' => 'add terms in 5',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer entity view modes'.
  $permissions['administer entity view modes'] = array(
    'name' => 'administer entity view modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_view_mode',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer settings'.
  $permissions['administer settings'] = array(
    'name' => 'administer settings',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'adef_camps',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer tipsy'.
  $permissions['administer tipsy'] = array(
    'name' => 'administer tipsy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'tipsy',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bulk generate spacetime'.
  $permissions['bulk generate spacetime'] = array(
    'name' => 'bulk generate spacetime',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'adef_camps',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear bagdes feeds'.
  $permissions['clear bagdes feeds'] = array(
    'name' => 'clear bagdes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear node feeds'.
  $permissions['clear node feeds'] = array(
    'name' => 'clear node feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear participants feeds'.
  $permissions['clear participants feeds'] = array(
    'name' => 'clear participants feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear schedule feeds'.
  $permissions['clear schedule feeds'] = array(
    'name' => 'clear schedule feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear user feeds'.
  $permissions['clear user feeds'] = array(
    'name' => 'clear user feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear workshops feeds'.
  $permissions['clear workshops feeds'] = array(
    'name' => 'clear workshops feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create field_date_time'.
  $permissions['create field_date_time'] = array(
    'name' => 'create field_date_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_location'.
  $permissions['create field_location'] = array(
    'name' => 'create field_location',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_participant_notes'.
  $permissions['create field_participant_notes'] = array(
    'name' => 'create field_participant_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'مدرب' => 'مدرب',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_participant_phone'.
  $permissions['create field_participant_phone'] = array(
    'name' => 'create field_participant_phone',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_participants'.
  $permissions['create field_participants'] = array(
    'name' => 'create field_participants',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_related_particpant_profile'.
  $permissions['create field_related_particpant_profile'] = array(
    'name' => 'create field_related_particpant_profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create participant content'.
  $permissions['create participant content'] = array(
    'name' => 'create participant content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create register_entry content'.
  $permissions['create register_entry content'] = array(
    'name' => 'create register_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create session content'.
  $permissions['create session content'] = array(
    'name' => 'create session content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create timespace content'.
  $permissions['create timespace content'] = array(
    'name' => 'create timespace content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create workshop content'.
  $permissions['create workshop content'] = array(
    'name' => 'create workshop content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any participant content'.
  $permissions['delete any participant content'] = array(
    'name' => 'delete any participant content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any register_entry content'.
  $permissions['delete any register_entry content'] = array(
    'name' => 'delete any register_entry content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any session content'.
  $permissions['delete any session content'] = array(
    'name' => 'delete any session content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any timespace content'.
  $permissions['delete any timespace content'] = array(
    'name' => 'delete any timespace content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any workshop content'.
  $permissions['delete any workshop content'] = array(
    'name' => 'delete any workshop content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own participant content'.
  $permissions['delete own participant content'] = array(
    'name' => 'delete own participant content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own register_entry content'.
  $permissions['delete own register_entry content'] = array(
    'name' => 'delete own register_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own session content'.
  $permissions['delete own session content'] = array(
    'name' => 'delete own session content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own timespace content'.
  $permissions['delete own timespace content'] = array(
    'name' => 'delete own timespace content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own workshop content'.
  $permissions['delete own workshop content'] = array(
    'name' => 'delete own workshop content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in educational_goals'.
  $permissions['delete terms in educational_goals'] = array(
    'name' => 'delete terms in educational_goals',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in fields'.
  $permissions['delete terms in fields'] = array(
    'name' => 'delete terms in fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in location_description'.
  $permissions['delete terms in location_description'] = array(
    'name' => 'delete terms in location_description',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in locations'.
  $permissions['delete terms in locations'] = array(
    'name' => 'delete terms in locations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in participant_groups'.
  $permissions['delete terms in participant_groups'] = array(
    'name' => 'delete terms in participant_groups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any participant content'.
  $permissions['edit any participant content'] = array(
    'name' => 'edit any participant content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any register_entry content'.
  $permissions['edit any register_entry content'] = array(
    'name' => 'edit any register_entry content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any session content'.
  $permissions['edit any session content'] = array(
    'name' => 'edit any session content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any timespace content'.
  $permissions['edit any timespace content'] = array(
    'name' => 'edit any timespace content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any workshop content'.
  $permissions['edit any workshop content'] = array(
    'name' => 'edit any workshop content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_date_time'.
  $permissions['edit field_date_time'] = array(
    'name' => 'edit field_date_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_location'.
  $permissions['edit field_location'] = array(
    'name' => 'edit field_location',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_participant_notes'.
  $permissions['edit field_participant_notes'] = array(
    'name' => 'edit field_participant_notes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_participant_phone'.
  $permissions['edit field_participant_phone'] = array(
    'name' => 'edit field_participant_phone',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_participants'.
  $permissions['edit field_participants'] = array(
    'name' => 'edit field_participants',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_related_particpant_profile'.
  $permissions['edit field_related_particpant_profile'] = array(
    'name' => 'edit field_related_particpant_profile',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_date_time'.
  $permissions['edit own field_date_time'] = array(
    'name' => 'edit own field_date_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_location'.
  $permissions['edit own field_location'] = array(
    'name' => 'edit own field_location',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_participant_notes'.
  $permissions['edit own field_participant_notes'] = array(
    'name' => 'edit own field_participant_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'مدرب' => 'مدرب',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_participant_phone'.
  $permissions['edit own field_participant_phone'] = array(
    'name' => 'edit own field_participant_phone',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_participants'.
  $permissions['edit own field_participants'] = array(
    'name' => 'edit own field_participants',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_related_particpant_profile'.
  $permissions['edit own field_related_particpant_profile'] = array(
    'name' => 'edit own field_related_particpant_profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own participant content'.
  $permissions['edit own participant content'] = array(
    'name' => 'edit own participant content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own register_entry content'.
  $permissions['edit own register_entry content'] = array(
    'name' => 'edit own register_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own session content'.
  $permissions['edit own session content'] = array(
    'name' => 'edit own session content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own timespace content'.
  $permissions['edit own timespace content'] = array(
    'name' => 'edit own timespace content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own workshop content'.
  $permissions['edit own workshop content'] = array(
    'name' => 'edit own workshop content',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in educational_goals'.
  $permissions['edit terms in educational_goals'] = array(
    'name' => 'edit terms in educational_goals',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in fields'.
  $permissions['edit terms in fields'] = array(
    'name' => 'edit terms in fields',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in location_description'.
  $permissions['edit terms in location_description'] = array(
    'name' => 'edit terms in location_description',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in locations'.
  $permissions['edit terms in locations'] = array(
    'name' => 'edit terms in locations',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in participant_groups'.
  $permissions['edit terms in participant_groups'] = array(
    'name' => 'edit terms in participant_groups',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import bagdes feeds'.
  $permissions['import bagdes feeds'] = array(
    'name' => 'import bagdes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import node feeds'.
  $permissions['import node feeds'] = array(
    'name' => 'import node feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import participants feeds'.
  $permissions['import participants feeds'] = array(
    'name' => 'import participants feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import schedule feeds'.
  $permissions['import schedule feeds'] = array(
    'name' => 'import schedule feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import user feeds'.
  $permissions['import user feeds'] = array(
    'name' => 'import user feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import workshops feeds'.
  $permissions['import workshops feeds'] = array(
    'name' => 'import workshops feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'register participants'.
  $permissions['register participants'] = array(
    'name' => 'register participants',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'adef_camps',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'session attendance'.
  $permissions['session attendance'] = array(
    'name' => 'session attendance',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'adef_camps',
  );

  // Exported permission: 'tamper bagdes'.
  $permissions['tamper bagdes'] = array(
    'name' => 'tamper bagdes',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper node'.
  $permissions['tamper node'] = array(
    'name' => 'tamper node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper participants'.
  $permissions['tamper participants'] = array(
    'name' => 'tamper participants',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper schedule'.
  $permissions['tamper schedule'] = array(
    'name' => 'tamper schedule',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper user'.
  $permissions['tamper user'] = array(
    'name' => 'tamper user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper workshops'.
  $permissions['tamper workshops'] = array(
    'name' => 'tamper workshops',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'unlock bagdes feeds'.
  $permissions['unlock bagdes feeds'] = array(
    'name' => 'unlock bagdes feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock node feeds'.
  $permissions['unlock node feeds'] = array(
    'name' => 'unlock node feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock participants feeds'.
  $permissions['unlock participants feeds'] = array(
    'name' => 'unlock participants feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock schedule feeds'.
  $permissions['unlock schedule feeds'] = array(
    'name' => 'unlock schedule feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock user feeds'.
  $permissions['unlock user feeds'] = array(
    'name' => 'unlock user feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock workshops feeds'.
  $permissions['unlock workshops feeds'] = array(
    'name' => 'unlock workshops feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view field_date_time'.
  $permissions['view field_date_time'] = array(
    'name' => 'view field_date_time',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_location'.
  $permissions['view field_location'] = array(
    'name' => 'view field_location',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_participant_notes'.
  $permissions['view field_participant_notes'] = array(
    'name' => 'view field_participant_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_participant_phone'.
  $permissions['view field_participant_phone'] = array(
    'name' => 'view field_participant_phone',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
      'مدير مستخدمين' => 'مدير مستخدمين',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_participants'.
  $permissions['view field_participants'] = array(
    'name' => 'view field_participants',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_related_particpant_profile'.
  $permissions['view field_related_particpant_profile'] = array(
    'name' => 'view field_related_particpant_profile',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_date_time'.
  $permissions['view own field_date_time'] = array(
    'name' => 'view own field_date_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_location'.
  $permissions['view own field_location'] = array(
    'name' => 'view own field_location',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_participant_notes'.
  $permissions['view own field_participant_notes'] = array(
    'name' => 'view own field_participant_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_participant_phone'.
  $permissions['view own field_participant_phone'] = array(
    'name' => 'view own field_participant_phone',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_participants'.
  $permissions['view own field_participants'] = array(
    'name' => 'view own field_participants',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_related_particpant_profile'.
  $permissions['view own field_related_particpant_profile'] = array(
    'name' => 'view own field_related_particpant_profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'رائد' => 'رائد',
      'مدرب' => 'مدرب',
    ),
    'module' => 'system',
  );

  return $permissions;
}
