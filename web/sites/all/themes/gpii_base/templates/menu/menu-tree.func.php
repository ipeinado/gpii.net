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
  return '<ul class="menu nav navbar-nav primary">' . $variables['tree'] . '</ul>';
}