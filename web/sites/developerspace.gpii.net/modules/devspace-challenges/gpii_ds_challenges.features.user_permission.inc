<?php
/**
 * @file
 * gpii_ds_challenges.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function gpii_ds_challenges_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create challenge content'.
  $permissions['create challenge content'] = array(
    'name' => 'create challenge content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any challenge content'.
  $permissions['delete any challenge content'] = array(
    'name' => 'delete any challenge content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own challenge content'.
  $permissions['delete own challenge content'] = array(
    'name' => 'delete own challenge content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any challenge content'.
  $permissions['edit any challenge content'] = array(
    'name' => 'edit any challenge content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own challenge content'.
  $permissions['edit own challenge content'] = array(
    'name' => 'edit own challenge content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
