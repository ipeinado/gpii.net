#/bin/sh
for i in `seq 1 10`; do
USER=test$i
PASS=test$i
lando drush -l ul.gpii.net user-create $USER --mail=$USER@example.com --password=$PASS
lando drush -l ul.gpii.net user-add-role "Tester" $USER
echo $USER,$PASS >>passes.csv
done
ch