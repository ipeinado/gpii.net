#!/bin/bash
# echo $1
# exit 0
# cd <profile/version controlled directory>

DRUSH_PATH="/var/www/clients/client2/web3/home/gpiiweb/.composer/vendor/bin/drush"


echo "Starting..."
echo "Grabbing latest info from Git..."
# switch to the right starting directory
cd /var/www/staging.gpii.net/web/sites

git pull


# switch to the right starting directory
cd /var/www/staging.gpii.net/web/sites/saa.gpii.net

echo "backing up staging database"
# dump the current database
$DRUSH_PATH sql-dump --gzip > /var/www/clients/client2/web3/home/gpiiweb/saa-db-stg.sql.gz

echo "syncing database from @saaprod"

# create a backup of the production database
$DRUSH_PATH  @saaprod sql-dump --result-file=/var/www/clients/client4/web5/tmp/saaprod-db.sql

#rsync the file created above so that it is available locally
rsync -e 'ssh ' -akz --remove-source-files gpiiweb@qual-msn-web07.qualtim.local:/var/www/clients/client4/web5/tmp/saaprod-db.sql /var/www/clients/client2/web3/tmp/saaprod-db.sql

# drop the current DB and import the new
$DRUSH_PATH --yes sql-drop
$DRUSH_PATH --yes sql-cli < /var/www/clients/client2/web3/tmp/saaprod-db.sql
# disable CSS/JS aggregation
#$DRUSH_PATH -y config-set system.performance css.preprocess 0

# Turning on maint. mode.
$DRUSH_PATH --yes vset maintenance_mode 1

# disable modules
$DRUSH_PATH --yes dis googleanalytics

# enable modules
$DRUSH_PATH --yes en reroute_email search_api_override patchinfo

# adjust variables
$DRUSH_PATH vset --yes file_private_path '' # set to null to avoid errors in local environments (ex. /var/www/clients/client3/web18/private)

# sync files
echo "syncing files"
$DRUSH_PATH --yes sync-files @saaprod @self

echo "updating database"
# update databse
$DRUSH_PATH --yes updb

echo "clearing cache"
$DRUSH_PATH --yes cc all

echo "done!"

