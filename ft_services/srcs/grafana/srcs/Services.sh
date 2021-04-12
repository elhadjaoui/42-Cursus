mv healthy.sh grafana
telegraf --config telegraf.conf&
./bin/grafana-server
tail -f /dev/null
