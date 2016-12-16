<?php
/**
 * @file
 * gpii_ds_challenges.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gpii_ds_challenges_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function gpii_ds_challenges_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function gpii_ds_challenges_node_info() {
  $items = array(
    'challenge' => array(
      'name' => t('Challenge'),
      'base' => 'node_content',
      'description' => t('<i>Challenges</i> are tasks and endeavors that aim to improve the accessibility of ICT systems. <i>Challenges</i> can have prizes associated with them. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
