#!/usr/bin/expect -f
set timeout -1
spawn apt install -y mysql-server
expect "Enter root password:"
send -- "root\r"
expect "Re-enter root password:"
send -- "root\r"
expect eof