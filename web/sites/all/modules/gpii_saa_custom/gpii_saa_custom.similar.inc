<?php
/**
 * This .inc file contains most of the logic for the similar products search feature.
 */

function similar_search_form() {
    $form = array();
    $form['product'] = array(
        '#title' => t('Product Name'),
        '#type' => 'textfield',
        '#autocomplete_path' => 'similar/autocomplete',
     );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
        '#submit' => array('similar_search_submit'),
    );
    return $form;
}



function similar_search_submit($form, &$form_state) {
    // get the nid from the product value and redirect
    //dpm($form_state['values']['product']);
    preg_match("/\[[^\]]*\]/", $form_state['values']['product'], $matches);
    $find = array('[nid:',']');
    $replace = array('');
    $matches = str_replace($find,$replace,$matches);
    //dpm($matches[0]);
    drupal_goto('search/similar/' . trim($matches[0]));
}
  


?>
