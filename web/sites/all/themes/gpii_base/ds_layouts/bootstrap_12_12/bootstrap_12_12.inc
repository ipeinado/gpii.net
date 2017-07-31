<?php

/**
 * @file
 * Display Suite Bootstrap Two Col 12 12 configuration.
 */

function ds_bootstrap_12_12() {
  return array(
    'label' => t('Bootstrap Two Col 12-12'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right')
    ),
    // Uncomment if you want to include a CSS file for this layout (bootstrap_12_12.css)
    // 'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (bootstrap_12_12.png)
    'image' => TRUE,
  );
}
