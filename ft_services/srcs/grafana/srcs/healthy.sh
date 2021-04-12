pgrep telegraf  

if [ $? -ne 0 ]
then
    exit 1
fi 

pgrep grafana   

if [ $? -ne 0 ]
then
    exit 1
fi 

