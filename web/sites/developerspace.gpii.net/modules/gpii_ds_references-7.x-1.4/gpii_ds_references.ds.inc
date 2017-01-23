<?php
/**
 * @file
 * gpii_ds_references.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function gpii_ds_references_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|reference|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'reference';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'author_linked',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' <span class="text-muted">shared this reference</span>',
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
          'ow-el' => 'p',
          'ow-cl' => 'text-muted',
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
    'field_book_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_citation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_conference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_journal' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_keywords' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_last_updated' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Link',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_publication_authors' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Authors',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'field-publication-authors',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => TRUE,
        ),
      ),
    ),
    'field_type_of_reference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Type of reference',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_website' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_year' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Publication date',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Description',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-ref-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-ref-row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'field-ref-items',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|reference|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|reference|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'reference';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '-5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'author_linked',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' shared this reference on ',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'text-muted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'changed_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_search_api_facetapi_DAY',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span ',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_book_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ',&nbsp;',
          'fi' => TRUE,
          'fi-el' => 'em',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_conference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ',&nbsp;',
          'fi' => TRUE,
          'fi-el' => 'em',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_journal' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ',&nbsp;',
          'fi' => TRUE,
          'fi-el' => 'em',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_publication_authors' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ',&nbsp;',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'field-publication-authors',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => TRUE,
        ),
      ),
    ),
    'field_type_of_reference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'reference-type',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_website' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '. Retrieved from&nbsp;',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_year' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'field-name-body',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|reference|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function gpii_ds_references_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|reference|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'reference';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'ds_user_picture',
        1 => 'group_user_info',
        2 => 'author',
        3 => 'field_type_of_reference',
        4 => 'post_date',
        5 => 'field_publication_authors',
        6 => 'field_year',
        7 => 'field_conference',
        8 => 'field_journal',
        9 => 'field_website',
        10 => 'field_book_title',
        11 => 'field_last_updated',
        12 => 'body',
        13 => 'field_link',
        14 => 'field_citation',
        15 => 'field_keywords',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'ds_content',
      'group_user_info' => 'ds_content',
      'author' => 'ds_content',
      'field_type_of_reference' => 'ds_content',
      'post_date' => 'ds_content',
      'field_publication_authors' => 'ds_content',
      'field_year' => 'ds_content',
      'field_conference' => 'ds_content',
      'field_journal' => 'ds_content',
      'field_website' => 'ds_content',
      'field_book_title' => 'ds_content',
      'field_last_updated' => 'ds_content',
      'body' => 'ds_content',
      'field_link' => 'ds_content',
      'field_citation' => 'ds_content',
      'field_keywords' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|reference|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|reference|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'reference';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_type_of_reference',
        1 => 'title',
        2 => 'field_publication_authors',
        3 => 'field_book_title',
        4 => 'field_journal',
        5 => 'field_conference',
        6 => 'field_year',
        7 => 'author',
        8 => 'field_website',
        9 => 'field_link',
        10 => 'body',
        11 => 'changed_date',
      ),
    ),
    'fields' => array(
      'field_type_of_reference' => 'central',
      'title' => 'central',
      'field_publication_authors' => 'central',
      'field_book_title' => 'central',
      'field_journal' => 'central',
      'field_conference' => 'central',
      'field_year' => 'central',
      'author' => 'central',
      'field_website' => 'central',
      'field_link' => 'central',
      'body' => 'central',
      'changed_date' => 'central',
    ),
    'limit' => array(
      'field_publication_authors' => '3',
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
  $export['node|reference|teaser'] = $ds_layout;

  return $export;
}
