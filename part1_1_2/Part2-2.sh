#!/bin/bash

find_bysize_function(){
		if [[ ! $(  find /home/$USER/"$1" -type f -size -"$2""$3" ) ]]; then
			echo "No such file."		
		else
			find /home/$USER/"$1" -type f -size -"$2""$3" -ls
		fi
}

temp=0
while [ $temp -eq 0 ]; do
echo "Which folder do want to find ?"
read u_foldername

if [ -d /home/$USER/"$u_foldername" ]; then
    echo "Decided file size parameter."
    echo "1.Byte"
    echo "2.KiloByte"
    echo "3.MegaByte"
    read u_ans
    u_params="c"
    case $u_ans in
    	1) u_params="c"
    		;;
    	2) u_params="k"
    		;;
    	3) u_params="M"
    		;;
    	*)
			echo "Wrong input"
			exit 1
    		;;
    esac

    echo "Decided file size."
    read u_file_size
    find_bysize_function $u_foldername $u_file_size $u_params
    else
	echo "Your folder is not exist"
fi
done
exit 0
