<?php
/**
 * @file
 * gpii_ds_challenges.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function gpii_ds_challenges_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_action_links|node|challenge|full';
  $field_group->group_name = 'group_action_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Action links',
    'weight' => '-1',
    'children' => array(
      0 => 'flag_upvote_challenge',
      1 => 'accept_challenge_link',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Action links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-action-links field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_action_links|node|challenge|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_links|node|challenge|teaser';
  $field_group->group_name = 'group_list_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'List of links',
    'weight' => '3',
    'children' => array(
      0 => 'flag_upvote_challenge',
      1 => 'accept_challenge_link',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'List of links',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-action-links',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_list_links|node|challenge|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prize|node|challenge|form';
  $field_group->group_name = 'group_prize';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prize',
    'weight' => '-2',
    'children' => array(
      0 => 'field_prize_explanation',
      1 => 'field_amount',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prize',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-prize field-group-fieldset',
        'description' => 'If there is a prize, please state it here',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_prize|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_info|node|challenge|full';
  $field_group->group_name = 'group_user_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Info',
    'weight' => '-2',
    'children' => array(
      0 => 'author',
      1 => 'post_date',
      2 => 'ds_user_picture',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'User Info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-info field-group-div',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'h3',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_user_info|node|challenge|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_info|node|challenge|teaser';
  $field_group->group_name = 'group_user_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Info',
    'weight' => '-5',
    'children' => array(
      0 => 'author',
      1 => 'post_date',
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
  $field_groups['group_user_info|node|challenge|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Action links');
  t('List of links');
  t('Prize');
  t('User Info');

  return $field_groups;
}
