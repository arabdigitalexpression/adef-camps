<?php
/**
 * @file
 * adef_camps_site_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function adef_camps_site_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_--:node/add
  $menu_links['main-menu_--:node/add'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'اضف محتوى يدويا',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_--:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_-:camps/schedule/print
  $menu_links['main-menu_-:camps/schedule/print'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'camps/schedule/print',
    'router_path' => 'camps/schedule/print',
    'link_title' => 'طباعة الجدول',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_-:camps/schedule/print',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_-:daily
  $menu_links['main-menu_-:daily'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'daily',
    'router_path' => 'daily',
    'link_title' => 'الجدول اليومي',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_-:daily',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_:<front>
  $menu_links['main-menu_:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'الرئيسية',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_:admin/structure/taxonomy
  $menu_links['main-menu_:admin/structure/taxonomy'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/structure/taxonomy',
    'router_path' => 'admin/structure/taxonomy',
    'link_title' => 'تصنيفات',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_:admin/structure/taxonomy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_:participants
  $menu_links['main-menu_:participants'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'participants',
    'router_path' => 'participants',
    'link_title' => 'المشاركون',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_:participants',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_:workshops
  $menu_links['main-menu_:workshops'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'workshops',
    'router_path' => 'workshops',
    'link_title' => 'الورش',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_:workshops',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('اضف محتوى يدويا');
  t('الجدول اليومي');
  t('الرئيسية');
  t('المشاركون');
  t('الورش');
  t('تصنيفات');
  t('طباعة الجدول');

  return $menu_links;
}
