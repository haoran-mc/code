#!/bin/bash

function rmTrashFiles ()
{
    for file in `ls $1`
    do
        # 读取文件地址
        # echo $1"/"$file
        # 读取文件的文件名
        # echo `basename $file`
        # echo $file
        read -p "Do you want to delete this file：'${file}' (y/n):" yn
        if [ "${yn}" == "Y" ] || [ "${yn}" == "y" ]; then
            rm $1"/"$file
        fi
    done
}

folder="/home/haoran/.local/share/Trash/files"
rmTrashFiles $folder
