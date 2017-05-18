<?php
/**
 * @file
 * open_marketplace.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function open_marketplace_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openmarketplace';
  $context->description = 'OpenMarketplace Context';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'open_marketplace_product' => 'open_marketplace_product',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-openmarketplace' => array(
          'module' => 'bean',
          'delta' => 'openmarketplace',
          'region' => 'hero',
          'weight' => '-10',
        ),
      ),
    ),
    'debug' => array(
      'debug' => 1,
    ),
    'region' => array(
      'bootstrap' => array(
        'disable' => array(
          'navigation' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'devspace' => array(
        'disable' => array(
          'navigation' => 0,
          'header' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content' => 0,
          'sidebar_first' => 0,
          'sidebar_second' => 0,
          'footer' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'gpii_sai' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'topbar_first' => 0,
          'topbar_second' => 0,
          'header_first' => 0,
          'header_second' => 0,
          'menu_first' => 0,
          'menu_second' => 0,
          'hero' => 0,
          'sidebar_second' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content_preface' => 0,
          'content' => 0,
          'content_postscript' => 0,
          'secondary_first' => 0,
          'secondary_second' => 0,
          'secondary_third' => 0,
          'secondary_fourth' => 0,
          'tertiary_first' => 0,
          'tertiary_second' => 0,
          'tertiary_third' => 0,
          'tertiary_fourth' => 0,
          'footer_first' => 0,
          'footer_second' => 0,
          'footer_third' => 0,
          'footer_fourth' => 0,
          'footer_fifth' => 0,
          'fine_print_first' => 0,
          'fine_print_second' => 0,
          'fine_print_third' => 0,
          'fine_print_fourth' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
      'seven' => array(
        'disable' => array(
          'content' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
          'sidebar_first' => 0,
          'dashboard_main' => 0,
          'dashboard_sidebar' => 0,
          'dashboard_inactive' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenMarketplace Context');
  $export['openmarketplace'] = $context;

  return $export;
}
