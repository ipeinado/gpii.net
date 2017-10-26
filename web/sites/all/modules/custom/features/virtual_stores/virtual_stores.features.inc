<?php
/**
 * @file
 * virtual_stores.features.inc
 */

/**
 * Implements hook_node_info().
 */
function virtual_stores_node_info() {
  $items = array(
    'virtual_store' => array(
      'name' => t('Virtual Store'),
      'base' => 'node_content',
      'description' => t('Use the virtual store content type to create a new virtual store in the browse virtual stores section of the site. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
