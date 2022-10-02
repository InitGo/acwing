#! /bin/zsh

:<<EOF
This is some notice
hahaha
EOF

readonly const1=constVar
declare -r const2=1

name=zqw
name1="zqw1"
name2='zqw2'
name3=zqw3
unset name3

echo $name
echo ${name1}hello
echo "${name2}abc"
echo "-------------"

#./a.sh 1 4 5 6
echo "文件名："$0
echo "第一个参数："$1
echo "第二个参数："$2
echo "第三个参数："$3
echo "第四个参数："$4
echo "返回参数个数: $#"
echo "参数列表：$*"

echo "-------------"

lst=(1 abc "def" yxc)
arr=(1 abc "def" yxc)
# arr[0]=10
# arr[1]=abc
# arr[2]="def"
# arr[3]=yxc

echo ${lst[@]}
echo ${arr[*]}  # 第二种写法
echo "arr数组长度：${#arr}"

echo "-------------"

str="Hello world!"
echo $(expr length "$str") #$(command)返回command这条命令的stdout