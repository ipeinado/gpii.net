<?php
/**
 * @file
 * openmarketplace_order_processing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openmarketplace_order_processing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'individual_payment_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'payment';
  $view->human_name = 'Individual Payment View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Individual Payment View';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'token';
  /* Field: Payment: Context */
  $handler->display->display_options['fields']['context']['id'] = 'context';
  $handler->display->display_options['fields']['context']['table'] = 'payment';
  $handler->display->display_options['fields']['context']['field'] = 'context';
  /* Field: Payment: Rendered Payment */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_payment';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'token';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Payment: Finish callback */
  $handler->display->display_options['fields']['finish_callback']['id'] = 'finish_callback';
  $handler->display->display_options['fields']['finish_callback']['table'] = 'payment';
  $handler->display->display_options['fields']['finish_callback']['field'] = 'finish_callback';
  /* Contextual filter: Payment: Payment ID */
  $handler->display->display_options['arguments']['pid']['id'] = 'pid';
  $handler->display->display_options['arguments']['pid']['table'] = 'payment';
  $handler->display->display_options['arguments']['pid']['field'] = 'pid';
  $handler->display->display_options['arguments']['pid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['pid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['pid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['pid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['pid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['individual_payment_view'] = $view;

  return $export;
}
