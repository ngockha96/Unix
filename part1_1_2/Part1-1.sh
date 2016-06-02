#!/bin/bash

find_function(){
	find /home/$USER/$1 -name "*$2*"
}

temp=0
while [ $temp -eq 0 ]; do
echo "Which folder do want to find ?"
read u_foldername

if [ -d /home/$USER/"$u_foldername" ]; then
    echo "Type in file name."
    read u_filename
    find_function $u_foldername $u_filename
    temp=1
else
	echo "Your folder is not exist"
fi
done
exit 0
