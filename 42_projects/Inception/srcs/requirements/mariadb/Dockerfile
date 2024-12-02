FROM debian:bullseye

RUN groupadd -g 101 mysql && \
    useradd -u 101 -g mysql -r -s /bin/false mysql && \
    mkdir -p /run/mysqld && \
    chown mysql:mysql /run/mysqld

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y vim && \
    apt-get install -y mariadb-server

COPY ./conf/docker-entrypoint.sh /usr/local/bin/
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN chown mysql:mysql /usr/local/bin/docker-entrypoint.sh

USER mysql

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/docker-entrypoint.sh"]
