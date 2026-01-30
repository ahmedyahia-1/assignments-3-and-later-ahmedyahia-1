#!/bin/bash

writefile=$1
writestr=$2

if [ -z $writefile ] || [ -z $writestr ]; then
    echo -e "Usage:\n\t$0 <file_path> <written_text>"
    exit 1
fi

writefile_dir=$(dirname $writefile)

mkdir -p $writefile_dir

echo $writestr > $writefile

if [ $? != 0 ]; then
    echo "Error writing to file $writefile"
    exit 1
fi