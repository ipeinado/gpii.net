<?php
/**
 * @file
 * gpii_ds_challenges.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gpii_ds_challenges_ctools_plugin_api($module = NULL, $api = NULL) {
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
function gpii_ds_challenges_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function gpii_ds_challenges_flag_default_flags() {
  $flags = array();
  // Exported flag: "Upvote challenge".
  $flags['upvote_challenge'] = array(
    'entity_type' => 'node',
    'title' => 'Upvote challenge',
    'global' => 0,
    'types' => array(
      0 => 'challenge',
    ),
    'flag_short' => 'Upvote <span class="flag-count">[node:flag-upvote-challenge-count]</span>',
    'flag_long' => 'Vote this challenge',
    'flag_message' => 'Thank you for voting for this challenge! ',
    'unflag_short' => 'Downvote <span class="flag-count">[node:flag-upvote-challenge-count]</span>',
    'unflag_long' => 'Remove your vote for this challenge',
    'unflag_message' => 'Sad to see you are not supporting this challenge any more!',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'print' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'gpii_ds_challenges',
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
