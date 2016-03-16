<?php
/**
 * @file
 * staging_server_settings_and_config.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function staging_server_settings_and_config_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-gpii-sites-staging-.
  $menus['menu-gpii-sites-staging-'] = array(
    'menu_name' => 'menu-gpii-sites-staging-',
    'title' => 'GPII Sites (Staging)',
    'description' => 'Menu for switching between GPII sites on the staging server. ',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('GPII Sites (Staging)');
  t('Menu for switching between GPII sites on the staging server. ');

  return $menus;
}
