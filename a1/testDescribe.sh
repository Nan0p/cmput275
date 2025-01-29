#!/bin/bash

#Telling user that 1 file must be inputed
if [ "$#" -ne 1 ]; then
  echo "Usage: ./testDescribe.sh testSetFile" >&2
  exit 1

fi

#Looping throught the file and making each line an array for each item seperated by white space
while read -r -a stems; do
  #Looping through the array and dispaying contents
  for stem in "${stems[@]}"; do 
    if [ -f "${stem}.desc" ]; then
      cat "${stem}.desc"
  
    else
      echo "$stem No test description"
    fi
  done
done < "$1"

exit 0

