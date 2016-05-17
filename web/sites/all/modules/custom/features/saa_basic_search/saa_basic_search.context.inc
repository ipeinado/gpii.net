<?php
/**
 * @file
 * saa_basic_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function saa_basic_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'saa_simple_search';
  $context->description = 'Blocks to be shown on the search and basic search results pages. ';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/simple' => 'search/simple',
        'search/simple/*' => 'search/simple/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search-page' => array(
          'module' => 'views',
          'delta' => '-exp-search-page',
          'region' => 'content',
          'weight' => '-10',
        ),
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks to be shown on the search and basic search results pages. ');
  t('search');
  $export['saa_simple_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'saa_simple_search_grid';
  $context->description = 'Blocks to be shown on the search and basic search results pages. (Grid View)';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/grid' => 'search/grid',
        'search/grid/*' => 'search/grid/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-search-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-search-page_1',
          'region' => 'content',
          'weight' => '-27',
        ),
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'content',
          'weight' => '-26',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks to be shown on the search and basic search results pages. (Grid View)');
  t('search');
  $export['saa_simple_search_grid'] = $context;

  return $export;
}
