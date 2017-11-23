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
      $classes .= ' skiptranslate';
    }
  }
?>
<p><a aria-controls="feedback-collapsible" aria-expanded="false" class="btn btn-default collapsed<?php print $skiptranslate; ?>" data-target="#feedback-collapsible" data-toggle="collapse" type="button" href="#feedback-collapsible"><?php print t('If you see an error or omission or if you have any other comments, please let us know'); ?></a></p>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<div class="container">
  <div class="row">
  <div class="col-sm-24">
    <div class="collapse" id="feedback-collapsible">
      <?php print $content ?>
    </div>
  </div>
  </div>
</div>


</section>
