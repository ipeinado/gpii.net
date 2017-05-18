<?php
/**
 * @file
 * Displays a Bootstrap-style nav for tabs/pills.
 *
 * Available variables:
 * - $is_empty: Boolean: any content to render at all?
 * - $classes: The classes set on the group div.
 * - $panels: An array of panels containing content.
 * - $index: The index of the active tab/pane.
 *
 * @ingroup themeable
 *
 * BBC: Template override to change from <h4> to <h2>
 */
?>

<?php if (!$is_empty) : ?>

  <?php if ($is_single) : ?>

    <?php print $panels[0]['content']; ?>

  <?php else: ?>

    <div class="panel-group <?php print $classes; ?>" id="<?php print $id; ?>">

      <?php foreach ($panels as $index => $panel) : ?>

        <div class="panel panel-default <?php print $panel['classes']; ?>">

          <div class="panel-heading">
            <h2 class="panel-title">
              <a data-toggle="collapse" data-parent="#<?php print $id; ?>" href="#<?php print $panel['id'] ?>-<?php print $index; ?>">
                <?php print $panel['label']; ?>
              </a>
            </h2>
          </div>

          <div id="<?php print $panel['id'] ?>-<?php print $index; ?>" class="panel-collapse <?php print $panel['collapse']; ?> <?php print $panel['classes']; ?>">
            <div class="panel-body"><?php print $panel['content']; ?></div>
          </div>

        </div>

      <?php endforeach; ?>

    </div>

  <?php endif; ?>

<?php endif; ?>
