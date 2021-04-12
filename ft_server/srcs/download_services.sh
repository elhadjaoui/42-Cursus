apt-get install -y nginx curl wget zip  php-fpm php-mysql expect vim
mv default /etc/nginx/sites-available/default
#
## PHPMYADMIN
#
wget  https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-all-languages.zip
unzip phpMyAdmin-5.0.1-all-languages.zip
mkdir /var/www/html/phpmyadmin
mv phpMyAdmin-5.0.1-all-languages/* /var/www/html/phpmyadmin
#
## WORDPRESS
#
wget http://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress /var/www/html/
mv wp-config.php /var/www/html/wordpress/
#
## MYSQL
#
wget https://dev.mysql.com/get/mysql-apt-config_0.8.13-1_all.deb
apt update
dpkg -i mysql-apt-config_0.8.13-1_all.deb << A
1
1
4
A
apt update
expect mysql_install.sh
##
# SSL WITH NGINX
#
mkdir /etc/nginx/ssl
chmod 700 /etc/nginx/ssl
mv rsa.* /etc/nginx/ssl/
apt update