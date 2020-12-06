chown -R mysql:mysql /var/lib/mysql/
service php7.3-fpm start
service mysql start
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY 'root';"
mysql -u root -proot -e "CREATE DATABASE WORD;"
mysql -u root -proot WORD < localhost.sql
nginx -g 'daemon off;'
service nginx restart