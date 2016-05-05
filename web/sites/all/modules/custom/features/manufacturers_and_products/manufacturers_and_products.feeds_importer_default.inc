<?php
/**
 * @file
 * manufacturers_and_products.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function manufacturers_and_products_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'manufacturers';
  $feeds_importer->config = array(
    'name' => 'Manufacturers',
    'description' => 'Import manufacturer data from Misericordia DB',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Manufacturer_ID',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Manufacturer_ID',
            'target' => 'field_origin_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Manufacturer_Name',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Address1',
            'target' => 'field_address:thoroughfare',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Address2',
            'target' => 'field_address:premise',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'City',
            'target' => 'field_address:locality',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'State',
            'target' => 'field_address:administrative_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Mailcode',
            'target' => 'field_address:postal_code',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Country',
            'target' => 'field_address:country',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Phone1',
            'target' => 'field_phone_1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Phone2',
            'target' => 'field_phone_2',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Fax',
            'target' => 'field_fax',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'URL',
            'target' => 'field_url:url',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'manufacturer',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['manufacturers'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'products';
  $feeds_importer->config = array(
    'name' => 'Products',
    'description' => 'Products imported from the Misericordia DB',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '115',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Product ID',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'Product ID',
            'target' => 'field_origin_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Product Name',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Cost',
            'target' => 'field_cost',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Manufacturer Name',
            'target' => 'field_manufacturer_reference:label',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Product Categories',
            'target' => 'field_product_categories',
            'term_search' => '0',
            'autocreate' => 0,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Product Categories',
            'target' => 'field_needs',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Features',
            'target' => 'field_features',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Product Description',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Image File',
            'target' => 'field_product_image:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Image Alt Text',
            'target' => 'field_product_image:alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Model',
            'target' => 'field_model',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Product Type',
            'target' => 'field_product_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'License Type',
            'target' => 'field_license',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'product',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['products'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'unified_listing_products';
  $feeds_importer->config = array(
    'name' => 'Unified Listing Products',
    'description' => 'Imports products from the unified listing API. ',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'http',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'context' => array(
          'value' => '$.records.*',
        ),
        'sources' => array(
          'uid' => array(
            'name' => 'uid',
            'value' => 'uid',
            'debug' => 0,
            'weight' => '1',
          ),
          'name' => array(
            'name' => 'name',
            'value' => 'name',
            'debug' => 0,
            'weight' => '2',
          ),
          'source' => array(
            'name' => 'source',
            'value' => 'source',
            'debug' => 0,
            'weight' => '3',
          ),
          'status' => array(
            'name' => 'status',
            'value' => 'status',
            'debug' => 0,
            'weight' => '4',
          ),
          'description' => array(
            'name' => 'description',
            'value' => 'description',
            'debug' => 0,
            'weight' => '5',
          ),
          'mfg_name' => array(
            'name' => 'mfg_name',
            'value' => 'manufacturer.name',
            'debug' => 0,
            'weight' => '6',
          ),
        ),
        'display_errors' => 1,
        'debug_mode' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'uid',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'uid',
            'target' => 'field_uid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'source',
            'target' => 'field_source',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'status',
            'target' => 'field_status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'description',
            'target' => 'body',
            'format' => 'filtered_html',
          ),
          6 => array(
            'source' => 'mfg_name',
            'target' => 'field_mfgr_name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'product',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['unified_listing_products'] = $feeds_importer;

  return $export;
}
