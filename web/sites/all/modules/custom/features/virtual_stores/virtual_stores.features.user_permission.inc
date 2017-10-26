<?php
/**
 * @file
 * virtual_stores.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function virtual_stores_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_trouble_with'.
  $permissions['create field_trouble_with'] = array(
    'name' => 'create field_trouble_with',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_trouble_with'.
  $permissions['edit field_trouble_with'] = array(
    'name' => 'edit field_trouble_with',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_trouble_with'.
  $permissions['edit own field_trouble_with'] = array(
    'name' => 'edit own field_trouble_with',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_trouble_with'.
  $permissions['view field_trouble_with'] = array(
    'name' => 'view field_trouble_with',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_trouble_with'.
  $permissions['view own field_trouble_with'] = array(
    'name' => 'view own field_trouble_with',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
