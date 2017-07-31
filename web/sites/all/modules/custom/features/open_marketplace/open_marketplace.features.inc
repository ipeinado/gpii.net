<?php
/**
 * @file
 * open_marketplace.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function open_marketplace_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function open_marketplace_node_info() {
  $items = array(
    'open_marketplace_product' => array(
      'name' => t('Open Marketplace Product'),
      'base' => 'node_content',
      'description' => t('Products being sold by GPII in the Open Marketplace.'),
      'has_title' => '1',
      'title_label' => t('Product Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
