FROM debian:bullseye

RUN apt-get update && \
apt-get install -y nginx && \
apt-get clean

COPY ./default.conf /etc/nginx/conf.d/default.conf

EXPOSE 80

 CMD ["nginx", "-g", "daemon off;"]
