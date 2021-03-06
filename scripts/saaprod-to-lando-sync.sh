#!/bin/bash
# echo $1
# exit 0
# cd <profile/version controlled directory>

echo "Starting..."
echo "Grabbing latest info from Git..."
# switch to the right starting directory
cd ~/code/gpii.net/web

git pull

# switch to the right starting directory
cd ~/code/gpii.net/web/sites/saa.gpii.net

echo "backing up production database"
# dump the current database
# lando db-export saa-db-dev.sql.gz

echo "syncing database from @saaprod"

# create a backup of the production database
lando drush @saaprod sql-dump --result-file=/var/www/clients/client4/web5/tmp/saaprod-db.sql

#rsync the file created above so that it is available locally
rsync -e 'ssh ' -akz --remove-source-files gpiiweb@192.168.123.79:/var/www/clients/client4/web5/tmp/saaprod-db.sql ~/code/gpii.net/backups/saaprod-db.sql

# # drop the current DB and import the new
lando db-import ../../../backups/saaprod-db.sql --host database2

echo "Database successfully imported!"

## disable CSS/JS aggregation
lando drush -y vset preprocess_css 0


## disable modules
lando drush --yes dis googleanalytics

## enable modules
lando drush --yes en reroute_email search_api_override patchinfo stage_file_proxy devel admin_devel ds_devel

// Set the origin, or where the files live, the production site
lando drush variable-set stage_file_proxy_origin "https://ul.gpii.net"

echo "updating database"
# update databse
lando drush --yes updb


echo "done!"

