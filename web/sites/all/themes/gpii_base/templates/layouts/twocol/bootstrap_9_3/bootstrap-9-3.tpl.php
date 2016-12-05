<?php
/**
 * @file
 * Bootstrap 9-3 template for Display Suite.
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
    <<?php print $left_wrapper; ?> class="<?php if (empty($right)): ?>col-sm-12 <?php else: ?>col-sm-9 <?php endif; ?><?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper; ?>>
  <?php endif; ?>
  <?php if ($right): ?>
    <<?php print $right_wrapper; ?> class="<?php if (empty($left)): ?>col-sm-12 <?php else: ?>col-sm-3 <?php endif; ?><?php print $right_classes; ?>">
      <?php print $right; ?>
    </<?php print $right_wrapper; ?>>
  </div>
  <?php endif; ?>
  <?php endif; ?>
</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
