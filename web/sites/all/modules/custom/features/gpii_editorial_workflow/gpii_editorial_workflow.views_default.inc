<?php
/**
 * @file
 * gpii_editorial_workflow.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function gpii_editorial_workflow_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'node_flag_done';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Node Flag Done';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Node Flag Progress';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: photo_reviewed */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'photo_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Photos';
  $handler->display->display_options['fields']['ops']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = 'Description';
  $handler->display->display_options['fields']['ops_1']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ops_1']['link_type'] = 'toggle';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Photos Done */
  $handler = $view->new_display('block', 'Photos Done', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: photo_complete */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'photo_complete';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: description_complete */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'description_complete';
  $handler->display->display_options['relationships']['flag_content_rel_1']['user_scope'] = 'any';
  /* Relationship: Flags: alt_title_complete */
  $handler->display->display_options['relationships']['flag_content_rel_2']['id'] = 'flag_content_rel_2';
  $handler->display->display_options['relationships']['flag_content_rel_2']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_2']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_2']['label'] = 'flag_alt-title_done';
  $handler->display->display_options['relationships']['flag_content_rel_2']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_2']['flag'] = 'alt_title_complete';
  $handler->display->display_options['relationships']['flag_content_rel_2']['user_scope'] = 'any';
  /* Relationship: Flags: mfgr_complete */
  $handler->display->display_options['relationships']['flag_content_rel_3']['id'] = 'flag_content_rel_3';
  $handler->display->display_options['relationships']['flag_content_rel_3']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_3']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_3']['label'] = 'flag_mjgr_done';
  $handler->display->display_options['relationships']['flag_content_rel_3']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_3']['flag'] = 'mfgr_complete';
  $handler->display->display_options['relationships']['flag_content_rel_3']['user_scope'] = 'any';
  /* Relationship: Flags: taxonomy_complete */
  $handler->display->display_options['relationships']['flag_content_rel_4']['id'] = 'flag_content_rel_4';
  $handler->display->display_options['relationships']['flag_content_rel_4']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_4']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_4']['label'] = 'flag_tagging_done';
  $handler->display->display_options['relationships']['flag_content_rel_4']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_4']['flag'] = 'taxonomy_complete';
  $handler->display->display_options['relationships']['flag_content_rel_4']['user_scope'] = 'any';
  /* Relationship: Flags: wheretobuy_complete */
  $handler->display->display_options['relationships']['flag_content_rel_5']['id'] = 'flag_content_rel_5';
  $handler->display->display_options['relationships']['flag_content_rel_5']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_5']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_5']['label'] = 'flag_where_buy_done';
  $handler->display->display_options['relationships']['flag_content_rel_5']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_5']['flag'] = 'wheretobuy_complete';
  $handler->display->display_options['relationships']['flag_content_rel_5']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Photos';
  $handler->display->display_options['fields']['ops']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_2']['id'] = 'ops_2';
  $handler->display->display_options['fields']['ops_2']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_2']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_2']['relationship'] = 'flag_content_rel_2';
  $handler->display->display_options['fields']['ops_2']['label'] = 'Alt & Title';
  $handler->display->display_options['fields']['ops_2']['element_label_type'] = 'strong';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = 'Description';
  $handler->display->display_options['fields']['ops_1']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ops_1']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_3']['id'] = 'ops_3';
  $handler->display->display_options['fields']['ops_3']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_3']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_3']['relationship'] = 'flag_content_rel_3';
  $handler->display->display_options['fields']['ops_3']['label'] = 'Manufacturer Info';
  $handler->display->display_options['fields']['ops_3']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ops_3']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_4']['id'] = 'ops_4';
  $handler->display->display_options['fields']['ops_4']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_4']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_4']['relationship'] = 'flag_content_rel_4';
  $handler->display->display_options['fields']['ops_4']['label'] = 'Tagging';
  $handler->display->display_options['fields']['ops_4']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ops_4']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_5']['id'] = 'ops_5';
  $handler->display->display_options['fields']['ops_5']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_5']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_5']['relationship'] = 'flag_content_rel_5';
  $handler->display->display_options['fields']['ops_5']['label'] = 'Where to Buy';
  $handler->display->display_options['fields']['ops_5']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['ops_5']['link_type'] = 'toggle';

  /* Display: Photos Reviewed */
  $handler = $view->new_display('block', 'Photos Reviewed', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: photo_reviewed */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'photo_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: description_reviewed */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'description_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'description_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_1']['user_scope'] = 'any';
  /* Relationship: Flags: alt_title_reviewed */
  $handler->display->display_options['relationships']['flag_content_rel_2']['id'] = 'flag_content_rel_2';
  $handler->display->display_options['relationships']['flag_content_rel_2']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_2']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_2']['label'] = 'flag_alt-title-reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_2']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_2']['flag'] = 'alt_title_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_2']['user_scope'] = 'any';
  /* Relationship: Flags: mfgr_reviewed */
  $handler->display->display_options['relationships']['flag_content_rel_3']['id'] = 'flag_content_rel_3';
  $handler->display->display_options['relationships']['flag_content_rel_3']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_3']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_3']['label'] = 'flag_mfgr_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_3']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_3']['flag'] = 'mfgr_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_3']['user_scope'] = 'any';
  /* Relationship: Flags: taxonomy_reviewed */
  $handler->display->display_options['relationships']['flag_content_rel_4']['id'] = 'flag_content_rel_4';
  $handler->display->display_options['relationships']['flag_content_rel_4']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_4']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_4']['label'] = 'flag_tagging_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_4']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_4']['flag'] = 'taxonomy_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_4']['user_scope'] = 'any';
  /* Relationship: Flags: wheretobuy_reviewed */
  $handler->display->display_options['relationships']['flag_content_rel_5']['id'] = 'flag_content_rel_5';
  $handler->display->display_options['relationships']['flag_content_rel_5']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_5']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_5']['label'] = 'flag_where_buy_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_5']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_5']['flag'] = 'wheretobuy_reviewed';
  $handler->display->display_options['relationships']['flag_content_rel_5']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_2']['id'] = 'ops_2';
  $handler->display->display_options['fields']['ops_2']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_2']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_2']['relationship'] = 'flag_content_rel_2';
  $handler->display->display_options['fields']['ops_2']['label'] = '';
  $handler->display->display_options['fields']['ops_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops_2']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = '';
  $handler->display->display_options['fields']['ops_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops_1']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_3']['id'] = 'ops_3';
  $handler->display->display_options['fields']['ops_3']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_3']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_3']['relationship'] = 'flag_content_rel_3';
  $handler->display->display_options['fields']['ops_3']['label'] = '';
  $handler->display->display_options['fields']['ops_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops_3']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_4']['id'] = 'ops_4';
  $handler->display->display_options['fields']['ops_4']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_4']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_4']['relationship'] = 'flag_content_rel_4';
  $handler->display->display_options['fields']['ops_4']['label'] = '';
  $handler->display->display_options['fields']['ops_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops_4']['link_type'] = 'toggle';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_5']['id'] = 'ops_5';
  $handler->display->display_options['fields']['ops_5']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops_5']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_5']['relationship'] = 'flag_content_rel_5';
  $handler->display->display_options['fields']['ops_5']['label'] = '';
  $handler->display->display_options['fields']['ops_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops_5']['link_type'] = 'toggle';
  $export['node_flag_done'] = $view;

  $view = new view();
  $view->name = 'node_flag_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Node Flag Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editorial Progress';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'view' => 'view',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'view' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Done';
  $handler->display->display_options['fields']['view']['view'] = 'node_flag_done';
  $handler->display->display_options['fields']['view']['display'] = 'block_2';
  $handler->display->display_options['fields']['view']['arguments'] = '!1';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['label'] = 'Reviewed';
  $handler->display->display_options['fields']['view_1']['view'] = 'node_flag_done';
  $handler->display->display_options['fields']['view_1']['display'] = 'block_1';
  $handler->display->display_options['fields']['view_1']['arguments'] = '!1';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Done */
  $handler = $view->new_display('block', 'Done', 'block');
  $export['node_flag_report'] = $view;

  return $export;
}
