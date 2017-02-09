<?php

/**
 * @file
 * Display Suite Two column Stacked Fluid - modified for use on product edit pages.
 */

function ds_twocol_stacked_fluid() {
  return array(
    'label' => t('Two column Stacked Fluid (Admin)'),
    'regions' => array(
      'header' => t('Header'),
      'left' => t('Left'),
      'right' => t('Right'),
      'footer' => t('Footer'),
    ),
    // Uncomment if you want to include a CSS file for this layout (twocol_stacked_fluid.css)
    'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (twocol_stacked_fluid.png)
    'image' => TRUE,
  );
}
