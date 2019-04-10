<?php

/**
 * @file
 * ul_notifications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ul_notifications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ul_notifications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function ul_notifications_default_message_type() {
  $items = array();
  $items['update_category'] = entity_import('message_type', '{
    "name" : "update_category",
    "description" : "Update Category",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "A product was updated in the category you follow",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EA product was updated in the category you follow\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:user:name] email: [message:user:mail]\\r\\nThe product [message:field-node-ref:title] was updated to:\\r\\n[message:field-node-ref:node-teaser]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] email: [message:user:mail]\\u003Cbr \\/\\u003E\\nThe product [message:field-node-ref:title] was updated to:\\u003Cbr \\/\\u003E\\n[message:field-node-ref:node-teaser]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['update_company'] = entity_import('message_type', '{
    "name" : "update_company",
    "description" : "Update Company",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "A product was updated in the company you follow",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EA product was updated in the company you follow\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:user:name] email: [message:user:mail]\\r\\nThe product [message:field-node-ref:title] made by [message:field-node-ref:field-company:title] was updated to:\\r\\n[message:field-node-ref:node-teaser]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] email: [message:user:mail]\\u003Cbr \\/\\u003E\\nThe product [message:field-node-ref:title] made by [message:field-node-ref:field-company:title] was updated to:\\u003Cbr \\/\\u003E\\n[message:field-node-ref:node-teaser]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['update_product'] = entity_import('message_type', '{
    "name" : "update_product",
    "description" : "Update Product",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "A product was updated",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EA product was updated\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "A product was updated [message:user:name] email: [message:user:mail]\\r\\nThe product [message:field-node-ref:title] was updated to:\\r\\n[message:field-node-ref:node-teaser]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EA product was updated [message:user:name] email: [message:user:mail]\\u003Cbr \\/\\u003E\\nThe product [message:field-node-ref:title] was updated to:\\u003Cbr \\/\\u003E\\n[message:field-node-ref:node-teaser]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
