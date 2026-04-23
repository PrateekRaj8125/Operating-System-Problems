# Write a shell script to input two numbers and display their sum.

#!/bin/bash
echo "Enter First No.:"
read a -r
echo "Enter Second No.:"
read b -r
sum=$(($a+$b))
echo "Sum = $sum"