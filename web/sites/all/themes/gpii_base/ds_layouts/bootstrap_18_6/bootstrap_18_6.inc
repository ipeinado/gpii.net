<?php

/**
 * @file
 * Display Suite Bootstrap Two Col 18 6 configuration.
 */

function ds_bootstrap_18_6() {
  return array(
    'label' => t('Bootstrap Two Col 18-6'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right')
    ),
    // Uncomment if you want to include a CSS file for this layout (bootstrap_18_6.css)
    // 'css' => TRUE,
    // Uncomment if you want to include a preview for this layout (bootstrap_18_6.png)
    'image' => TRUE,
  );
}
