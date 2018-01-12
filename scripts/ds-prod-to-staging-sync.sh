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
cd /var/www/staging.gpii.net/web/sites/developerspace.gpii.net

echo "backing up staging database"
# dump the current database
$DRUSH_PATH sql-dump --gzip > /var/www/clients/client2/web3/home/gpiiweb/devspace-db-stg.sql.gz

echo "syncing database from @devspaceprod"

# create a backup of the production database
$DRUSH_PATH  @devspaceprod sql-dump --result-file=/var/www/clients/client4/web5/tmp/devspaceprod-db.sql

#rsync the file created above so that it is available locally
rsync -e 'ssh ' -akz --remove-source-files gpiiweb@qual-msn-web07.qualtim.local:/var/www/clients/client4/web5/tmp/devspaceprod-db.sql /var/www/clients/client2/web3/tmp/devspaceprod-db.sql 

# drop the current DB and import the new
$DRUSH_PATH --yes sql-drop
$DRUSH_PATH --yes sql-cli < /var/www/clients/client2/web3/tmp/devspaceprod-db.sql 
# disable CSS/JS aggregation
#$DRUSH_PATH -y config-set system.performance css.preprocess 0

# disable modules
$DRUSH_PATH --yes dis google_analytics

# enable modules
$DRUSH_PATH --yes en reroute_email search_api_override patchinfo

# adjust variables
$DRUSH_PATH vset --yes file_private_path '' # set to null to avoid errors in local environments (ex. /var/www/clients/client3/web18/private)

# sync files
echo "syncing files"
$DRUSH_PATH --yes sync-files @devspaceprod @self

echo "updating database"
# update databse
$DRUSH_PATH --yes updb

echo "clearing cache"
$DRUSH_PATH --yes cc all

echo "done!"

