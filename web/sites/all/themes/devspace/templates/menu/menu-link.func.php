<?php
/**
 * @file
 * menu-link.func.php
 */

/**
 * Overrides theme_menu_link().
 */
function devspace_menu_link(array $variables) {
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
    //Here we need to change from ==1 to >=1 to allow for multilevel submenus
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] >= 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      // Remove the caret class since jquery submenus alread adds this $title .= ' <span class="caret"></span>';
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
}
/**
 * Overrides theme_menu_link() for book module.
 */
function devspace_menu_link__book_toc(array $variables) {
  $element = $variables['element'];
  $sub_menu = drupal_render($element['#below']);
  $title = $element['#title'];
  $href = $element['#href'];
  $options = !empty($element['#localized_options']) ? $element['#localized_options'] : array();
  $attributes = !empty($element['#attributes']) ? $element['#attributes'] : array();
  $attributes['role'] = 'presentation';
  // Header.
  $link = TRUE;
  if ($title && $href === FALSE) {
    $attributes['class'][] = 'dropdown-header';
    $link = FALSE;
  }
  // Divider.
  elseif ($title === FALSE && $href === FALSE) {
    $attributes['class'][] = 'divider';
    $link = FALSE;
  }
  // Active.
  elseif (($href == $_GET['q'] || ($href == '<front>' && drupal_is_front_page())) && (empty($options['language']))) {
    $attributes['class'][] = 'active';
  }

  // Filter the title if the "html" is set, otherwise l() will automatically
  // sanitize using check_plain(), so no need to call that here.
  if (!empty($options['html'])) {
    $title = _bootstrap_filter_xss($title);
  }
  // Convert to a link.
  if ($link) {
    $title = l($title, $href, $options);
  }
  return '<li' . drupal_attributes($attributes) . '>' . $title . $sub_menu . "</li>\n";
}
