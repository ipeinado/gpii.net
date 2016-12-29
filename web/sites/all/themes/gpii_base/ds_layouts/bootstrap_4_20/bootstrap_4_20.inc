<?php

/**
 * @file
 * Display Suite Bootstrap Two Col 4 20 configuration.
 */

function ds_bootstrap_4_20() {
  return array(
    'label' => t('Bootstrap Two Col 4-20'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right')
    ),
    // Uncomment if you want to include a CSS file for this layout (bootstrap_4_20.css)
    // 'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (bootstrap_4_20.png)
    'image' => TRUE,
  );
}
