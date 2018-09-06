<?php

// GPII Main Site

$aliases['gpiiprod'] = array(
  'uri' => 'gpii.net',
  'root' => '/var/www/clients/client4/web5/web',
  'remote-host' => '192.168.123.79',
  'remote-user' => 'gpiiweb',
  'path-aliases' => array(
    '%dump' => '/var/www/clients/client4/web5/tmp/dump.sql',
    '%dump-dir' => '/var/www/clients/client4/web5/tmp',
    '%files' => 'sites/gpii.net/files',
  ),
  // Read only - force the sql-sync & rsync to simulate transfer to this server
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '1',
    ),
    'rsync' => array (
      'simulate' => '1',
    ),
  ),
);

$aliases['gpiistaging'] = array(
  'uri' => 'staging.gpii.net',
  'root' => '/var/www/clients/client2/web3/web',
  'remote-host' => 'qual-msn-stg07.qualtim.local',
  'remote-user' => 'gpiiweb',
  'path-aliases' => array(
    '%dump' => '/var/www/clients/client2/web3/tmp/dump.sql',
    '%dump-dir' => '/var/www/clients/client2/web3/tmp',
    '%files' => 'sites/gpii.net/files',
  ),
);

$aliases['gpiidev'] = array(
  'uri' => 'dev.gpii.net',
  'root' => '/var/www/developerspace.gpii.net',
  'remote-host' => '127.0.0.1',
  'remote-user' => 'caldwell',
  'path-aliases' => array(
    '%dump' => '/tmp/dump.sql',
    '%dump-dir' => '/tmp',
    '%files' => 'sites/gpii.net/files'
  ),
);

// DeveloperSpace

$aliases['devspaceprod'] = array(
  'uri' => 'developerspace.gpii.net',
  'root' => '/var/www/clients/client1/web17/web',
  'remote-host' => 'web06.pushing7.com',
  'remote-user' => 'rtfwebdevspace',
  'path-aliases' => array(
    '%dump' => '/var/www/clients/client1/web17/tmp/dump.sql',
    '%dump-dir' => '/var/www/clients/client1/web17/tmp',
    '%files' => 'sites/developerspace.gpii.net/files',
  ),
  // Read only - force the sql-sync & rsync to simulate transfer to this server
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '1',
    ),
    'rsync' => array (
      'simulate' => '1',
    ),
  ),
);

$aliases['devspacestaging'] = array(
  'uri' => 'staging.developerspace.gpii.net',
  'root' => '/var/www/clients/client2/web3/web',
  'remote-host' => 'qual-msn-stg07.qualtim.local',
  'remote-user' => 'gpiiweb',
  'path-aliases' => array(
    '%dump' => '/var/www/clients/client2/web3/tmp/dump.sql',
    '%dump-dir' => '/var/www/clients/client2/web3/tmp',
    '%files' => 'sites/developerspace.gpii.net/files',
  ),
);

$aliases['devspacedev'] = array(
  'uri' => 'dev.developerspace.gpii.net',
  'root' => '/var/www/developerspace.gpii.net',
  'remote-host' => '127.0.0.1',
  'remote-user' => 'caldwell',
  'path-aliases' => array(
    '%dump' => '/tmp/dump.sql',
    '%dump-dir' => '/tmp',
    '%files' => 'sites/developerspace.gpii.net/files',
  ),
);

// SAA

$aliases['saaprod'] = array(
  'uri' => 'ul.gpii.net',
  'root' => '/var/www/clients/client4/web5/web',
  'remote-host' => '192.168.123.79',
  'remote-user' => 'gpiiweb',
  'path-aliases' => array(
    '%dump' => '/var/www/clients/client4/web5/tmp/dump.sql',
    '%dump-dir' => '/var/www/clients/client4/web5/tmp',
    '%files' => 'sites/saa.gpii.net/files',
  ),
  // Read only - force the sql-sync & rsync to simulate transfer to this server
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '1',
    ),
    'rsync' => array (
      'simulate' => '1',
    ),
  ),
);

$aliases['saastaging'] = array(
  'uri' => 'staging.saa.gpii.net',
  'root' => '/var/www/clients/client2/web3/web',
  'remote-host' => 'qual-msn-stg07.qualtim.local',
  'remote-user' => 'gpiiweb',
  'path-aliases' => array(
    '%dump' => '/tmp/dump.sql',
    '%dump-dir' => '/tmp',
    '%files' => 'sites/saa.gpii.net/files',
  ),
);

$aliases['saadev'] = array(
  'uri' => 'dev.saa.gpii.net',
  'root' => '/var/www/dev.gpii.net',
  'remote-host' => '127.0.0.1',
  'remote-user' => 'caldwell',
  'path-aliases' => array(
    '%dump' => '/tmp/dump.sql',
    '%dump-dir' => '/tmp',
    '%files' => 'sites/saa.gpii.net/files',
  ),
   // Read only - force the sql-sync & rsync to simulate transfer to this server
  'command-specific' => array (
    'sql-sync' => array (
      'simulate' => '0',
    ),
    'rsync' => array (
      'simulate' => '0',
    ),
  ),
);
