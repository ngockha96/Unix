#!/bin/bash
echo "How many client?"
read answer
for (( i = 0; i < $answer; i++ )); do
	echo "Enter name"
	read name
	gnome-terminal -e "bash -c './client.o -s 127.0.0.1:5000 -p $i -n $name;exec $SHELL'"
done