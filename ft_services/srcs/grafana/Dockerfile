FROM alpine:3.12
RUN apk update 
RUN apk add openrc
RUN apk add libc6-compat
RUN apk add telegraf --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/community
RUN mkdir /simo
COPY ./srcs/* /simo/
WORKDIR /simo
RUN mkdir /run/openrc
RUN mkdir /simo/grafana
RUN chmod 777 healthy.sh 
RUN touch /run/openrc/softlevel
EXPOSE 3000
CMD sh Services.sh