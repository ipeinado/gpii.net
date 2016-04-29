<?php
/**
 * @file
 * manufacturers_and_products.features.inc
 */

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
  );
  drupal_alter('node_info', $items);
  return $items;
}
