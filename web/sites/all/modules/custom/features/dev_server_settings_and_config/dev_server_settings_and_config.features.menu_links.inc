<?php
/**
 * @file
 * dev_server_settings_and_config.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dev_server_settings_and_config_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-gpii-sites-dev-_developerspace:http://dev.developerspace.gpii.net.
  $menu_links['menu-gpii-sites-dev-_developerspace:http://dev.developerspace.gpii.net'] = array(
    'menu_name' => 'menu-gpii-sites-dev-',
    'link_path' => 'http://dev.developerspace.gpii.net',
    'router_path' => '',
    'link_title' => 'DeveloperSpace',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-gpii-sites-dev-_developerspace:http://dev.developerspace.gpii.net',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-gpii-sites-dev-_gpii:http://dev.gpii.net.
  $menu_links['menu-gpii-sites-dev-_gpii:http://dev.gpii.net'] = array(
    'menu_name' => 'menu-gpii-sites-dev-',
    'link_path' => 'http://dev.gpii.net',
    'router_path' => '',
    'link_title' => 'GPII',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-gpii-sites-dev-_gpii:http://dev.gpii.net',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-gpii-sites-dev-_unified-listing:http://dev.saa.gpii.net.
  $menu_links['menu-gpii-sites-dev-_unified-listing:http://dev.saa.gpii.net'] = array(
    'menu_name' => 'menu-gpii-sites-dev-',
    'link_path' => 'http://dev.saa.gpii.net',
    'router_path' => '',
    'link_title' => 'Unified Listing',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-gpii-sites-dev-_unified-listing:http://dev.saa.gpii.net',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('DeveloperSpace');
  t('GPII');
  t('Unified Listing');

  return $menu_links;
}
