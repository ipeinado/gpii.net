<?php
/**
 * @file
 * manufacturers_and_products.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function manufacturers_and_products_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editor_notes|node|manufacturer|form';
  $field_group->group_name = 'group_editor_notes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'manufacturer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Needs Work',
    'weight' => '15',
    'children' => array(
      0 => 'field_needs_work',
      1 => 'field_notes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-editor-notes field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_editor_notes|node|manufacturer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editor_notes|node|product|form';
  $field_group->group_name = 'group_editor_notes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Needs Work',
    'weight' => '16',
    'children' => array(
      0 => 'field_needs_work',
      1 => 'field_notes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Needs Work',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-editor-notes field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_editor_notes|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_features|node|product|form';
  $field_group->group_name = 'group_features';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Features',
    'weight' => '37',
    'children' => array(
      0 => 'field_features',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-features field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_features|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_field_os|node|product|form';
  $field_group->group_name = 'group_field_os';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'OS',
    'weight' => '38',
    'children' => array(
      0 => 'field_operating_system',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'OS',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-field-os field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_field_os|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_needs|node|product|form';
  $field_group->group_name = 'group_needs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Needs and Wants',
    'weight' => '37',
    'children' => array(
      0 => 'field_needs',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-needs field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_needs|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_category|node|product|form';
  $field_group->group_name = 'group_product_category';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Product Category',
    'weight' => '36',
    'children' => array(
      0 => 'field_product_categories1',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-product-category field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_product_category|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|product|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '17',
    'children' => array(
      0 => 'group_product_category',
      1 => 'group_features',
      2 => 'group_field_os',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-taxonomies field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_taxonomies|node|product|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Features');
  t('Needs Work');
  t('Needs and Wants');
  t('OS');
  t('Product Category');
  t('Taxonomies');

  return $field_groups;
}
