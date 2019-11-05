<?php

/**
 * Implements hook_block_info().
 */
function ul_save_and_updates_block_info() {
  $blocks['notify_me_product'] = array(
    'info' => t('Notify Me Product')
  );
  $blocks['notify_me_company'] = array(
    'info' => t('Notify Me Company')
  );
  $blocks['notify_me_search'] = array(
    'info' => t('Notify Me Search')
  );

  return $blocks;
}

/**
 * Implements hook_block_view()
 */
function ul_save_and_updates_block_view($delta = '') {
  switch ($delta) {
    case 'notify_me_product':
      ob_start();
      include 'notify-me-block-product.php';
      $string = ob_get_clean();
      $block['content'] = $string;
      return $block;

    case 'notify_me_company':
      ob_start();
      include 'notify-me-block-company.php';
      $string = ob_get_clean();
      $block['content'] = $string;
      return $block;

    case 'notify_me_search':
      ob_start();
      include 'notify-me-block-search.php';
      $string = ob_get_clean();
      $block['content'] = $string;
      return $block;
  }

}