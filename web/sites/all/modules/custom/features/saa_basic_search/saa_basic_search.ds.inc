<?php
/**
 * @file
 * saa_basic_search.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function saa_basic_search_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|product|search_results';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'product';
  $ds_fieldsetting->view_mode = 'search_results';
  $ds_fieldsetting->settings = array(
    'accessible_read_more' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|product|search_results'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function saa_basic_search_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'accessible_read_more';
  $ds_field->label = 'Accessible Read More';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'bean' => 'bean',
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
     // dsm($entity);   // output the array so you can see your variables
    print "<a class=\\"read-more btn-default btn \\" title=\\"Read more: [node:title]\\" href=\\"[node:url]\\">Read more<span class=\\"element-invisible\\">: [node:title]</span><span class=\\"fa fa-chevron-circle-right\\"></span></a>";
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['accessible_read_more'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function saa_basic_search_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|search_results';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'search_results';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'title',
        1 => 'field_product_image',
        2 => 'body',
        3 => 'accessible_read_more',
      ),
    ),
    'fields' => array(
      'title' => 'central',
      'field_product_image' => 'central',
      'body' => 'central',
      'accessible_read_more' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|product|search_results'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function saa_basic_search_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search_results';
  $ds_view_mode->label = 'Search Results';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search_results'] = $ds_view_mode;

  return $export;
}
