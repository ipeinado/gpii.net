<?php
/**
 * @file
 * open_marketplace.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function open_marketplace_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_om_product_details|node|open_marketplace_product|default';
  $field_group->group_name = 'group_om_product_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_marketplace_product';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_om_product_info';
  $field_group->data = array(
    'label' => 'Product Details',
    'weight' => '11',
    'children' => array(
      0 => 'field_product_details',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'label' => 'Product Details',
      'instance_settings' => array(
        'classes' => 'group-om-product-details field-group-bootstrap_fieldgroup_accordion_item',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_om_product_details|node|open_marketplace_product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_om_product_info|node|open_marketplace_product|default';
  $field_group->group_name = 'group_om_product_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_marketplace_product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Info',
    'weight' => '3',
    'children' => array(
      0 => 'group_om_product_details',
      1 => 'group_om_product_shipping',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion',
    'format_settings' => array(
      'label' => 'Product Info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-om-product-info field-group-bootstrap_fieldgroup_accordion',
      ),
    ),
  );
  $field_groups['group_om_product_info|node|open_marketplace_product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_om_product_shipping|node|open_marketplace_product|default';
  $field_group->group_name = 'group_om_product_shipping';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_marketplace_product';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_om_product_info';
  $field_group->data = array(
    'label' => 'Shipping/Returns',
    'weight' => '12',
    'children' => array(
      0 => 'field_shipping_returns',
    ),
    'format_type' => 'bootstrap_fieldgroup_accordion_item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-om-product-shipping field-group-bootstrap_fieldgroup_accordion_item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_om_product_shipping|node|open_marketplace_product|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Product Details');
  t('Product Info');
  t('Shipping/Returns');

  return $field_groups;
}
