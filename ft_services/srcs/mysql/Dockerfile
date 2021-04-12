FROM alpine:3.12
RUN apk update 
RUN apk add openrc mysql mysql-client
RUN apk add telegraf --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/community
RUN mkdir /simo
COPY ./srcs/* /simo/
WORKDIR /simo
EXPOSE 3333
RUN mkdir /run/openrc
RUN mkdir /simo/mysql
RUN chmod 777 healthy.sh 
RUN touch /run/openrc/softlevel
CMD sh Services.sh