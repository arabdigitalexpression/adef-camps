#!/bin/bash

# Load environment variables from .env file
set -a
source /var/www/html/.env
set +a

# Create the settings.php file with database configuration
cp sites/default/default.settings.php sites/default/settings.php
chmod a+w sites/default/settings.php
cat <<EOL >> sites/default/settings.php
\$databases = array(
  'default' => array(
    'default' => array(
      'database' => '${MYSQL_DATABASE}',
      'username' => '${MYSQL_USER}',
      'password' => '${MYSQL_PASSWORD}',
      'host' => '${MYSQL_HOST}',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);
\$drupal_hash_salt = '${HASH_SALT}';
EOL

