<?php
/**
 * @file
 * gpii_ds_references.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function gpii_ds_references_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag bookmarks'.
  $permissions['flag bookmarks'] = array(
    'name' => 'flag bookmarks',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Content Editor' => 'Content Editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag bookmarks'.
  $permissions['unflag bookmarks'] = array(
    'name' => 'unflag bookmarks',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Content Editor' => 'Content Editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
