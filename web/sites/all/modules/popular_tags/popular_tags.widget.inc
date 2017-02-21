<?php

/**
 * @file
 * Functions for manipulating taxonomy_autocomplete widget to add
 * clickable/popular tags.
 */

/**
 * Util function to inject the popular tags functionality into a form element.
 *
 * @param string $children
 *   rendered form element
 * @param array $element
 *   form element
 */
function _popular_tags_inject($children, $element) {

  if (preg_match('/<\\/[a-zA-Z0-9]+>$/', $children, $matches) != 1) {
    return $children;
  }


  drupal_add_js(drupal_get_path('module', 'popular_tags') . '/popular_tags.js');
  drupal_add_css(drupal_get_path('module', 'popular_tags') . '/popular_tags.css');

  $field_name = $element['#field_name'];
  $field = field_info_field($field_name);
  $instance = field_info_instance($element['#entity_type'], $field_name, $element['#bundle']);

  $vname = $field['settings']['allowed_values'][0]['vocabulary'];
  $limit = $instance['widget']['settings']['popular_tags']['limit'];
  $showhide = $instance['widget']['settings']['popular_tags']['showhide'];


  if ($showhide) {
    $data = array();
    $data['popular_tags'][$field_name]['limit'] = $limit;
    drupal_add_js($data, array('type' =>'setting'));
  }

  $terms = _popular_tags_get_terms($vname, $limit, $showhide);
  $tag_terms = '<div class="tag-terms">';
  $classes[] = 'term';
  if (!empty($limit) && !empty($showhide)) {
    $classes[] = 'popular';
  }
  $count = 0;
  foreach ($terms as $tid => $term) {
    $count++;
    if (!empty($limit) && !empty($showhide) && $count > $limit) {
      $key = array_search('popular', $classes);
      if ($key !== FALSE) {
        unset($classes[$key]);
      }
    }

    // a term name containing comma needs to be quoted
    if(strpos($term->name, ',') !== FALSE) {
      $term->name = '"'. $term->name . '"';
    }

    $tag_terms .= t('<a class="@classes" data-toggle="tooltip" data-placement="top" href="#" title="@freq" >@term</a>', array(
      '@term' => $term->name,
      '@freq' => truncate_utf8(strip_tags($term->description), '600') .' (x' . $term->freq . ')',
      '@classes' => implode(' ', $classes),
    ));
  }
  $tag_terms .= '</div>';
  $html = '<div class="description popular-tags">' . t('You can type your own tags, or choose from the most commonly used tags below.');
  if (!empty($limit) && !empty($showhide)) {
    $html .= '<a href="#" class="show-all-terms">' . t('Show All Terms') . '</a>';
    $html .= '<a href="#" class="show-popular-terms">' . t('Show Popular Terms') . '</a>';
  }
  $html .= $tag_terms . '</div>';

// BBC: There are a few issues with this module related to how the popular tags code gets injected.
// Temporary fix below is to test which theme is active and inject the popular tags code in slightly different locations
  global $theme;

  if ($theme == 'gpii_devspace') {
    return substr_replace($children, $html, -(strlen($matches[0])), 0);
  }

  else {
    return substr_replace($children, $html, -(strlen($matches[0])+1), 0);
  }
}

/**
 * Util func to get the array of popular terms (key = tid, value = term name).
 *
 * @param string $vname
 *   name of the vocabulary
 * @param int $limit
 *   number of tags/terms to fetch (NULL if want default)
 * @param boolean $all
 *   flag set to TRUE if ALL tags/terms should be fetched
 *
 * @return array
 *   fetched terms
 */
function _popular_tags_get_terms($vname, $limit = NULL, $all = FALSE) {
  $query = db_select('taxonomy_term_data', 'td');
  $query->fields('td', array('tid', 'name', 'description'));
  $query->innerJoin('taxonomy_vocabulary', 'tv', 'tv.vid = td.vid');
  $query->leftJoin('taxonomy_index', 'tn', 'tn.tid = td.tid');
  $query->addExpression('COUNT(tn.tid)', 'freq');
  $query->condition('tv.machine_name', $vname);
  $query->groupBy('td.tid');
  $query->orderBy('freq', 'DESC');
  $query->orderBy('name');
  if (!empty($limit) && !$all) {
    $query->range(0, $limit);
  }

  $terms = $query->execute()->fetchAllAssoc('tid');
  return $terms;
}
