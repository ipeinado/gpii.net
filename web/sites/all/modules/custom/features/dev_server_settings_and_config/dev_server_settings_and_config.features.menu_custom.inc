<?php
/**
 * @file
 * dev_server_settings_and_config.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dev_server_settings_and_config_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-gpii-sites-dev-.
  $menus['menu-gpii-sites-dev-'] = array(
    'menu_name' => 'menu-gpii-sites-dev-',
    'title' => 'GPII Sites (Staging)',
    'description' => 'Menu for switching between GPII sites on the development server. ',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('GPII Sites (Development)');
  t('Menu for switching between GPII sites on the development server. ');

  return $menus;
}
