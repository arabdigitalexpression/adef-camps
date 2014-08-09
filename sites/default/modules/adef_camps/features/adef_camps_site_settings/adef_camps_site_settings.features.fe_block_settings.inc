<?php
/**
 * @file
 * adef_camps_site_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function adef_camps_site_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['logintoboggan-logintoboggan_logged_in'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'logintoboggan_logged_in',
    'module' => 'logintoboggan',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'camps' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'camps',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'camps' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'camps',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
