<?php
/**
 * @file
 * staging_server_settings_and_config.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function staging_server_settings_and_config_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-gpii-sites-staging-'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-gpii-sites-staging-',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'devspace' => array(
        'region' => '',
        'status' => 1,
        'theme' => 'devspace',
        'weight' => -14,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'GPII Sites',
    'visibility' => 0,
  );

  return $export;
}
