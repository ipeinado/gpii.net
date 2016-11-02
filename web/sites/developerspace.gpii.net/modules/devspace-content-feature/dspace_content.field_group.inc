<?php
/**
 * @file
 * dspace_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dspace_content_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|node|bb|form';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bb';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '16',
    'children' => array(
      0 => 'field_source_repository',
      1 => 'field_contact',
      2 => 'field_get_started',
      3 => 'field_read_more',
      4 => 'field_project',
      5 => 'field_additional_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_links|node|bb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_paragraph|field_collection_item|field_discussion_by_disabilities|default';
  $field_group->group_name = 'group_paragraph';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_discussion_by_disabilities';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'paragraph',
    'weight' => '4',
    'children' => array(
      0 => 'field_discussion',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'paragraph',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-paragraph field-group-html-element',
        'element' => 'p',
        'show_label' => '0',
        'label_element' => 'p',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_paragraph|field_collection_item|field_discussion_by_disabilities|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tags|node|bb|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bb';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '15',
    'children' => array(
      0 => 'field_needs',
      1 => 'field_solutions',
      2 => 'field_implementation_technologie',
      3 => 'field_license',
      4 => 'field_technology_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tags|node|bb|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_term_publishing|taxonomy_term|categories|form';
  $field_group->group_name = 'group_taxonomy_term_publishing';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'categories';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publishing settings',
    'weight' => '4',
    'children' => array(
      0 => 'field_taxonomy_term_status',
      1 => 'field_taxonomy_term_publish_on',
      2 => 'field_taxonomy_term_unpublish_on',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsed',
      'label' => 'Publishing settings',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
    ),
  );
  $field_groups['group_taxonomy_term_publishing|taxonomy_term|categories|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Links');
  t('Publishing settings');
  t('Tags');
  t('paragraph');

  return $field_groups;
}
