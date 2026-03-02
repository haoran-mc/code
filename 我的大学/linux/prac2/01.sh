#!/bin/bash

read -a arr

n=${#arr[@]}
let sum=0

for (( i=0;i<${#arr[*]};i++ ))
do
    let sum=sum+arr[i]
done

let avg=sum/n
let sum=0

for (( i=0;i<${#arr[*]};i++ ))
do
    let diff=arr[i]-avg
    # 平方和
    let sum=sum+diff*diff
done

standard_deviation=$(bc <<< "scale=6; sqrt(${sum}/${n})")

echo "$avg $standard_deviation"
