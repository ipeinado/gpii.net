<?php

/**
 * @file
 * Settings forms for Taxonomy Set Lineage 
 */

/**
 * Our configuration form.
 * 
 * @param array $form
 *   The configuration form
 * @param array $form_state
 *   The configuration form state
 */
function taxonomy_set_lineage_config_form($form, &$form_state) {
  $form['taxonomy_set_lineage_affected_taxonomies'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Set lineage in the following vocabularies:'),
    '#options' => array(),
    '#description' => t('Checked vocabularies will have parent terms of all selected terms automatically checked.  For instance, in a hypothetical vocabulary "Geography", if "Berlin" is checked, parent terms "Germany" and "Europe" would be automatically checked.  This behavior is true for any field referencing this vocabulary. Note that this does not change rules about the total number of terms that can be selected in a given field or field instance.'),
    '#default_value' => variable_get('taxonomy_set_lineage_affected_taxonomies', array()),
  );
  foreach (taxonomy_vocabulary_get_names() as $vocab) {
    $form['taxonomy_set_lineage_affected_taxonomies']['#options'][$vocab->machine_name] = check_plain($vocab->name);
  }
  return system_settings_form($form);
}
