<?php
/**
 * @file
 * related_terms.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function related_terms_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vocabulary_study_difficulties_category_import';
  $feeds_importer->config = array(
    'name' => 'Vocabulary Study: Difficulties Category Import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'tid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'term_name',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'alt_1',
            'target' => 'field_alternative_vocabulary_1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'alt_2',
            'target' => 'field_alternative_vocabulary_2',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'alt_3',
            'target' => 'field_alternative_vocabulary_3',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'alt_4',
            'target' => 'field_alternative_vocabulary_4',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'alt_5',
            'target' => 'field_alternative_vocabulary_5',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '0',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'things_that_i_have_trouble_with',
        'language' => 'en',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vocabulary_study_difficulties_category_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'vocabulary_study_import';
  $feeds_importer->config = array(
    'name' => 'Vocabulary Study: Product Category Import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'tid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'term_name',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'alt_1',
            'target' => 'field_alternative_vocabulary_1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'alt_2',
            'target' => 'field_alternative_vocabulary_2',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'alt_3',
            'target' => 'field_alternative_vocabulary_3',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'alt_4',
            'target' => 'field_alternative_vocabulary_4',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'alt_5',
            'target' => 'field_alternative_vocabulary_5',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '0',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'product_category1',
        'language' => 'en',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['vocabulary_study_import'] = $feeds_importer;

  return $export;
}
