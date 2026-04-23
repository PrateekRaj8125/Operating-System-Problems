# Write a shell script to find the greatest among three numbers entered by the user using conditional statements.

#!/bin/bash
echo "Enter 1st No.:"
read n1 -r
echo "Enter 2nd No.:"
read n2 -r
echo "Enter 3rd No.:"
read n3 -r
if ((n1>n2&&n1>n3))
then
echo "$n1 is greatest no."
elif ((n2>n3))
then
echo "$n2 is graetest no."
else
echo "$n3 is graetest no."
fi
fi