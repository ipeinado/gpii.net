<?php
/**
 * @file
 * gpii_developerspace_blocks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function gpii_developerspace_blocks_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
