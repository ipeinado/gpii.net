<?php
/**
 * @file
 * manufacturers_and_products.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function manufacturers_and_products_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_duplicate_nid'.
  $permissions['create field_duplicate_nid'] = array(
    'name' => 'create field_duplicate_nid',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Curated Content Editor' => 'Curated Content Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_needs_work'.
  $permissions['create field_needs_work'] = array(
    'name' => 'create field_needs_work',
    'roles' => array(
      'Author' => 'Author',
      'Comment moderator' => 'Comment moderator',
      'Content Admin' => 'Content Admin',
      'Contribution Editor' => 'Contribution Editor',
      'Curated Content Editor' => 'Curated Content Editor',
      'Demo Page Editor' => 'Demo Page Editor',
      'Translator' => 'Translator',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_notes'.
  $permissions['create field_notes'] = array(
    'name' => 'create field_notes',
    'roles' => array(
      'Author' => 'Author',
      'Content Admin' => 'Content Admin',
      'Contribution Editor' => 'Contribution Editor',
      'Curated Content Editor' => 'Curated Content Editor',
      'Demo Page Editor' => 'Demo Page Editor',
      'Translator' => 'Translator',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_product_categories'.
  $permissions['create field_product_categories'] = array(
    'name' => 'create field_product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_source'.
  $permissions['create field_source'] = array(
    'name' => 'create field_source',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Curated Content Editor' => 'Curated Content Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_duplicate_nid'.
  $permissions['edit field_duplicate_nid'] = array(
    'name' => 'edit field_duplicate_nid',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Curated Content Editor' => 'Curated Content Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_needs_work'.
  $permissions['edit field_needs_work'] = array(
    'name' => 'edit field_needs_work',
    'roles' => array(
      'Author' => 'Author',
      'Content Admin' => 'Content Admin',
      'Contribution Editor' => 'Contribution Editor',
      'Curated Content Editor' => 'Curated Content Editor',
      'Demo Page Editor' => 'Demo Page Editor',
      'Translator' => 'Translator',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_notes'.
  $permissions['edit field_notes'] = array(
    'name' => 'edit field_notes',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Curated Content Editor' => 'Curated Content Editor',
      'Translator' => 'Translator',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_product_categories'.
  $permissions['edit field_product_categories'] = array(
    'name' => 'edit field_product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_source'.
  $permissions['edit field_source'] = array(
    'name' => 'edit field_source',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_duplicate_nid'.
  $permissions['edit own field_duplicate_nid'] = array(
    'name' => 'edit own field_duplicate_nid',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Curated Content Editor' => 'Curated Content Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_needs_work'.
  $permissions['edit own field_needs_work'] = array(
    'name' => 'edit own field_needs_work',
    'roles' => array(
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_notes'.
  $permissions['edit own field_notes'] = array(
    'name' => 'edit own field_notes',
    'roles' => array(
      'Author' => 'Author',
      'Content Admin' => 'Content Admin',
      'Contribution Editor' => 'Contribution Editor',
      'Curated Content Editor' => 'Curated Content Editor',
      'Demo Page Editor' => 'Demo Page Editor',
      'Translator' => 'Translator',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_product_categories'.
  $permissions['edit own field_product_categories'] = array(
    'name' => 'edit own field_product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_source'.
  $permissions['edit own field_source'] = array(
    'name' => 'edit own field_source',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Curated Content Editor' => 'Curated Content Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_duplicate_nid'.
  $permissions['view field_duplicate_nid'] = array(
    'name' => 'view field_duplicate_nid',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'non-authenticated user' => 'non-authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_needs_work'.
  $permissions['view field_needs_work'] = array(
    'name' => 'view field_needs_work',
    'roles' => array(
      'Author' => 'Author',
      'Comment moderator' => 'Comment moderator',
      'Content Admin' => 'Content Admin',
      'Contribution Editor' => 'Contribution Editor',
      'Curated Content Editor' => 'Curated Content Editor',
      'Demo Page Editor' => 'Demo Page Editor',
      'Translator' => 'Translator',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_notes'.
  $permissions['view field_notes'] = array(
    'name' => 'view field_notes',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Contribution Editor' => 'Contribution Editor',
      'Curated Content Editor' => 'Curated Content Editor',
      'Translator' => 'Translator',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_product_categories'.
  $permissions['view field_product_categories'] = array(
    'name' => 'view field_product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_source'.
  $permissions['view field_source'] = array(
    'name' => 'view field_source',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'non-authenticated user' => 'non-authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_duplicate_nid'.
  $permissions['view own field_duplicate_nid'] = array(
    'name' => 'view own field_duplicate_nid',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Curated Content Editor' => 'Curated Content Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_needs_work'.
  $permissions['view own field_needs_work'] = array(
    'name' => 'view own field_needs_work',
    'roles' => array(
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_notes'.
  $permissions['view own field_notes'] = array(
    'name' => 'view own field_notes',
    'roles' => array(
      'Author' => 'Author',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_product_categories'.
  $permissions['view own field_product_categories'] = array(
    'name' => 'view own field_product_categories',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_source'.
  $permissions['view own field_source'] = array(
    'name' => 'view own field_source',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
