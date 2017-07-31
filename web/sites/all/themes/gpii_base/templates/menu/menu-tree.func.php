<?php
/**
 * @file
 * Stub file for gpii_base_menu_tree() and suggestion(s).
 */

 /**
 * Theme wrapper function for the primary menu links.
 *
 * @see bootstrap_menu_tree__primary()
 */
function gpii_base_menu_tree__primary(&$variables) {
  // This is the same as the implementation of the Drupal Bootstrap theme, but
  // it adds the "primary" class.
  //
  // It also introduces a "skiptranslate" class that tells Google Translate


  // get a list of installed languages
  $languages = array_keys(language_list());
  // remove the leading slash
  $currlanguage = substr($_SERVER['REQUEST_URI'], 1);
  // reduce the string to the first three characters
  $currlanguage = substr($currlanguage, 0, 3);

  // initialize a variable in case we need to tell Google Translate to skip this menu
  $skiptranslate = '';
  // if the first three characters include a slash, then this
  if(strstr($currlanguage, '/')) {
    $currlanguage = substr($currlanguage, 0, 2);
    if (in_array($currlanguage,$languages)) {
      $skiptranslate = ' skiptranslate';
    }
  }

  return '<ul class="menu nav navbar-nav primary' . $skiptranslate . '">' . $variables['tree'] . '</ul>';
}
