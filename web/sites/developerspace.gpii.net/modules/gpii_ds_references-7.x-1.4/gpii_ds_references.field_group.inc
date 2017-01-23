<?php
/**
 * @file
 * gpii_ds_references.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gpii_ds_references_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_journal|node|scientific_publication|form';
  $field_group->group_name = 'group_article_journal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'reference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'For ARTICLES IN JOURNALS',
    'weight' => '1',
    'children' => array(
      0 => 'field_journal',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-article-journal field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_article_journal|node|scientific_publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_book_chapters|node|scientific_publication|form';
  $field_group->group_name = 'group_book_chapters';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'reference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'For BOOK CHAPTERS',
    'weight' => '2',
    'children' => array(
      0 => 'field_book_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-book-chapters field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_book_chapters|node|scientific_publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conf_pubs|node|scientific_publication|form';
  $field_group->group_name = 'group_conf_pubs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'reference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'For CONFERENCE PUBLICATIONS',
    'weight' => '0',
    'children' => array(
      0 => 'field_conference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'For CONFERENCE PUBLICATIONS',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-conf-pubs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_conf_pubs|node|scientific_publication|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_info|node|reference|full';
  $field_group->group_name = 'group_user_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'reference';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Info',
    'weight' => '0',
    'children' => array(
      0 => 'author',
      1 => 'post_date',
      2 => 'ds_user_picture',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-user-info field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_user_info|node|reference|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_info|node|reference|teaser';
  $field_group->group_name = 'group_user_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'reference';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Info',
    'weight' => '4',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-user-info field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_user_info|node|reference|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_web_docs|node|reference|form';
  $field_group->group_name = 'group_web_docs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'reference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'For WEB DOCUMENTS',
    'weight' => '3',
    'children' => array(
      0 => 'field_last_updated',
      1 => 'field_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_web_docs|node|reference|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('For ARTICLES IN JOURNALS');
  t('For BOOK CHAPTERS');
  t('For CONFERENCE PUBLICATIONS');
  t('For WEB DOCUMENTS');
  t('User Info');

  return $field_groups;
}
