pgrep nginx 

if [ $? -ne 0 ]
then
    exit 1
fi 

pgrep telegraf  

if [ $? -ne 0 ]
then
    exit 1
fi 

pgrep php-fpm  

if [ $? -ne 0 ]
then
    exit 1
fi 

