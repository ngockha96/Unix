#!/bin/bash

gcc client.c -o client.o `mysql_config --cflags --libs` 

echo "How many client?"
read answer
echo "Connect to which IP"
read IP
for (( i = 0; i < $answer; i++ )); do
	echo "Enter name"
	read name
	gnome-terminal -e "bash -c './client.o -s $IP:5000 -p $i -n $name;exec $SHELL'"
done