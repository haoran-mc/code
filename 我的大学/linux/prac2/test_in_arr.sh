#!/bin/bash
declare -ai num

read -p "Please input some numbers: " -a num

declare -i len=${#num[*]}
declare -i sum=0

for (( i=1; i<$len; i++ ))
do
    let sum=sum+num[i]
done

echo "$sum, $len"
echo "scale=2; $sum/$len" | bc
