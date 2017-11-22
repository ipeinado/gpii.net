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
  // It also introduces a "skiptranslate" class that tells Google Translate to skip this menu item


  // get a list of installed languages
  $languages = array_keys(language_list());
  // remove the leading slash
  $currlanguage = substr($_SERVER['REQUEST_URI'], 1);
  // reduce the string to the first three characters
  $currlanguage = substr($currlanguage, 0, 3);
  //kpr($currlanguage);

  // initialize a variable in case we need to tell Google Translate to skip this menu
  $skiptranslate = '';
  // if the first three characters include a slash or  only two characters long (es, de, el), then add skiptranslate
  if(strstr($currlanguage, '/') || (strlen($currlanguage) == 2)) {
    $currlanguage = substr($currlanguage, 0, 2);
    if (in_array($currlanguage,$languages)) {
      $skiptranslate = ' skiptranslate';
    }
  }

  return '<ul class="menu nav navbar-nav primary' . $skiptranslate . '">' . $variables['tree'] . '</ul>';
}
