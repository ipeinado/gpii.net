<?php
/**
 * @file
 * virtual_stores.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function virtual_stores_taxonomy_default_vocabularies() {
  return array(
    'things_that_i_have_trouble_with' => array(
      'name' => 'Things that I Have Trouble With',
      'machine_name' => 'things_that_i_have_trouble_with',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
