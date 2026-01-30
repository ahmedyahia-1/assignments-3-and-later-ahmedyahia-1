#!/bin/bash

filedir=$1
searchstr=$2

if [ -z $filedir ] || [ -z $searchstr ]; then
    echo -e "Usage:\n\t$0 <file_path> <searched_text>"
    exit 1
fi

if ! [ -d $filedir ]; then
    echo "Error, $d is not a directory"
    exit 1
fi

file_num=$(find $filedir -type f | wc -l)
match_num=$(grep -r $searchstr $filedir 2> /dev/null | wc -l)

echo "The number of files are $file_num and the number of matching lines are $match_num"
