FROM alpine:3.12
RUN apk update 
RUN apk add nginx openrc
RUN apk add telegraf --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/community
RUN  apk add php-mbstring php-session php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-fpm
RUN mkdir /simo
COPY ./srcs/* /simo/
WORKDIR /simo
EXPOSE 5050
RUN mkdir /run/openrc
RUN mkdir /run/nginx
RUN mkdir /simo/randomname 
RUN touch /run/openrc/softlevel
RUN chmod 777 healthy.sh 
RUN wget http://wordpress.org/latest.tar.gz
CMD sh Services.sh