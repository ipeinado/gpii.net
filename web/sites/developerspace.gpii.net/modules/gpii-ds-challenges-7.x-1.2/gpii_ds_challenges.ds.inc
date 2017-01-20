<?php
/**
 * @file
 * gpii_ds_challenges.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function gpii_ds_challenges_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|challenge|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'challenge';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'accept_challenge_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'author_linked',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' <span class="text-muted">posed this challenge</span>',
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_search_api_facetapi_DAY',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => 'on&nbsp;',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'small text-muted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_thumbnail',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'user-info-picture',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_amount' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Prize',
          'lb-el' => 'div',
          'lb-cl' => 'challenge-prize-label',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'challenge-prize-div',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'challenge-prize-value',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_level_of_complexity' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Complexity',
          'lb-el' => 'div',
          'lb-cl' => 'challenge-complexity-label',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'challenge-complexity-div',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'field-level-of-complexity [node:field_level_of_complexity]',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_prize_explanation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'p',
          'ow-cl' => 'text-muted small',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Status',
          'lb-cl' => 'challenge-status-label',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'challenge-status-div',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'challenge-status-value',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|challenge|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|challenge|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'challenge';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'accept_challenge_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '-6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'author_linked',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' <span class="text-muted">posed this challenge</span>',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_search_api_facetapi_DAY',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '&nbsp;on&nbsp;',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'text-muted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_amount' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Prize',
          'lb-el' => 'span',
          'lb-cl' => 'challenge-prize-label',
          'lb-col' => TRUE,
          'lbw-el' => 'span',
          'lbw-cl' => 'challenge-prize-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'challenge-prize-div',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'span',
          'fis-cl' => 'challenge-prize-value',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_level_of_complexity' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Complexity',
          'lb-el' => 'span',
          'lb-cl' => 'challenge-complexity-label',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'challenge-complexity-div',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'field-level-of-complexity [node:field_level_of_complexity]',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_status' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'challenge-status-value',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|challenge|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function gpii_ds_challenges_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'accept_challenge_link';
  $ds_field->label = 'Accept challenge link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'challenge|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="mailto:[node:author:mail]" title="Contact the author of the challenge">Accept this challenge</a>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['accept_challenge_link'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function gpii_ds_challenges_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|challenge|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'challenge';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_18_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_user_info',
        2 => 'group_action_links',
        3 => 'ds_user_picture',
        4 => 'flag_upvote_challenge',
        6 => 'author',
        7 => 'accept_challenge_link',
        9 => 'body',
        11 => 'post_date',
        12 => 'field_read_more',
        13 => 'field_tags',
        14 => 'field_needs',
        15 => 'comments',
      ),
      'right' => array(
        1 => 'field_status',
        5 => 'field_level_of_complexity',
        8 => 'field_amount',
        10 => 'field_prize_explanation',
      ),
    ),
    'fields' => array(
      'group_user_info' => 'left',
      'field_status' => 'right',
      'group_action_links' => 'left',
      'ds_user_picture' => 'left',
      'flag_upvote_challenge' => 'left',
      'field_level_of_complexity' => 'right',
      'author' => 'left',
      'accept_challenge_link' => 'left',
      'field_amount' => 'right',
      'body' => 'left',
      'field_prize_explanation' => 'right',
      'post_date' => 'left',
      'field_read_more' => 'left',
      'field_tags' => 'left',
      'field_needs' => 'left',
      'comments' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|challenge|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|challenge|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'challenge';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_18_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'group_user_info',
        2 => 'body',
        5 => 'author',
        6 => 'flag_upvote_challenge',
        8 => 'accept_challenge_link',
        9 => 'post_date',
        10 => 'group_list_links',
      ),
      'right' => array(
        3 => 'field_status',
        4 => 'field_level_of_complexity',
        7 => 'field_amount',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'group_user_info' => 'left',
      'body' => 'left',
      'field_status' => 'right',
      'field_level_of_complexity' => 'right',
      'author' => 'left',
      'flag_upvote_challenge' => 'left',
      'field_amount' => 'right',
      'accept_challenge_link' => 'left',
      'post_date' => 'left',
      'group_list_links' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|challenge|teaser'] = $ds_layout;

  return $export;
}
