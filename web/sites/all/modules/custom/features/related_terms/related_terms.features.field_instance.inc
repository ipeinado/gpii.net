<?php
/**
 * @file
 * related_terms.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function related_terms_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-product_category1-field_alternative_vocabulary_1'.
  $field_instances['taxonomy_term-product_category1-field_alternative_vocabulary_1'] = array(
    'bundle' => 'product_category1',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Alternative terms or phrases with a 80-100% probability of matching the category.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_alternative_vocabulary_1',
    'label' => 'Alternative Vocabulary 1',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-product_category1-field_alternative_vocabulary_2'.
  $field_instances['taxonomy_term-product_category1-field_alternative_vocabulary_2'] = array(
    'bundle' => 'product_category1',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Alternative terms or phrases with a 60-80% probability of matching the category.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_alternative_vocabulary_2',
    'label' => 'Alternative Vocabulary 2',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-product_category1-field_alternative_vocabulary_3'.
  $field_instances['taxonomy_term-product_category1-field_alternative_vocabulary_3'] = array(
    'bundle' => 'product_category1',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Alternative terms or phrases with a 40-60% probability of matching the category.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_alternative_vocabulary_3',
    'label' => 'Alternative Vocabulary 3',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-product_category1-field_alternative_vocabulary_4'.
  $field_instances['taxonomy_term-product_category1-field_alternative_vocabulary_4'] = array(
    'bundle' => 'product_category1',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Alternative terms or phrases with a 20-40% probability of matching the category.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_alternative_vocabulary_4',
    'label' => 'Alternative Vocabulary 4',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-product_category1-field_alternative_vocabulary_5'.
  $field_instances['taxonomy_term-product_category1-field_alternative_vocabulary_5'] = array(
    'bundle' => 'product_category1',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Alternative terms or phrases with a 0-20% probability of matching the category.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_alternative_vocabulary_5',
    'label' => 'Alternative Vocabulary 5',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 36,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternative Vocabulary 1');
  t('Alternative Vocabulary 2');
  t('Alternative Vocabulary 3');
  t('Alternative Vocabulary 4');
  t('Alternative Vocabulary 5');
  t('Alternative terms or phrases with a 0-20% probability of matching the category.');
  t('Alternative terms or phrases with a 20-40% probability of matching the category.');
  t('Alternative terms or phrases with a 40-60% probability of matching the category.');
  t('Alternative terms or phrases with a 60-80% probability of matching the category.');
  t('Alternative terms or phrases with a 80-100% probability of matching the category.');

  return $field_instances;
}
