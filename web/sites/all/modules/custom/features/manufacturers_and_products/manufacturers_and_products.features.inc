<?php
/**
 * @file
 * manufacturers_and_products.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function manufacturers_and_products_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function manufacturers_and_products_node_info() {
  $items = array(
    'manufacturer' => array(
      'name' => t('Manufacturer'),
      'base' => 'node_content',
      'description' => t('Temporary Content type to store manufacturer contact information. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('Products imported from the GPII Unified Listing.'),
      'has_title' => '1',
      'title_label' => t('Product Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
