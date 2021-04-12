apk update
rc-status
mv default.conf /etc/nginx/conf.d
mv healthy.sh randomname
tar -xvf latest.tar.gz
mv wordpress /var/www/html/
mv wp-config.php  /var/www/html/
service php-fpm7 start
service nginx start
telegraf --config telegraf.conf&
apk update
service nginx restart
tail -f /dev/null
