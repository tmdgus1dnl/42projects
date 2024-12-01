#!/bin/bash
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/* /var/www/html
chown -R www-data:www-data /var/www/html
mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
rm -rf wordpress latest.tar.gz
mkdir -p /run/php && chown -R www-data:www-data /run/php
sed -i 's/^pid =.*/pid = \/run\/php\/php7.4-fpm.pid/' /etc/php/7.4/fpm/php-fpm.conf
sed -i "s/database_name_here/${MYSQL_DATABASE}/" /var/www/html/wp-config.php
sed -i "s/username_here/${MYSQL_USER}/" /var/www/html/wp-config.php
sed -i "s/password_here/${MYSQL_PASSWORD}/" /var/www/html/wp-config.php
sed -i "s/localhost/${MYSQL_HOST}/" /var/www/html/wp-config.php
sed -i "s/^listen = .*/listen = 0.0.0.0:9000/" /etc/php/7.4/fpm/pool.d/www.conf
sed -i "s/;clear_env = no/clear_env = no/" /etc/php/7.4/fpm/pool.d/www.conf

#/usr/local/bin/wp config create --path=/var/www/html --allow-root \
#--dbname=$MYSQL_DATABASE \
#--dbuser=$MYSQL_USER \
#--dbpass=$MYSQL_USER_PASSWORD \
#--dbhost=$MYSQL_HOST --skip-check
/usr/local/bin/wp core install --path=/var/www/html --allow-root \
--url=$WP_URL \
--title=$WP_TITLE \
--admin_user=$WP_ADMIN \
--admin_password=$WP_ADMIN_PASSWORD \
--admin_email=$WP_ADMIN_EMAIL
/usr/local/bin/wp user create --path=/var/www/html --allow-root $WP_USER $WP_USER_EMAIL \
--user_pass=$WP_USER_PASSWORD \
--role=author

exec php-fpm7.4 --nodaemonize
