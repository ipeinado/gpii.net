<?php
/**
 * @file
 * gpii_developerspace_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function gpii_developerspace_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-home_links'] = array(
    'cache' => -1,
    'css_class' => 'col-md-24',
    'custom' => 0,
    'machine_name' => 'home_links',
    'module' => 'block',
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
        'status' => 0,
        'theme' => 'devspace',
        'weight' => 0,
      ),
      'gpii_devspace' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'gpii_devspace',
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

  $export['block-welcome_block'] = array(
    'cache' => -1,
    'css_class' => 'welcome-block',
    'custom' => 0,
    'machine_name' => 'welcome_block',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
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
        'status' => 0,
        'theme' => 'devspace',
        'weight' => 0,
      ),
      'gpii_devspace' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'gpii_devspace',
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
    'visibility' => 1,
  );

  return $export;
}
