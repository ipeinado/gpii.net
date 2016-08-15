<?php

/**
 * @file
 * Provide Views handlers for facetapi.
 */

/**
 * Implements hook_views_data().
 */
function facetapi_views_views_data() {
  $data['facetapi']['table']['group'] = t('Facet API');
  $data['facetapi']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  $data['facetapi']['keep_facet_values'] = array(
    'title' => t('Keep facets'),
    'help' => t('Keeps the selected facets when updating the exposed filter.'),
    'filter' => array(
      'handler' => 'facetapi_views_handler_filter_keep_facet_values',
    ),
  );
  return $data;
}
