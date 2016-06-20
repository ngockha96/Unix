#!/bin/bash

u_foldername=$1
u_keyword=$2

find_function(){
	find /home/$USER/$u_foldername -name "*$u_keyword*"
}

if [ -d /home/$USER/"$u_foldername" ]; then
   
    find_function 
    temp=1
else
	echo "Your folder is not exist"
fi

exit 0
