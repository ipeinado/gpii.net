<?php
/**
 * @file
 * related_terms.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function related_terms_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vocab_alt_terms|taxonomy_term|product_category1|form';
  $field_group->group_name = 'group_vocab_alt_terms';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'product_category1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Alternate Terms',
    'weight' => '39',
    'children' => array(
      0 => 'field_alternative_vocabulary_1',
      1 => 'field_alternative_vocabulary_2',
      2 => 'field_alternative_vocabulary_3',
      3 => 'field_alternative_vocabulary_4',
      4 => 'field_alternative_vocabulary_5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Alternate Terms',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-vocab-alt-terms field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_vocab_alt_terms|taxonomy_term|product_category1|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternate Terms');

  return $field_groups;
}
