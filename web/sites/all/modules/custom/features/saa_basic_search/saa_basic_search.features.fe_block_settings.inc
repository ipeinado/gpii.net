<?php
/**
 * @file
 * saa_basic_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function saa_basic_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views--exp-search-page'] = array(
    'cache' => -1,
    'css' => NULL,
    'css_class' => '',
    'custom' => 0,
    'delta' => '-exp-search-page',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'devspace' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'devspace',
        'weight' => -11,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-search-page_1'] = array(
    'cache' => -1,
    'css' => NULL,
    'css_class' => '',
    'custom' => 0,
    'delta' => '-exp-search-page_1',
    'js' => NULL,
    'module' => 'views',
    'node_types' => array(),
    'noscript' => NULL,
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'devspace' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'devspace',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
