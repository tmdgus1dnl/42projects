FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install \
    mariadb-client \
    php7.4 \
    php-fpm \
    php-cli \
    wget \
    curl \
    php-mysql \
    php-mbstring \
    php-xml \
    sendmail

RUN mkdir -p /var/www/html && \
    chown -R www-data:www-data /var/www/html && \
    wget https://wordpress.org/latest.tar.gz && \
    tar -xvf latest.tar.gz && \
    mv wordpress/* /var/www/html/ && \
    chown -R www-data:www-data /var/www/html
    rm -rf wordpress latest.tar.gz

ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_HOST

RUN mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php && \
    mkdir -p /run/php && chown -R www-data:www-data /run/php && \
    sed -i 's/^pid =.*/pid = \/run\/php\/php7.4-fpm.pid/' /etc/php/7.4/fpm/php-fpm.conf && \
    sed -i "s/database_name_here/${MYSQL_DATABASE}/" /var/www/html/wp-config.php && \
    sed -i "s/username_here/${MYSQL_USER}/" /var/www/html/wp-config.php && \
    sed -i "s/password_here/${MYSQL_PASSWORD}/" /var/www/html/wp-config.php && \
    sed -i "s/localhost/${MYSQL_HOST}/" /var/www/html/wp-config.php && \
    sed -i "s/^listen = .*/listen = 0.0.0.0:9000/" /etc/php/7.4/fpm/pool.d/www.conf && \
    sed -i "s/;clear_env = yes/clear_env = no/" /etc/php/7.4/fpm/pool.d/www.conf

EXPOSE 9000

ENTRYPOINT ["php-fpm7.4", "--nodaemonize"]
