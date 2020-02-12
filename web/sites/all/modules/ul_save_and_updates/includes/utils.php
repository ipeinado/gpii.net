<?php

function _saved_search_updateNotificationType($string, $key, $value) {
  if ($key == 'new_entries') {
    $term = 'new';
  }
  else if ($key == 'major_changes') {
    $term = 'changed';
  }

  if ($string == '') {
    $nt = [];
  }
  else {
    $nt = explode(', ', $string);
  }

  if ($value == 'on') {
    if (!in_array($term, $nt)) array_push($nt, $term);
  }
  else if ($value == 'off') {
    unset($nt[array_search($term, $nt)]);
  }


  return implode(', ', $nt) == '' ? null : implode(', ', $nt);
}

function _saved_search_createTableMarkup($headers, $rows, $noneMessage) {
  $markup = '<table class="table table-bordered table-hover" summary="This table lists saved notifications. You can edit saved searches, modify notification preferences or delete the notifications using the form controls in each row. Changes to notification settings are saved automatically.">';

  $markup .= '<tr>';
  foreach ($headers as $header) {
    $markup .= '<th scope="col">' . $header . '</th>';
  }
  $markup .= '</tr>';

  if ($rows != null || count($rows) > 0) {
    foreach ($rows as $id => $row) {
      $markup .= "<tr id=\"saved-search-$id\">";
      foreach ($row as $column) {
        $markup .= "<td>$column</td>";
      }
      $markup .= '</tr>';
    }
  }
  else {
    $markup .= "<tr><td colspan=\"" . count($headers) . "\">$noneMessage</td></tr>";
  }

  $markup .= '</table>';

  return $markup;
}

function _saved_search_createRemoveButton($id) {
  return '<button class="notify-me-button-remove btn btn-danger btn-xs" style="cursor: pointer;" data-id="' . $id . '" data-toggle="modal" data-target="#notify-me-modal-confirm">Remove</button>';
}

function _saved_search_createUpdateCheckbox($class, $id, $name, $status, $label) {
  return '<form class="notify-me-form-edit" data-callback="notifyMeCheckbox">'
          .'<input type="hidden" name="id" value="' . $id . '" />'
          .'<input type="hidden" name="' . $name . '" value="off" />'
          ."<div class=\"checkbox\"><label for=\"$class-$id\"><input id=\"$class-$id\" class=\"$class\" type=\"checkbox\" name=\"$name\" value=\"on\" " . ($status ? 'checked' : '') . "/><span class=\"sr-only\">$label</span> </label></div>"
        .'</form>';
}

function _saved_search_createNameEdit($id, $name) {
  return '<span class="notify-me-name-wrapper" style="white-space: nowrap;">'
    ."<span class=\"notify-me-name\">$name</span>"
    .' <button class="notify-me-name-edit btn-default btn btn-xs" data-id="' . $id . '" style="cursor: pointer;">edit</button></span>';
}

function _saved_search_getManufacturerProducts($manfId) {
  $query = db_select('node', 'n');
  $query->join('field_data_field_manufacturer_reference', 'm', 'n.nid = m.entity_id');
  $query->fields('n', array('nid'))
        ->condition('type', 'product')
        ->condition('field_manufacturer_reference_target_id', $manfId);
        
  $result = $query->execute()->fetchAll();
  $nids = array();
  foreach ($result as $nid) {
    $nids[] = $nid->nid;
  }
  return $nids;
}

function _saved_search_buildSolrQueryFromGET($get) {
  $query = array(
    'fl' => 'is_nid',
    'fq' => [],
    'sort' => 'is_nid asc',
    'start' => 0,
    'rows' => 2147483647,
    'wt' => 'json'
  );

  // Classic Search
  parse_str($get, $getQuery);

  if ($getQuery['f']) {
    foreach ($getQuery['f'] as $facet) {
     $query['fq'][] = _saved_search_replaceFieldName($facet);
    }
  }
  
  if ($getQuery['product_status']) {
    $status = $getQuery['product_status'] == '1' ? '1' : '[1 TO 2]';
    $query['fq'][] = _saved_search_replaceFieldName('product_status:'. $status);
  }

  if ($getQuery['search_api_views_fulltext']) {
    $query['q'] = $getQuery['search_api_views_fulltext'];
  }

  // Power Search
  if ($getQuery['query']) {
    $query['q'] = $getQuery['query'];
  }
  $urlArray = explode('&', $get);
  foreach ($urlArray as $value) {
    $keyValue = explode('=', $value);
    if ($keyValue[0] == 'product_category') {
      $query['fq'][] = 'im_field_product_categories1:' . $keyValue[1];
    }
    if ($keyValue[0] == 'os') {
      $query['fq'][] = 'im_field_operating_system:' . $keyValue[1];
    }
    
  }

  $query_string = urldecode(http_build_query($query));
  $query_string = preg_replace('/\[\d+\]/', '', $query_string);
  $query_string = preg_replace('/\s/', '%20', $query_string);

  return $query_string;
}

/** 
 * This is used by classic search to convert facet API query parameters to solr field names. 
 */

function _saved_search_replaceFieldName($filter) {
  $filter = explode(':', $filter);
  $field = $filter[0];
  $filter[0] = preg_replace("/^$field$/", _saved_search_getSolrFieldEquivalent($field), $filter[0]);
  return implode(':', $filter);
}

function _saved_search_getSolrFieldEquivalent($string) {
  switch($string) {
    case 'field_operating_system':
      return 'im_field_operating_system';
      break;

    case 'product_status':
      return 'ss_field_status';
      break;

    case 'field_product_categories1':
      return 'im_field_product_categories1';
      break;

    case 'product_category':
      return 'im_field_product_categories1';
      break;
    

    default:
      return false;
      break;
  }
}

function _saved_search_getSearchResults($get) {
  $query_string = _saved_search_buildSolrQueryFromGET($get);
  // get the active search_api_solr information
  $solr = search_api_server_load_multiple(FALSE, $conditions);
  $solr_url = $solr['stg06']->options['scheme'] . '://' . $solr['stg06']->options['host'] . ':' . $solr['stg06']->options['port'] . $solr['stg06']->options['path'];

  $search_url = $solr_url . "/select?" . $query_string;
  return json_decode(file_get_contents($search_url));
}

function _saved_search_getFilterTerms($facets) {
  $tids = array();
  foreach ($facets as $field) {
      $tids = array_merge($tids, $field);
  }
  $terms = taxonomy_term_load_multiple($tids);
  $termNames = array();
  foreach ($terms as $term ) {
    $termNames[] = $term->name;
  }
  return implode(', ', $termNames);
}

/**
 * Helper Function used to generate a UUID for saved searches. These
 * values are used in conjunction with unsubscrie links from notification 
 * emails. 
 */

function _saved_search_delete() { // POST
  $results = db_delete('saved_searches')
    ->condition('id', $_POST['id'])
    ->execute();
  $data = array('success' => $results > 0, 'results' => $results);
  return drupal_json_output($data);
}

function _saved_search_uniqidReal($length = 27) {
  // uniqid gives 24 chars, but you could adjust it to your needs.
  if (function_exists("random_bytes")) {
      $bytes = random_bytes(ceil($length / 2));
  } elseif (function_exists("openssl_random_pseudo_bytes")) {
      $bytes = openssl_random_pseudo_bytes(ceil($length / 2));
  } else {
      throw new Exception("no cryptographically secure random function available");
  }
  return substr(bin2hex($bytes), 0, $length);
}