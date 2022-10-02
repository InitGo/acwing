#! /bin/zsh

./dlc bits.c

make clean
make btest

#./btest
#测试某个函数，
./btest -f $1
