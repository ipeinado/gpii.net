<?php
/**
 * @file
 * gpii_ds_references.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gpii_ds_references_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function gpii_ds_references_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function gpii_ds_references_flag_default_flags() {
  $flags = array();
  // Exported flag: "Bookmarks".
  $flags['bookmarks'] = array(
    'entity_type' => 'node',
    'title' => 'Bookmarks',
    'global' => 0,
    'types' => array(
      0 => 'article',
    ),
    'flag_short' => 'Bookmark this',
    'flag_long' => 'Add this post to your bookmarks',
    'flag_message' => 'This post has been added to your bookmarks',
    'unflag_short' => 'Unbookmark this',
    'unflag_long' => 'Remove this post from your bookmarks',
    'unflag_message' => 'This post has been removed from your bookmarks',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 1,
      'teaser' => 1,
    ),
    'show_as_field' => FALSE,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'gpii_ds_references',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function gpii_ds_references_node_info() {
  $items = array(
    'reference' => array(
      'name' => t('Reference'),
      'base' => 'node_content',
      'description' => t('Articles in conference proceedings, articles in journals and book chapters in the field of accessibility and universal design.'),
      'has_title' => '1',
      'title_label' => t('Title of the reference'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
