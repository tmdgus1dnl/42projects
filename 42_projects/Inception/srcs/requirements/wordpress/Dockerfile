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
    sendmail \
    tini && \
    apt-get clean

COPY ./conf/docker-entrypoint.sh /

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xvf latest.tar.gz && \
    mv /wordpress/wp-config-sample.php /wordpress/wp-config.php && \
    chown -R www-data:www-data /wordpress && \
    chmod +x /docker-entrypoint.sh && \
    mkdir -p /var/www/html && \
    mkdir -p /run/php && chown -R www-data:www-data /run/php && \
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

EXPOSE 9000

ENTRYPOINT ["tini", "--"]

CMD ["/docker-entrypoint.sh"]
