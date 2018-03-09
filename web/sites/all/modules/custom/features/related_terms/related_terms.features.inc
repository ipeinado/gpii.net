<?php
/**
 * @file
 * related_terms.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function related_terms_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function related_terms_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function related_terms_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_category_suggestions'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_category_suggestions",
    "name" : "Category Suggestions",
    "index_id" : "categories",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : { "results" : true, "fields" : [] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function related_terms_default_search_api_index() {
  $items = array();
  $items['categories'] = entity_import('search_api_index', '{
    "name" : "Categories",
    "machine_name" : "categories",
    "description" : "Index for category and alternative terms search.",
    "server" : "stg06",
    "item_type" : "taxonomy_term",
    "options" : {
      "datasource" : { "bundles" : [ "things_that_i_have_trouble_with", "product_category1" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "field_alternative_vocabulary_1" : { "type" : "text", "boost" : "13.0" },
        "field_alternative_vocabulary_2" : { "type" : "text", "boost" : "2.0" },
        "field_alternative_vocabulary_3" : { "type" : "text", "boost" : "0.5" },
        "field_alternative_vocabulary_4" : { "type" : "text", "boost" : "0.2" },
        "field_alternative_vocabulary_5" : { "type" : "text", "boost" : "0.1" },
        "field_product_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "name" : { "type" : "text", "boost" : "21.0" },
        "node_count" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "tid" : { "type" : "integer" },
        "vocabulary" : { "type" : "integer", "entity_type" : "taxonomy_vocabulary" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : { "features" : "features" } }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_product_categories:parent" : "field_product_categories:parent" } }
        },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "name" : true,
              "field_alternative_vocabulary_1" : true,
              "field_alternative_vocabulary_2" : true,
              "field_alternative_vocabulary_3" : true,
              "field_alternative_vocabulary_4" : true,
              "field_alternative_vocabulary_5" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "name" : true,
              "field_alternative_vocabulary_1" : true,
              "field_alternative_vocabulary_2" : true,
              "field_alternative_vocabulary_3" : true,
              "field_alternative_vocabulary_4" : true,
              "field_alternative_vocabulary_5" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "name" : true,
              "field_alternative_vocabulary_1" : true,
              "field_alternative_vocabulary_2" : true,
              "field_alternative_vocabulary_3" : true,
              "field_alternative_vocabulary_4" : true,
              "field_alternative_vocabulary_5" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "name" : true,
              "field_alternative_vocabulary_1" : true,
              "field_alternative_vocabulary_2" : true,
              "field_alternative_vocabulary_3" : true,
              "field_alternative_vocabulary_4" : true,
              "field_alternative_vocabulary_5" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "name" : true,
              "field_alternative_vocabulary_1" : true,
              "field_alternative_vocabulary_2" : true,
              "field_alternative_vocabulary_3" : true,
              "field_alternative_vocabulary_4" : true,
              "field_alternative_vocabulary_5" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "name" : true,
              "field_alternative_vocabulary_1" : true,
              "field_alternative_vocabulary_2" : true,
              "field_alternative_vocabulary_3" : true,
              "field_alternative_vocabulary_4" : true,
              "field_alternative_vocabulary_5" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
