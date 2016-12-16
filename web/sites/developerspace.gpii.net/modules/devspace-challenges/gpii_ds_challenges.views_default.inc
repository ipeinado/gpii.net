<?php
/**
 * @file
 * gpii_ds_challenges.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gpii_ds_challenges_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'challenges';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Challenges';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Challenges';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'uid' => 'uid',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  /* Relationship: who posted the challenge */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'who posted the challenge';
  /* Field: challenge title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'challenge title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'node-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitted by';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Bounty */
  $handler->display->display_options['fields']['field_bounty']['id'] = 'field_bounty';
  $handler->display->display_options['fields']['field_bounty']['table'] = 'field_data_field_bounty';
  $handler->display->display_options['fields']['field_bounty']['field'] = 'field_bounty';
  $handler->display->display_options['fields']['field_bounty']['label'] = 'Prize';
  $handler->display->display_options['fields']['field_bounty']['element_type'] = 'strong';
  /* Field: Content: Level of complexity */
  $handler->display->display_options['fields']['field_level_of_complexity']['id'] = 'field_level_of_complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['table'] = 'field_data_field_level_of_complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['field'] = 'field_level_of_complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['label'] = 'Complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_level_of_complexity']['element_label_class'] = 'challenge-label';
  $handler->display->display_options['fields']['field_level_of_complexity']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_level_of_complexity']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: prize_explanation */
  $handler->display->display_options['fields']['field_prize_explanation']['id'] = 'field_prize_explanation';
  $handler->display->display_options['fields']['field_prize_explanation']['table'] = 'field_data_field_prize_explanation';
  $handler->display->display_options['fields']['field_prize_explanation']['field'] = 'field_prize_explanation';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'challenge' => 'challenge',
  );
  /* Filter criterion: Content: Level of complexity (field_level_of_complexity) */
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['id'] = 'field_level_of_complexity_tid';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['table'] = 'field_data_field_level_of_complexity';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['field'] = 'field_level_of_complexity_tid';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['value'] = array(
    1246 => '1246',
    1247 => '1247',
    1248 => '1248',
    1249 => '1249',
  );
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['expose']['operator_id'] = 'field_level_of_complexity_tid_op';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['expose']['label'] = 'Complexity';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['expose']['description'] = 'Select the level of complexity of the challenges';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['expose']['operator'] = 'field_level_of_complexity_tid_op';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['expose']['identifier'] = 'field_level_of_complexity_tid';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_level_of_complexity_tid']['vocabulary'] = 'challenge_difficulty';

  /* Display: Challenges Page */
  $handler = $view->new_display('page', 'Challenges Page', 'page');
  $handler->display->display_options['display_description'] = 'Page displaying all challenges';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Some of these challenges are for volunteers and others have funding or prizes associated with them. All are intended to inspire and guide people who would like to work on key issues.

The challenges are particularly good for student projects, either as individuals or as teams. All are needed and provide an opportunity to carry our academic work that will really mean something if you are successful.';
  $handler->display->display_options['header']['area']['format'] = 'markdown';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: challenge title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'challenge title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'node-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitted by';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Bounty */
  $handler->display->display_options['fields']['field_bounty']['id'] = 'field_bounty';
  $handler->display->display_options['fields']['field_bounty']['table'] = 'field_data_field_bounty';
  $handler->display->display_options['fields']['field_bounty']['field'] = 'field_bounty';
  $handler->display->display_options['fields']['field_bounty']['label'] = 'Prize';
  $handler->display->display_options['fields']['field_bounty']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_bounty']['empty'] = 'no prize';
  /* Field: Content: prize_explanation */
  $handler->display->display_options['fields']['field_prize_explanation']['id'] = 'field_prize_explanation';
  $handler->display->display_options['fields']['field_prize_explanation']['table'] = 'field_data_field_prize_explanation';
  $handler->display->display_options['fields']['field_prize_explanation']['field'] = 'field_prize_explanation';
  $handler->display->display_options['fields']['field_prize_explanation']['label'] = '';
  $handler->display->display_options['fields']['field_prize_explanation']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_prize_explanation']['element_class'] = 'prize-explanation';
  $handler->display->display_options['fields']['field_prize_explanation']['element_label_colon'] = FALSE;
  /* Field: Content: Level of complexity */
  $handler->display->display_options['fields']['field_level_of_complexity']['id'] = 'field_level_of_complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['table'] = 'field_data_field_level_of_complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['field'] = 'field_level_of_complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['label'] = 'Complexity';
  $handler->display->display_options['fields']['field_level_of_complexity']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_level_of_complexity']['element_label_class'] = 'challenge-label';
  $handler->display->display_options['fields']['field_level_of_complexity']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_level_of_complexity']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['separator'] = ' ';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'challenges';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Challenges';
  $handler->display->display_options['menu']['description'] = 'Prove your skills as a developer and earn some badges';
  $handler->display->display_options['menu']['weight'] = '-44';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['challenges'] = $view;

  return $export;
}
