<?php

/**
 * @file
 * Bootstrap 8-16 template for Display Suite.
 *
 * Available variables:
 *
 * Layout:
 * - $classes: String of classes that can be used to style this layout.
 * - $contextual_links: Renderable array of contextual links.
 * - $layout_wrapper: wrapper surrounding the layout.
 *
 * BBC: Overridden to invoke fluid behavior when left or right content is empty.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <?php if ($left || $right): ?>
  <div class="row">
  <?php if ($left): ?>
    <<?php print $left_wrapper; ?> class="<?php if (empty($right)): ?>col-sm-24 <?php else: ?>col-sm-18 <?php endif; ?><?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper; ?>>
  <?php endif; ?>
  <?php if ($right): ?>
    <<?php print $right_wrapper; ?> class="<?php if (empty($left)): ?>col-sm-24 <?php else: ?>col-sm-6 <?php endif; ?><?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper; ?>>
  </div>
  <?php endif; ?>
  <?php endif; ?>
</<?php print $layout_wrapper ?>>


<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
