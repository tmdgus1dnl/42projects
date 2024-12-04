#!/bin/bash
mysqld_safe &
sleep 1
if ! mysql -h localhost -e "USE ${MYSQL_DATABASE};" 2>/dev/null; then
    echo "No WordPress Database found. Creating WordPress DB and USER..."
    mysql -h localhost <<-EOSQL
        ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
        CREATE DATABASE ${MYSQL_DATABASE};
        CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';
        GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
        FLUSH PRIVILEGES;
EOSQL
else
    echo "WordPress Database already exist. Skipping setup."
fi

mysqladmin -h localhost shutdown
mysqld_safe
