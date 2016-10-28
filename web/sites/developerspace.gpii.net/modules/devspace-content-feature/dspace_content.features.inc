<?php
/**
 * @file
 * dspace_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dspace_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dspace_content_node_info() {
  $items = array(
    'bb' => array(
      'name' => t('Building Block'),
      'base' => 'node_content',
      'description' => t('Libraries, Software &amp; Hardware Modules as well Code Snippets that will help you build accessible and personalized technology.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'framework' => array(
      'name' => t('Development Framework'),
      'base' => 'node_content',
      'description' => t('A complete framework (toolbox) that makes it easier, faster, less expensive to conceive, create, test, and market new solutions.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'handbook' => array(
      'name' => t('Handbook'),
      'base' => 'node_content',
      'description' => t('A reference document that helps developers build accessible products.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A funded project or consortium that contributed to the GPII developer space.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'quicksheet' => array(
      'name' => t('Quicksheet'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'solution' => array(
      'name' => t('Solution'),
      'base' => 'node_content',
      'description' => t('Information on access techniques and approaches for all known barriers and disability categories.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'tool' => array(
      'name' => t('Developer Tool'),
      'base' => 'node_content',
      'description' => t('A specialized tool that help developers build, test and integrate accessible and personalizable software and hardware.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'tutorial' => array(
      'name' => t('Tutorial'),
      'base' => 'node_content',
      'description' => t('A step by step guide that enables developers to understand building blocks, frameworks or tools as a  hands-on experience.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
