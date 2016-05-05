<?php
/**
 * @file
 * saa_taxonomies.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function saa_taxonomies_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_terms|taxonomy_term|needs_and_wants|form';
  $field_group->group_name = 'group_related_terms';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'needs_and_wants';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Terms',
    'weight' => '35',
    'children' => array(
      0 => 'field_features',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related Terms',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-related-terms field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_related_terms|taxonomy_term|needs_and_wants|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Related Terms');

  return $field_groups;
}
