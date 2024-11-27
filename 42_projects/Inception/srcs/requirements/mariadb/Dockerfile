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

COPY ./conf/init.sh /docker-entrypoint-initdb.d/

RUN chmod +x /docker-entrypoint-initdb.d/init.sh && \
    chmod +x /usr/local/bin/docker-entrypoint.sh

EXPOSE 3306

USER mysql

#ENTRYPOINT ["bash", "-c", " tail -f /dev/null"]

ENTRYPOINT ["bash", "/usr/local/bin/docker-entrypoint.sh"]

CMD ["mysqld_safe"]
