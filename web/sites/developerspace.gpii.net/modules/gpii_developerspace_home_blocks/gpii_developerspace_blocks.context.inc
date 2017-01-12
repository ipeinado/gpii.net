<?php
/**
 * @file
 * gpii_developerspace_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function gpii_developerspace_blocks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Home Page of the Developer Space';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'search_api_page-search' => array(
          'module' => 'search_api_page',
          'delta' => 'search',
          'region' => 'hero',
          'weight' => '-9',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page of the Developer Space');
  $export['homepage'] = $context;

  return $export;
}
