<?php
/**
 * @file
 * open_marketplace.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function open_marketplace_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|open_marketplace_product|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'open_marketplace_product';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'purchase_now' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'field_product_price' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'strong',
          'prefix' => '<strong>Price: </strong> $',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-product-price',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_product_details' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_access_features' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h2',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-access-features',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|open_marketplace_product|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function open_marketplace_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'action_links';
  $ds_field->label = 'Action Links';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['action_links'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'help';
  $ds_field->label = 'Help';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['help'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'purchase_now';
  $ds_field->label = 'Purchase Now';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'open_marketplace_product|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="text-center">
<button class="btn btn-purchase" type="button">Purchase Now</button><br />
<small>[placeholder button]</small><div>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['purchase_now'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'tabs';
  $ds_field->label = 'Tabs';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['tabs'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function open_marketplace_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|open_marketplace_product|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'open_marketplace_product';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_18_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_om_product_image',
        1 => 'field_om_manufacturer_reference',
        2 => 'body',
        3 => 'group_om_product_info',
        4 => 'field_shipping_returns',
        8 => 'field_product_details',
        9 => 'group_om_product_details',
        10 => 'group_om_product_shipping',
      ),
      'right' => array(
        5 => 'field_product_price',
        6 => 'purchase_now',
        7 => 'field_access_features',
      ),
    ),
    'fields' => array(
      'field_om_product_image' => 'left',
      'field_om_manufacturer_reference' => 'left',
      'body' => 'left',
      'group_om_product_info' => 'left',
      'field_shipping_returns' => 'left',
      'field_product_price' => 'right',
      'purchase_now' => 'right',
      'field_access_features' => 'right',
      'field_product_details' => 'left',
      'group_om_product_details' => 'left',
      'group_om_product_shipping' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|open_marketplace_product|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|open_marketplace_product|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'open_marketplace_product';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'twocol_stacked_fluid';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_om_product_image',
        2 => 'field_om_manufacturer_reference',
        3 => 'body',
        4 => 'field_product_details',
        5 => 'field_shipping_returns',
        6 => 'language',
        7 => 'redirect',
        8 => 'path',
      ),
      'right' => array(
        0 => 'field_product_price',
        1 => 'field_access_features',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_om_product_image' => 'left',
      'field_om_manufacturer_reference' => 'left',
      'body' => 'left',
      'field_product_details' => 'left',
      'field_shipping_returns' => 'left',
      'language' => 'left',
      'redirect' => 'left',
      'path' => 'left',
      'field_product_price' => 'right',
      'field_access_features' => 'right',
    ),
  );
  $export['node|open_marketplace_product|form'] = $ds_layout;

  return $export;
}
