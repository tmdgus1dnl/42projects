FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y nginx openssl tini && \
    apt-get clean

COPY ./conf/openssl.cnf /etc/ssl/openssl.cnf

RUN mkdir -p /etc/ssl/private /etc/ssl/certs && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/server_pkey.pem \
    -out /etc/ssl/certs/server.crt \
    -config /etc/ssl/openssl.cnf

COPY ./conf/default /etc/nginx/sites-available

EXPOSE 443

ENTRYPOINT ["tini", "--"]

CMD ["nginx", "-g", "daemon off;"]
