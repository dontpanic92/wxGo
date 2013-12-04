#!/bin/bash
###the script use to delete comment

if [ -z "$1" ];then                  #检测是否输入了源文件
     echo "ipput the source file"
     exit 1
fi

postfix=`echo $1 |cut -f 2 -d '.'`   #取文件的后缀，以便根据不同的文件进行不同的处理

if [ -n "$2" ];then                  #存放处理源文件产生的信息的文件 
     target_file=$2                  #如果给出了就直接调用 
     touch ${target_file}
else
prefix=`echo $1|cut -f 1 -d '.' ` #如果没有给出的话则生成一个和源文件名字一样，但后缀为temp的文件
     target_file=${prefix}.temp
     touch ${target_file}
fi

case $postfix in
          sh ) 
              echo "it is shell script !"
              sed 's/[[:space:]]#.*//g' $1 |sed '/^#/d'|\
              sed '/^[[:space:]]*$/d' | sed '/^$/d' >${target_file}
              echo "the source file is $1,target file is ${target_file}"
              ;;
       c|java|h )
              echo "c  or java program"
              sed 's/\/\*.*\*\///g' $1|sed '/\/\*/,/.*\*\//d' |\
              sed 's/\/\/.*//g' |\
              sed '/^[[:space:]]*$/d' |sed '/^$/d' >${target_file}
              echo "the source file is $1,target file is ${target_file}"
              ;;
        *)
              echo "unknown file type !"
              rm -f ${target_file}
              ;;
esac
