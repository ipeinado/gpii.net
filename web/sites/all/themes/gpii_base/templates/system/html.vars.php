<?php
/**
 * @file
 * Stub file for "html" theme hook [pre]process functions.
 */

/**
 * Processes variables for the "html" theme hook.
 *
 * See template for list of available variables.
 *
 * @see html.tpl.php
 * @see bootstrap_process_html()
 *
 * @ingroup theme_process
 */
function gpii_base_process_html(&$variables) {
  bootstrap_process_html($variables);

  $block = block_load('google_translator', 'active_languages');
  $block = _block_get_renderable_array(_block_render_blocks(array($block)));

  // These bits of content are added here at the root instead of elsewhere,
  // e.g., within a region, to allow z-index stacking to work properly.
  $variables['page_top'] .= theme('gpii_base_translate_toggle');
  $variables['page_top'] .= drupal_render($block);
}
