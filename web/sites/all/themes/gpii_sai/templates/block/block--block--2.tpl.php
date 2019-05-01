<?php
/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see bootstrap_preprocess_block()
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see bootstrap_process_block()
 * @see template_process()
 *
 * @ingroup templates
 */

?>

<?php
/**
 * BBC: Check to see if the block we're about to render has a translation that matches the currently set language preference
 */

  // get a list of active languages
  $languages = array_keys(language_list());
  // remove the leading slash from the request
  $currlanguage = substr($_SERVER['REQUEST_URI'], 1);
  // reduce the string to the first three characters
  $currlanguage = substr($currlanguage, 0, 3);
  //kpr($currlanguage);

  // initialize a variable in case we need to tell Google Translate to skip this block
  $skiptranslate = '';
  // if the first three characters include a slash or is only two characters long (es, de, el), then add skiptranslate
  if(strstr($currlanguage, '/') || (strlen($currlanguage) == 2)) {
    $currlanguage = substr($currlanguage, 0, 2);
    // ensure that the block we're rendering has a translation for one of the languages we support
    if (in_array($currlanguage,$languages) && $block->i18n_mode == 1) {
      $classes .= ' skiptranslate';
    }
  }

?>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <?php // print $content ?>
  <?php drupal_add_js(drupal_get_path('theme', 'gpii_sai') . '/js/standard_search.js'); ?>
  <script>
    (function ($) {
      'use strict';

      $(document).ready(function(){

        var related_terms_from_php = {};

        // related_terms_from_php will be set here. If it is not set, there were no related terms.
        <?php 

          $search_term = $_GET['search_api_views_fulltext'];

          $query = json_decode('{
            "qf": [
              "tm_field_alternative_vocabulary_2^2",
              "tm_field_alternative_vocabulary_3^0.5",
              "tm_field_alternative_vocabulary_4^0.2",
              "tm_field_alternative_vocabulary_5^0.1",
              "tm_name^21"
            ],
            "fl": "item_id,score",
            "fq": [
              "bs_status:\"true\"",
              "index_id:\"categories\"",
              "hash:3927w6"
            ],
            "start": "0",
            "rows": "25",
            "json.nl": "map",
            "q": "\"' . $search_term . '\"",
            "wt": "json"
          }');
          
          $query_string = urldecode(http_build_query($query));
          $query_string = preg_replace('/\[\d+\]/', '', $query_string);
          
          // get the active search_api_solr information
          $solr = search_api_server_load_multiple(FALSE, $conditions);
          $solr_url = $solr['stg06']->options['scheme'] . '://' . $solr['stg06']->options['host'] . ':' . $solr['stg06']->options['port'] . $solr['stg06']->options['path'];
          
          $search_url = $solr_url . "/select?" . $query_string;

          if ($search_term . '' != '') {
            $results = json_decode(file_get_contents($search_url));

            $items = $results->response->docs;

            if (count($items) >= 1) {
              $related_terms = [];

              foreach ($items as $item) {
                $term_id = $item->item_id;
                $term = taxonomy_term_load($term_id);
                array_push($related_terms, [
                    'tid' => $term->tid,
                    'name' => $term->name,
                    ]);
              }

              echo "related_terms_from_php = " . json_encode($related_terms) . ";";
            }
          }

        ?>

        if (related_terms_from_php.length >= 1) {
          var related_params = parseQueryString(query);
          var reg1 = /f\[(\d+)\]/g;
          var reg2 = /field_product_categories/;
          var f_index = -1; // facet index
          Object.keys(related_params).forEach(key => {
            let value = related_params[key];
            key.replace(reg1, function (g0, g1) {
              if (g1 > f_index) {
                f_index = g1;
              }
            });
            if (reg2.test(key)) {
                delete related_params[key];
            }
          });
          f_index++;
          related_params['search_api_views_fulltext'] = '';

          $.each(related_terms_from_php, function(i, item) {
            related_params['f[' + f_index + ']'] = 'field_product_categories1:' + item.tid;
            var new_query = Object.keys(related_params).map(key => encodeURIComponent(key) + '=' + encodeURIComponent(related_params[key])).join('&');

            var anchor = $('<a></a>').text(item.name).attr('href', base_url + "?" + new_query);
            var list_item = $('<li></li>').append(anchor);
            $('.related-search-terms .panel-body ul').append(list_item);
          });
          $('.related-search-terms').css('display', 'block');
        }

      });
    }(jQuery));
  </script>
  <p class="element-invisible">Note: The sort, count and disconinued filters listed below will cause the page to reload. </p>
  <div class="remote-filters">

    <div class="btn-group" role="group">
      
      <div class="btn-group remote-wrapper remote-sort-by" role="group">
        <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false" data-edit="edit-sort-by">
          Sort: <span class="current-value">Relevance</span> <span class="caret"></span> 
        </button>
        <ul class="dropdown-menu">
          <li><a value="search_api_relevance">Relevance</a></li>
          <li><a value="search_api_aggregation_2">Alphabetical</a></li>
        </ul>
      </div>

      <div class="btn-group remote-wrapper remote-sort-order" role="group">
        <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false" data-edit="edit-sort-order">
          <span class="current-value">Descending</span> <span class="caret"></span>
        </button>
        <ul class="dropdown-menu">
          <li><a value="ASC">Ascending</a></li>
          <li><a value="DESC">Descending</a></li>
        </ul>
      </div>

      <div class="btn-group remote-wrapper remote-items-per-page" role="group">
        <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false" data-edit="edit-items-per-page">
          Count: <span class="current-value">25</span> <span class="caret"></span>
        </button>
        <ul class="dropdown-menu">
          <li><a value="15">15</a></li>
          <li><a value="25">25</a></li>
          <li><a value="50">50</a></li>
          <li><a value="100">100</a></li>
        </ul>
      </div>

    </div>

    <div class="checkbox remote-wrapper remote-show-discontinued">
      <label>
        <input type="checkbox"> Show discontinued items
      </label>
    </div>

  </div>

  <?php if ($_GET['field_product_categories1_1']): ?>
    <p><strong>Note: </strong>Some products in this list have been excluded. Please reset your search to view all categories.</p> 
  <?php endif;?>

</section>
