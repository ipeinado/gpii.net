<?php
/**
 * @file
 * openmarketplace_order_processing.features.inc
 */

/**
 * Implements hook_views_api().
 */
function openmarketplace_order_processing_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function openmarketplace_order_processing_node_info() {
  $items = array(
    'order' => array(
      'name' => t('Order'),
      'base' => 'node_content',
      'description' => t('Order form for OpenMarketplace purchases.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_payment_method().
 */
function openmarketplace_order_processing_default_payment_method() {
  $items = array();
  $items['paypal_express'] = entity_import('payment_method', '{
    "controller_data" : {
      "capture" : "Authorization",
      "email_address" : "",
      "password" : "VCK75TCSCQ7LGA8B",
      "server" : 1,
      "signature" : "AZyJIVtrKZJIFn35ToMVOPQoZ8ZAAT0o-pBqbwwRdjoi.gwiCxab7T2M",
      "username" : "treasurer_api1.raisingthefloor.net"
    },
    "enabled" : true,
    "name" : "paypal_express",
    "title_specific" : "PayPal Express",
    "title_generic" : "PayPal Express",
    "uid" : 1,
    "rdf_mapping" : [],
    "controller_class_name" : "PayPalPaymentECPaymentMethodController"
  }');
  return $items;
}
