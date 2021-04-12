mv default.conf /etc/nginx/conf.d
mv healthy.sh phpmyadmin
mkdir -p /var/www/html/phpmyadmin
tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
rm phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages/*   /var/www/html/phpmyadmin
rc-status
rm  /var/www/html/phpmyadmin/config.sample.inc.php   
mv  config.inc.php  /var/www/html/phpmyadmin/
service php-fpm7 start
service nginx start
telegraf --config telegraf.conf&
tail -f /dev/null