#!/bin/bash

read -p "the first number: " num1
read -p "the second numberi: " num2

total=$(($num1 + $num2))
echo "the total number of $num1 and $num2 is $total"
