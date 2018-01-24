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
 * @see _bootstrap_colorize_text()hyb
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

/**
 * Override of theme('textarea').
 * Deprecate misc/textarea.js in favor of using the 'resize' CSS3 property.
 */

function gpii_base_textarea($variables) {
  $element = $variables ['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element ['#attributes']) . '>' . check_plain($element ['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

/**
 * Implements Hook form alter
 */

function gpii_base_form_alter(&$form, &$form_state, $form_id) {

  if ($form_id == 'user_login' || $form_id == 'user_register_form') {

    // use the address to determine whether we're on the register or login page and adjust the help text that follows
    $path = arg(1);

    if ($path == 'register') {
      $form_function = 'create a new account';
    }
    else {
      $form_function = 'sign in';
    }

    // add some introductory text so that nonvisual users are aware that login/account creation can be done via hybridauth
    $form['intro_text'] = array(
          '#type' => 'item',
          '#markup' => '<p class="sr-only">Please ' . $form_function . ' by completing the form or using social media links below.</p>',
          '#weight' => -200,
      );
    // push the hybridauth widget to the end of the form.
    $form['hybridauth'] = array(
      '#type' => 'hybridauth_widget',
      '#weight' => 300,
    );
  }
}
