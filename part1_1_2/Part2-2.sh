#!/bin/bash

path=$1
given=$2

files=(/home/$USER/$path/*)
size=()

for (( i=0; i<${#files[@]}; i++ )); do
  
size[$i]=$(stat -c%s "${files[$i]}");


if [[ ${size[i]} -lt $given ]];
  then 
    echo "${files[i]} ----- ${size[i]}"

fi

done
