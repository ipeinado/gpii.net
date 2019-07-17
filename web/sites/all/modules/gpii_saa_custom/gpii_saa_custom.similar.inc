<?php

/**
 * @file
 * This .inc file contains most of the logic for the similar products.
 */

/**
 * Render a form that supports searchable selectWoo widget.
 */
function similar_search_form() {

  // Some fantasy DB table which holds cities.
  $query = db_select('node', 'n');

  // Select rows that match the string.
  $return = $query
    ->fields('n', array('title', 'nid'))
    ->condition('n.title', '%' . db_like($string) . '%', 'LIKE')
    ->condition('n.status', 1)
    ->condition('n.type', 'product')
    ->orderBy('n.title', ASC)
    ->execute();

  // Add matches to $matches.
  foreach ($return as $row) {
    $match = check_plain($row->title);
    $matches[$row->nid] = html_entity_decode($match, ENT_QUOTES);
  }

  // Return for JS.
  // dpm($matches);
  $form = array();
  $form['product'] = array(
    '#title' => t('Find products similar to what?'),
    '#type' => 'select',
    '#options' => $matches,
    '#empty_option' => t('Choose a product from our database'),
    '#multiple'     => 0,
    '#select2' => array(
      'allowClear' => TRUE,
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#submit' => array('similar_search_submit'),
  );
  return $form;
}

/**
 * Redirect to the specified nid.
 */
function similar_search_submit($form, &$form_state) {
  drupal_goto('search/similar/' . $form_state['values']['product']);
}