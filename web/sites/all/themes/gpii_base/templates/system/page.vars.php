<?php

    /**

    * Implements template_preprocess_html().

    */



    function gpii_base_preprocess_html(&$variables) {

     //Adds typekit js to theme
     drupal_add_js('//use.typekit.net/bpk2tek.js', 'external');
     drupal_add_js('try{Typekit.load({ async: true });}catch(e){}', 'inline', 'page_bottom');

    }

/**
 * @file
 * File for "page" theme hook [pre]process functions.
 */

/**
 * Pre-processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_preprocess
 */
function gpii_base_preprocess_page(&$variables) {
  // Set variables for the sidebar and content regions depending on which are
  // used on the page since the regions don't all have equal widths.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-12 col-sm-push-6"';
    $variables['sidebar_first_column_class'] = 'col-sm-6 col-sm-pull-12';
    $variables['sidebar_second_column_class'] = 'col-sm-6';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['content_column_class'] = ' class="col-sm-18 col-sm-push-6"';
    $variables['sidebar_first_column_class'] = 'col-sm-6 col-sm-pull-18';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-18"';
    $variables['sidebar_first_column_class'] = '';
    $variables['sidebar_second_column_class'] = 'col-sm-6';
  }
  else {
    $variables['content_column_class'] = ' class="col-sm-24"';
    $variables['sidebar_first_column_class'] = '';
    $variables['sidebar_second_column_class'] = '';
  }

  // The following region groups have equal-width columns that need to be sized
  // based on how many columns actually have content in them.
  $variables['region_info']['topbar'] = gpii_base_column_regions_info($variables, array(
    'topbar_first', 'topbar_second'));
  $variables['region_info']['header'] = gpii_base_column_regions_info($variables, array(
    'header_first', 'header_second'));
  $variables['region_info']['menu'] = gpii_base_column_regions_info($variables, array(
    'menu_first', 'menu_second'));
  $variables['region_info']['secondary'] = gpii_base_column_regions_info($variables, array(
    'secondary_first', 'secondary_second', 'secondary_third', 'secondary_fourth'));
  $variables['region_info']['tertiary'] = gpii_base_column_regions_info($variables, array(
    'tertiary_first', 'tertiary_second', 'tertiary_third', 'tertiary_fourth'));
  $variables['region_info']['footer'] = gpii_base_column_regions_info($variables, array(
    'footer_first', 'footer_second', 'footer_third', 'footer_fourth', 'footer_fifth'));
  $variables['region_info']['fine_print'] = gpii_base_column_regions_info($variables, array(
    'fine_print_first', 'fine_print_second', 'fine_print_third', 'fine_print_fourth'));

  $variables['has_footer_regions'] = gpii_base_num_set_regions($variables, array(
    'footer_first', 'footer_second', 'footer_third', 'footer_fourth', 'footer_fifth',
    'fine_print_first', 'fine_print_second', 'fine_print_third',
    'fine_print_fourth', 'footer_postscript'));
}

/**
 * Processes variables for the "page" theme hook.
 *
 * See template for list of available variables.
 *
 * @see page.tpl.php
 *
 * @ingroup theme_process
 */
function gpii_base_process_page(&$variables) {

}
