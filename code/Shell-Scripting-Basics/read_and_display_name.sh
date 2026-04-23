# Write a shell script to accept a user's name as input and display it.

#!/bin/bash
echo "Enter your name:"
read reply -r
echo "Name: $reply"