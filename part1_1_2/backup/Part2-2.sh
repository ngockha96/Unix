#!/bin/bash

u_foldername=$1
u_file_size=$2

find_bysize_function(){
		if [[ ! $(  find /home/$USER/"$1" -type f -size -"$2""$3" ) ]]; then
			echo "No Such File."		
		else
			find /home/$USER/"$1" -type f -size -"$2""$3" -ls
		fi
}

if [ -d /home/$USER/"$u_foldername" ]; then
    
    find_bysize_function $u_foldername $u_file_size "k"
else
	echo "Your folder does not exist"
fi

exit 0
