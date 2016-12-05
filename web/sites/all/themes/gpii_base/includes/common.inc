<?php
/**
 * @file
 * List of common helper functions for use in the GPII base theme.
 */

/**
 * Determine how many regions are set within the page variables typically given
 * to the (pre-)processing functions.
 *
 * @param array $variables
 *   Page variables to check.
 * @param array $regions_to_check
 *   Names of the regions to check for.
 *
 * @return
 *   Number of regions that are set.
 */
function gpii_base_num_set_regions($variables, $regions_to_check) {
  $num_set_regions = 0;

  foreach ($regions_to_check as $region_to_check) {
    if (!empty($variables['page'][$region_to_check])) {
      $num_set_regions += 1;
    }
  }

  return $num_set_regions;
}

/**
 * Get info about general regions set up as adjacent columns.
 *
 * @param array $variables
 *   Page variables to check.
 * @param array $regions_to_check
 *   Names of the regions to check for.
 *
 * @return
 *   Region information.
 */
function gpii_base_column_regions_info($variables, $regions_to_check) {
  $num_columns = gpii_base_num_set_regions($variables, $regions_to_check);
  $column_width = floor(12/max(1, $num_columns));

  return array(
    'num_columns' => $num_columns,
    'column_width' => $column_width,
    'column_class' => 'col-sm-'.$column_width,
    'has_columns' => $num_columns > 0);
}

/**
 * Generate the HTML for a group that contains equal width regions meant to be
 * displayed as columns.
 *
 * @param array $page
 *   Standard Drupal page variables.
 * @param array $region_info
 *   Information about the region group.
 * @param string $group
 *   The name of the group.
 *
 * @return
 *   Generated HTML for the group.
 *
 * @see gpii_base_column_regions_info()
 */
function gpii_base_equal_width_column_regions($page, $region_info, $group) {
  $html = '<div class="row gpii-region_row-'.$group.'">';

  foreach (array('first', 'second', 'third', 'fourth', 'fifth') as $column) {
    $region = "{$group}_{$column}";

    if (!empty($page[$region])) {
      $html .= '<div class="gpii-region_column gpii-region_column-'.$region.' '.$region_info[$group]['column_class'].'">';
      $html .= render($page[$region]);
      $html .= '</div>';
    }
  }

  $html .= '</div>';

  return $html;
}

/**
 * Generate HTML for a group that contains variable width regions meant to be
 * displayed as columns.
 *
 * @param array $page
 *   Standard Drupal page variables.
 * @param array $region_info
 *   Information about the region group.
 * @param string $group
 *   The name of the group.
 * @param array $widths
 *   An array of widths for each column.
 *
 * @return
 *   Generated HTML for the group.
 *
 * @see gpii_base_column_regions_info()
 */
function gpii_base_variable_width_column_regions($page, $region_info, $group, $widths) {
  $html = '<div class="row gpii-region_row-'.$group.'">';

  foreach (array('first', 'second', 'third', 'fourth', 'fifth') as $column) {
    $region = "{$group}_{$column}";

    if (!empty($page[$region])) {
      $html .= '<div class="gpii-region_column gpii-region_column-'.$region.' col-sm-'.$widths[$column].'">';
      $html .= render($page[$region]);
      $html .= '</div>';
    }
  }

  $html .= '</div>';

  return $html;
}
