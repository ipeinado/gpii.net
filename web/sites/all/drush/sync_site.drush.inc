<?php
/**
 * @file
 * Site Sync Drush integration - refresh the local dev.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 */
function sync_site_drush_command() {
  return array(
    'sync-site' => array(
      'callback' => 'sync_site_full',
      'description' => dt('Refresh your local db and reset for development.'),
      'arguments' => array(
        'alias' => dt('Optional. The environment alias to pull the data from. Defaults to @prod.'),
      ),
    ),
    'sync-db' => array(
      'callback' => 'sync_site_db',
      'description' => dt('Refresh your local db and reset for development.'),
      'drush dependencies' => array('sql'),
      'arguments' => array(
        'alias' => dt('Optional. The environment alias to pull the data from. Defaults to @prod.'),
      ),
    ),
    'sync-files' => array(
      'callback' => 'sync_site_files',
      'description' => dt('Refresh your local db and reset for development.'),
      'drush dependencies' => array('core'),
      'arguments' => array(
        'alias' => dt('Optional. The environment alias to pull the data from. Defaults to @prod.'),
      ),
    ),
  );
}

/**
 * Run a series of drush commands to reset local dev
 */
function sync_site_full() {
  drush_log('*****************************************************************', 'ok');
  drush_log('*** Refreshing local DB and files - it begins...              ***', 'ok');
  drush_log('*****************************************************************', 'ok');
  drush_log(' ', 'ok');
  $alias = '@prod';
  // Get the alias argument
  if ($args = func_get_args()) {
    $alias = $args[0];
  }
  // Sync the DB
  sync_site_db($alias);
  // Run the golocal
  go_local_dev();
}

/**
 * Update the local DB from production
 */
function sync_site_db($alias = '@prod') {
  // Include required files
  require_once DRUSH_BASE_PATH . '/commands/sql/sync.sql.inc';
  // Set options
  drush_set_option('structure-tables-key', 'common+springboard');
  drush_set_option('skip-tables-key', 'common');
  drush_set_option('cache', TRUE);
  // @TODO: make this work    drush_set_option('sanitize', TRUE);
  // Initiate the sync
  drush_log('*** Starting DB sync from ' . $alias . ' to local*** ', 'ok');
  drush_sql_sync($alias, '@self');
  drush_log('*** DB sync complete *** ', 'ok');
}

/**
 * Update the local files from production
 */
function sync_site_files($alias = '@prod') {
  // Include required files
  require_once DRUSH_BASE_PATH . '/commands/core/rsync.core.inc';
  // Set options
  $options = array (
    'delete' => TRUE,
    'exclude' => '*.js:*.css:*.pdf:*.zip',
    'progress' => TRUE,
    'stats' => TRUE,
    'mode' => 'arhzO',
  );
  // Call drush rsync
  drush_log('*** Starting File sync from  ' . $alias . '  to local *** ', 'ok');
  drush_core_rsync($alias . ':%files', '@self:%files', $options);
  drush_log('*** File sync complete *** ', 'ok');
}
