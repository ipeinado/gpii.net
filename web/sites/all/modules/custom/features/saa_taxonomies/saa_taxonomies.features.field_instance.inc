<?php
/**
 * @file
 * saa_taxonomies.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function saa_taxonomies_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-difficulties-field_difficulties_question'.
  $field_instances['taxonomy_term-difficulties-field_difficulties_question'] = array(
    'bundle' => 'difficulties',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_difficulties_question',
    'label' => 'Question',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-difficulties-field_origin_id'.
  $field_instances['taxonomy_term-difficulties-field_origin_id'] = array(
    'bundle' => 'difficulties',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Unique ID from Misericordia demo site. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_origin_id',
    'label' => 'Origin ID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-features-field_origin_id'.
  $field_instances['taxonomy_term-features-field_origin_id'] = array(
    'bundle' => 'features',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Unique ID from Misericordia demo site. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_origin_id',
    'label' => 'Origin ID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-iso_9241-field_origin_id'.
  $field_instances['taxonomy_term-iso_9241-field_origin_id'] = array(
    'bundle' => 'iso_9241',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Unique ID from Misericordia demo site. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_origin_id',
    'label' => 'Origin ID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-product_category-field_origin_id'.
  $field_instances['taxonomy_term-product_category-field_origin_id'] = array(
    'bundle' => 'product_category',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Unique ID from Misericordia demo site. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_origin_id',
    'label' => 'Origin ID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Origin ID');
  t('Question');
  t('Unique ID from Misericordia demo site. ');

  return $field_instances;
}
