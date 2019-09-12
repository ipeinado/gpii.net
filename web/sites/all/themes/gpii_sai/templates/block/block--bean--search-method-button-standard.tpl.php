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
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

<?php

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
    if (in_array($currlanguage,$languages)) {
      $skiptranslate = ' skiptranslate';
    }
  }

?>

  <div class="container <?php print $skiptranslate; ?>">
    <div class="row">
      <div class="col-lg-4 col-md-4 col-sm-24 search-method">
  <a href="/search/"><img alt="Go to the Classic Search Page" src="/sites/saa.gpii.net/files/uploads/images/standardsearchcircle.png" /></a></div>

<div class="col-lg-4 col-md-4 col-sm-24 search-method text-adjust">
  <h3>
    <?php print t('Classic Search'); ?></h3>
  <p><?php print t('The world&#39;s most popular search method.'); ?></p></div>


      <div class="col-lg-16 col-md-16 col-sm-24 search-method-input">

      <?php
        // $blockObject = block_load('views', '-exp-search-page');
        // $block = _block_get_renderable_array(_block_render_blocks(array($blockObject)));
        // $output = drupal_render($block);
        // print $output;

        // View now has multiple exposed filters and needs to be manually specified
      ?>
        
        <section id="block-views-exp-search-page" class="block block-views standard-search-filters contextual-links-region clearfix">
          <form action="/search" method="get" id="views-exposed-form-search-page" accept-charset="UTF-8" class="hideSubmitButton-processed"><div>

          <div class="views-exposed-form">
            <div class="views-exposed-widgets clearfix">
              <div id="edit-search-api-views-fulltext-wrapper" class="views-exposed-widget views-widget-filter-search_api_views_fulltext">
                <label for="edit-search-api-views-fulltext">
                Enter a few words that describe what you're looking for in the box below.
                </label>
                <div class="views-widget">
                  <div class="form-item form-type-textfield form-item-search-api-views-fulltext" role="search">
                    <div class="input-group">
                      <input class="form-control form-text" data-search-api-autocomplete-search="search_api_views_search" data-min-autocomplete-length="3" type="text" id="edit-search-api-views-fulltext" name="search_api_views_fulltext" value="" size="30" maxlength="128" autocomplete="OFF" aria-autocomplete="list">
                    </div>
                    <input type="hidden" id="edit-search-api-views-fulltext-autocomplete" value="/index.php?q=search_api_autocomplete/search_api_views_search/-" disabled="disabled" class="autocomplete autocomplete-processed">
                    <span class="element-invisible" aria-live="assertive" id="edit-search-api-views-fulltext-autocomplete-aria-live"></span>
                  </div>
                </div>
              </div>
              <div class="views-exposed-widget views-submit-button">
                <button type="submit" id="edit-submit-search" name="" value="Search" class="btn btn-primary form-submit">Search</button>
              </div>
            </div>
          </div>

          </div></form>
        </section>

      </div>
    </div>
  </div>


</section>
