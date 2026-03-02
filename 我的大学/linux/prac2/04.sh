#!/bin/bash

for (( i=1;i<=9;i++ ))
do
   for (( j=1;j<=9;j++ ))
   do
      [ $j -le $i ] && echo -n "${i}*${j}=$((i*j))      "
   done
   echo ""
done
