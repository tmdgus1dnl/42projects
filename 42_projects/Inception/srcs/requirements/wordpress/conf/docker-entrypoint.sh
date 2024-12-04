#!/bin/bash
mv wordpress/* /var/www/html
chown -R www-data:www-data /var/www/html
rm -rf wordpress latest.tar.gz
sed -i 's/^pid =.*/pid = \/run\/php\/php7.4-fpm.pid/' /etc/php/7.4/fpm/php-fpm.conf
sed -i "s/database_name_here/${MYSQL_DATABASE}/" /var/www/html/wp-config.php
sed -i "s/username_here/${MYSQL_USER}/" /var/www/html/wp-config.php
sed -i "s/password_here/${MYSQL_USER_PASSWORD}/" /var/www/html/wp-config.php
sed -i "s/localhost/${MYSQL_HOST}/" /var/www/html/wp-config.php
sed -i "s/^listen = .*/listen = 0.0.0.0:9000/" /etc/php/7.4/fpm/pool.d/www.conf
sed -i "s/;clear_env = no/clear_env = no/" /etc/php/7.4/fpm/pool.d/www.conf

sleep 2
until mysqladmin ping -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_USER_PASSWORD" --silent; do
    echo "Waiting for database connection..."
    sleep 2
done

if ! echo 'SHOW TABLES;' | mysql -h"$MYSQL_HOST" -u"$MYSQL_USER" \
-p"$MYSQL_USER_PASSWORD" "$MYSQL_DATABASE" | grep -q 'wp_options'; then
    echo "No WordPress tables found. Initializing WordPress setup..."
    /usr/local/bin/wp core install --url="$WP_URL" \
    --title="$WP_TITLE" \
    --admin_user="$WP_ADMIN" \
    --admin_password="$WP_ADMIN_PASSWORD" \
    --admin_email="$WP_ADMIN_EMAIL" --path=/var/www/html --allow-root
    /usr/local/bin/wp user create $WP_USER $WP_USER_EMAIL \
    --user_pass=$WP_USER_PASSWORD \
    --role=author --path=/var/www/html --allow-root
else
    echo "WordPress tables already exist. Skipping setup."
fi

exec php-fpm7.4 --nodaemonize
