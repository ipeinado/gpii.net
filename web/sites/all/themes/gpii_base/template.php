<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Include common functions used throughout the theme.
 */
include_once dirname(__FILE__) . '/includes/common.inc';

/**
 * Alter the default text colorization patterns.
 *
 * @param array $texts
 *   Default colorization rules.
 *
 * @see _bootstrap_colorize_text()
 */
function gpii_base_bootstrap_colorize_text_alter(&$texts) {
  $texts['contains'][t('Administer')] = 'default';
  $texts['contains'][t('Clone')] = 'success';
  $texts['matches'][t('Read more')] = 'primary';
}

/**
 * Alter the default icon patterns.
 *
 * @param string $texts
 *   Default iconization rules.
 *
 * @see _bootstrap_iconize_text()
 */
function gpii_base_bootstrap_iconize_text_alter(&$texts) {
  $texts['contains'][t('Administer')] = 'cog';
  $texts['contains'][t('Clone')] = 'plus';
}

/**
 * Define the theme's theme implementations.
 *
 * @param array $existing
 *   An array of existing implementations that may be used for override
 *   purposes.
 * @param string $type
 *   Whether a theme, module, etc. is being processed.
 * @param string $theme
 *   The actual name of theme, module, etc. that is being being processed.
 * @param string $path
 *   The directory path of the theme or module, so that it doesn't need to be
 *   looked up.
 *
 * @see hook_theme()
 */
function gpii_base_theme($existing, $type, $theme, $path) {
  $implementations['gpii_base_translate_toggle'] = array(
    'template' => 'gpii-base-translate-toggle',
    'path' => "{$path}/templates/gpii_base",
    'file' => 'gpii-base-translate-toggle.vars.php',
    'render element' => 'element');

  return $implementations;
}
