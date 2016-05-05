<?php
/**
 * @file
 * manufacturers_and_products.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function manufacturers_and_products_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'products-features-explode';
  $feeds_tamper->importer = 'products';
  $feeds_tamper->source = 'Features';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '%n',
    'limit' => '',
    'real_separator' => '
',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['products-features-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'products-product_categories-explode';
  $feeds_tamper->importer = 'products';
  $feeds_tamper->source = 'Product Categories';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '%n',
    'limit' => '',
    'real_separator' => '
',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['products-product_categories-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unified_listing_products-status-find_replace';
  $feeds_tamper->importer = 'unified_listing_products';
  $feeds_tamper->source = 'status';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'new',
    'replace' => '0',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'New Status';
  $export['unified_listing_products-status-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unified_listing_products-status-unified_listing_status_1';
  $feeds_tamper->importer = 'unified_listing_products';
  $feeds_tamper->source = 'status';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'active',
    'replace' => '1',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Active Status';
  $export['unified_listing_products-status-unified_listing_status_1'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unified_listing_products-status-unified_listing_status_2';
  $feeds_tamper->importer = 'unified_listing_products';
  $feeds_tamper->source = 'status';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'discontinued',
    'replace' => '2',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Discontinued Status';
  $export['unified_listing_products-status-unified_listing_status_2'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'unified_listing_products-status-unified_listing_status_3';
  $feeds_tamper->importer = 'unified_listing_products';
  $feeds_tamper->source = 'status';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'deleted',
    'replace' => '3',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Deleted Status';
  $export['unified_listing_products-status-unified_listing_status_3'] = $feeds_tamper;

  return $export;
}
