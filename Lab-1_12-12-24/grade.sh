#!/bin/bash
echo"Enter the Percentage:"
read p -r
if[$p -ge 90]
then
echo "Grade A"
elif[$p -ge 80]
then
echo "Grade B"
elif[$p -ge 70]
then
echo "Grade C"
elif[$p -ge 60]
then
echo "Grade D"
else
echo "Grade F"
fi