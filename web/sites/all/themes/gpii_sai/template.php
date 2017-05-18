<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Tell subtheme to go ahead and use template overrides as originally designed
 * (bootstrap module changes this)
 */

function gpii_sai_preprocess_page(&$vars, $hook) {
  if (isset($vars['node']->type)) {
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  }
}
