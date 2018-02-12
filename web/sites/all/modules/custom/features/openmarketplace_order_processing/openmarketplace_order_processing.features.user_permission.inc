<?php
/**
 * @file
 * openmarketplace_order_processing.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openmarketplace_order_processing_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create order content'.
  $permissions['create order content'] = array(
    'name' => 'create order content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any order content'.
  $permissions['delete any order content'] = array(
    'name' => 'delete any order content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own order content'.
  $permissions['delete own order content'] = array(
    'name' => 'delete own order content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any order content'.
  $permissions['edit any order content'] = array(
    'name' => 'edit any order content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own order content'.
  $permissions['edit own order content'] = array(
    'name' => 'edit own order content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'order openmarketplace products'.
  $permissions['order openmarketplace products'] = array(
    'name' => 'order openmarketplace products',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'non-authenticated user' => 'non-authenticated user',
    ),
    'module' => 'gpii_saa_custom',
  );

  // Exported permission: 'payment.global.administer'.
  $permissions['payment.global.administer'] = array(
    'name' => 'payment.global.administer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.administer'.
  $permissions['payment.payment.administer'] = array(
    'name' => 'payment.payment.administer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.delete.any'.
  $permissions['payment.payment.delete.any'] = array(
    'name' => 'payment.payment.delete.any',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.delete.own'.
  $permissions['payment.payment.delete.own'] = array(
    'name' => 'payment.payment.delete.own',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.update.any'.
  $permissions['payment.payment.update.any'] = array(
    'name' => 'payment.payment.update.any',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.update.own'.
  $permissions['payment.payment.update.own'] = array(
    'name' => 'payment.payment.update.own',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.view.any'.
  $permissions['payment.payment.view.any'] = array(
    'name' => 'payment.payment.view.any',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment.view.own'.
  $permissions['payment.payment.view.own'] = array(
    'name' => 'payment.payment.view.own',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.create.PayPalPaymentECPaymentMethodController'.
  $permissions['payment.payment_method.create.PayPalPaymentECPaymentMethodController'] = array(
    'name' => 'payment.payment_method.create.PayPalPaymentECPaymentMethodController',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.delete.any'.
  $permissions['payment.payment_method.delete.any'] = array(
    'name' => 'payment.payment_method.delete.any',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.delete.own'.
  $permissions['payment.payment_method.delete.own'] = array(
    'name' => 'payment.payment_method.delete.own',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.update.any'.
  $permissions['payment.payment_method.update.any'] = array(
    'name' => 'payment.payment_method.update.any',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.update.own'.
  $permissions['payment.payment_method.update.own'] = array(
    'name' => 'payment.payment_method.update.own',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.view.any'.
  $permissions['payment.payment_method.view.any'] = array(
    'name' => 'payment.payment_method.view.any',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_method.view.own'.
  $permissions['payment.payment_method.view.own'] = array(
    'name' => 'payment.payment_method.view.own',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.payment_status.view'.
  $permissions['payment.payment_status.view'] = array(
    'name' => 'payment.payment_status.view',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  // Exported permission: 'payment.rules.administer'.
  $permissions['payment.rules.administer'] = array(
    'name' => 'payment.rules.administer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'payment',
  );

  return $permissions;
}
