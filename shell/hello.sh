#!/bin/bash
echo Hello world!
# cd ../
ls -l

HELLO="hello"
echo "HELLO" = $HELLO

unset HELLO
echo "HELLO" = $HELLO

# TBD: What does 'dirname $0' work?
CUR_PATH=$(cd `dirname $0`;pwd)
touch $CUR_PATH/demo.txt

var=45
echo $[var + 1]
echo $((var + 2))

# TBD: How to use it?
echo $[8#10 + 11]

var="a b"
touch $var
touch "$var"
