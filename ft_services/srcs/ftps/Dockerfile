FROM alpine:3.12.1
RUN apk update 
RUN apk add openrc  vsftpd
RUN adduser -D lorus
RUN echo 'lorus:123' | chpasswd
RUN mkdir /home/lorus/ftp
RUN chmod -R 774 /home/lorus/ftp

RUN apk add telegraf --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/community
RUN mkdir /simo
COPY ./srcs/* /simo/
WORKDIR /simo
RUN mkdir /run/openrc
RUN mkdir /simo/ftps
RUN touch /run/openrc/softlevel
RUN chmod 777 Services.sh
RUN chmod 777 healthy.sh 
EXPOSE 21
EXPOSE  50110
CMD sh Services.sh