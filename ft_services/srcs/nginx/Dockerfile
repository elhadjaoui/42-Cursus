FROM alpine:3.12
RUN apk update 
RUN apk add nginx openrc openssh 
RUN adduser -D lorus
RUN echo 'lorus:123' | chpasswd
RUN apk add telegraf --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/community
RUN mkdir /simo
COPY ./srcs/* /simo/
WORKDIR /simo
EXPOSE 80 443 22
RUN mkdir /run/openrc
RUN mkdir /simo/nginx 
RUN mkdir /run/nginx
RUN chmod 777 healthy.sh 
RUN touch /run/openrc/softlevel
CMD sh Services.sh
