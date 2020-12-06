FROM debian:buster
RUN  apt update
RUN  apt install -y lsb-release
RUN  apt install -y gnupg
RUN  mkdir /root/simo/
COPY  ./srcs/* /root/simo/
WORKDIR /root/simo
EXPOSE 80 443
RUN  bash download_services.sh
CMD bash run_services.sh