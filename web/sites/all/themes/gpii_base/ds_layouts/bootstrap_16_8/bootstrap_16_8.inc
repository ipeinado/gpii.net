<?php

/**
 * @file
 * Display Suite Bootstrap Two Col 16 8 configuration.
 */

function ds_bootstrap_16_8() {
  return array(
    'label' => t('Bootstrap Two Col 16-8'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right')
    ),
    // Uncomment if you want to include a CSS file for this layout (bootstrap_16_8.css)
    // 'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (bootstrap_16_8.png)
    'image' => TRUE,
  );
}
