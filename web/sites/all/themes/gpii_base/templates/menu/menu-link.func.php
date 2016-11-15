<?php
/**
 * @file
 * Stub file for gpii_base_menu_link() and suggestion(s).
 */

/**
 * Returns HTML for a menu link and submenu.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: Structured array data for a menu link.
 *
 * @return string
 *   The constructed HTML.
 *
 * @see theme_menu_link()
 * @see bootstrap_menu_link()
 *
 * @ingroup theme_functions
 */
function gpii_base_menu_link($variables) {
  $use_bootstrap_themer = array(
    'menu_link__main_menu',
    'menu_link__user_menu');

  // Only use Drupal Bootstrap's theme implementation for a few of the major
  // menus. Otherwise, use the default one. The code below is taken from Drupal
  // Bootstrap's implementation, but it removes the restriction on how nested
  // the menus can be. This requires Smartmenu's Bootstrap library.
  if (in_array($variables['theme_hook_original'], $use_bootstrap_themer)) {
    $element = $variables['element'];
    $sub_menu = '';

    $title = $element['#title'];
    $href = $element['#href'];
    $options = !empty($element['#localized_options']) ? $element['#localized_options'] : array();
    $attributes = !empty($element['#attributes']) ? $element['#attributes'] : array();

    if ($element['#below']) {
      // Prevent dropdown functions from being added to management menu so it
      // does not affect the navbar module.
      if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
        $sub_menu = drupal_render($element['#below']);
      }
      // CHANGED: removed the restriction on how nested the menus can be, but
      // only if they're set to display as expanded.
      elseif (!empty($element['#original_link']['depth']) && !empty($element['#original_link']['expanded'])) {
        // Add our own wrapper.
        unset($element['#below']['#theme_wrappers']);
        $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';

        // Generate as standard dropdown.
        $title .= ' <span class="caret"></span>';
        $attributes['class'][] = 'dropdown';

        $options['html'] = TRUE;

        // Set dropdown trigger element to # to prevent inadvertant page loading
        // when a submenu link is clicked.
        $options['attributes']['data-target'] = '#';
        $options['attributes']['class'][] = 'dropdown-toggle';
        $options['attributes']['data-toggle'] = 'dropdown';
      }
    }

    // Filter the title if the "html" is set, otherwise l() will automatically
    // sanitize using check_plain(), so no need to call that here.
    if (!empty($options['html'])) {
      $title = _bootstrap_filter_xss($title);
    }

    return '<li' . drupal_attributes($attributes) . '>' . l($title, $href, $options) . $sub_menu . "</li>\n";
  } else {
    return theme_menu_link($variables);
  }
}
