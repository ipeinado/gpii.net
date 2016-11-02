<?php
/**
 * @file
 * dspace_content.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dspace_content_taxonomy_default_vocabularies() {
  return array(
    'categories' => array(
      'name' => 'Categories',
      'machine_name' => 'categories',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'implementation_technologies' => array(
      'name' => 'Implementation Technologies',
      'machine_name' => 'implementation_technologies',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'licenses' => array(
      'name' => 'Licenses',
      'machine_name' => 'licenses',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'needs' => array(
      'name' => 'Needs',
      'machine_name' => 'needs',
      'description' => '',
      'hierarchy' => 2,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'solutions' => array(
      'name' => 'Solutions',
      'machine_name' => 'solutions',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'technology_categories' => array(
      'name' => 'Technology Categories',
      'machine_name' => 'technology_categories',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tool_type' => array(
      'name' => 'Tool Type',
      'machine_name' => 'tool_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
