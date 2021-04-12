mv healthy.sh influxdb 
influxd &
telegraf --config telegraf.conf&
influx -execute "CREATE USER lorus WITH PASSWORD '123456' WITH ALL PRIVILEGES"
tail -f /dev/null