#!/bin/bash

#Telling user that 2 files must be inputed
if [ $# -ne 2 ]; then
  echo "Usage: $0 commandToTest testSetFile" >&2
  exit 1
fi

commandToTest="$1"
testSetFile="$2"

#Looping through the file 
while read -r stem; do

  #Removing empty lines
  if [ -z "$stem" ]; then
    continue
  fi

  tempOutput=$(mktemp)
  $commandToTest < "${stem}.in" > "$tempOutput"

  #Comparing outputs
  diff "$tempOutput" "${stem}.out" > /dev/null
  if [ $? -eq 0 ]; then
    echo "Test $stem passed"

  else
    echo "Test $stem failed"
    echo "Expected output:"
    cat "${stem}.out"
    echo "Actual output:"
    cat "$tempOutput"
  
  fi

  #Garbage removal
  rm -f "$tempOutput"
done < "$testSetFile"
