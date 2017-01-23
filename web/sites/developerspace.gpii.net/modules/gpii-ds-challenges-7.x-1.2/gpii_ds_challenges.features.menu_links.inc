<?php
/**
 * @file
 * gpii_ds_challenges.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function gpii_ds_challenges_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_challenges:challenges.
  $menu_links['main-menu_challenges:challenges'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'challenges',
    'router_path' => 'challenges',
    'link_title' => 'Challenges',
    'options' => array(
      'attributes' => array(
        'title' => 'Prove your skills as a developer and earn some badges',
      ),
      'identifier' => 'main-menu_challenges:challenges',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Challenges');

  return $menu_links;
}
