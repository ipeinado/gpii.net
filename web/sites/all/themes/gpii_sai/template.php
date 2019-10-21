<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Tell subthemes to go ahead and use template overrides as originally designed
 * (bootstrap module changes this by default)
 */

function gpii_sai_preprocess_page(&$vars, $hook) {
  if (isset($vars['node']->type)) {
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  }
}

function gpii_sai_entity_view_mode_alter(&$view_mode, &$context) {
  if ($context['entity_type'] == 'node' && $context['entity']->field_generic_product['und'][0]['value'] == 1) {
    $view_mode = 'generic_product';
  }
}