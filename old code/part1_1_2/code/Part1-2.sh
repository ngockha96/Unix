#!/bin/bash

grepfile_function() {
	grep -n $2 /home/$USER/$1/$3
}

echo "Which folder do want to find ?"
read u_foldername
	if [ -d /home/$USER/"$u_foldername" ]; then
    	echo "Do you want to search in folder or in file (1/2)."
    	read ans
    	if [ $ans -eq 1 ]; then
    		echo "Enter your keyword."
    		read u_keyword
    		grep -r -e $u_keyword "/home/$USER/"$u_foldername
    		echo "Do you want to search more (Y/N)"
    		read u_ans
    		u_ans = $temp
    	else
    		echo  "Enter your filename."
    		read u_filename
			if [ -e /home/$USER/"$u_foldername"/"$u_filename" ]; then
				echo "Enter your keyword."
				read u_keyword
				grepfile_function $u_foldername $u_keyword $u_filename
				echo "Do you want to search more (Y/N)"
    			read u_ans
    			$u_ans = $temp
			else
			echo "Incorrect filename"
			fi
		fi
   
	else
	echo "Your folder is not exist"
fi
exit 0
