<?php

abstract class TecoMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Add info about who is involved with the migration for Migrate UI
    $this->teamm = array(
      new MigrateTeamMember('Ben Caldwell', 'bcaldwell@pushing7.com', t('Product Owner')),
    );
  }

  // provide a method to connect to the source database for the migration data
  public function getConnnection($connection = 'tecodevspace') {
    return Database::getConnection('default', $connection)
  }
}
