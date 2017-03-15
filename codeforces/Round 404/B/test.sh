#!/usr/bin/env sh
g++ code.cpp -o code -Wall
echo "runing test 1"
./code < data1.in
echo "runing test 2"
./code < data2.in