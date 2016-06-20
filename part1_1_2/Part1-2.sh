#!/bin/bash

u_foldername=$1
u_keyword=$2

grepfile_function() {
	grep -n $2 /home/$USER/$1/$3
}

if [ -d /home/$USER/"$u_foldername" ]; then

	grep -r -e $u_keyword "/home/$USER/"$u_foldername

else
	echo "Your folder is not exist"
fi