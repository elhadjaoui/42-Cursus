FROM alpine:3.12
RUN apk update 
RUN apk add  influxdb  openrc
RUN apk add telegraf --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/community
RUN mkdir /simo
COPY ./srcs/* /simo/
WORKDIR /simo
RUN mkdir /run/openrc
RUN mkdir /simo/influxdb 
RUN touch /run/openrc/softlevel
EXPOSE 8086
RUN chmod 777 Services.sh
RUN chmod 777 healthy.sh 
CMD sh Services.sh
