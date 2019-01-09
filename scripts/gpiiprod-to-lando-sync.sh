#!/bin/bash
# echo $1
# exit 0
# cd <profile/version controlled directory>

DRUSH_PATH="drush"

echo "Starting..."
echo "Grabbing latest info from Git..."
# switch to the right starting directory
cd ~/code/gpii.net/web

git pull

# switch to the right starting directory
cd ~/code/gpii.net/web/sites/default

echo "backing up production database"
# dump the current database
#lando db-export saa-db-dev.sql.gz 

echo "syncing database from @gpiiprod"

# create a backup of the production database
$DRUSH_PATH @gpiiprod sql-dump --result-file=/var/www/clients/client4/web5/tmp/gpiiprod-db.sql

#rsync the file created above so that it is available locally
rsync -e 'ssh ' -akz --remove-source-files gpiiweb@192.168.123.79:/var/www/clients/client4/web5/tmp/gpiiprod-db.sql /home/ben/code/gpii.net/backups/gpiiprod-db.sql

# # drop the current DB and import the new
lando db-import ../../../backups/gpiiprod-db.sql

echo "Database successfully imported!"

# # disable CSS/JS aggregation
lando drush -y config-set system.performance css.preprocess 0

# # Turning on maint. mode.
# lando drush --yes vset maintenance_mode 1

# # disable modules
lando drush --yes dis googleanalytics

# # enable modules
lando drush --yes en reroute_email search_api_override patchinfo stage_file_proxy

# # adjust variables
# lando drush vset --yes file_private_path '' # set to null to avoid errors in local environments (ex. /var/www/clients/client3/web18/private)

# # sync files
# echo "syncing files"
# lando drush --yes sync-files @gpiiprod @self

# echo "updating database"
# # update databse
# lando drush --yes updb

# echo "clearing cache"
# lando drush --yes cc all

echo "done!"

