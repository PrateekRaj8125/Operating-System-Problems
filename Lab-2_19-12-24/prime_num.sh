#!/bin/bash
for(( i=1; i<=100; i++))
do
if [ $i -lt 2 ]
then
 continue
fi
is_prime=1
for((j=2; j*j<=i; j++))
do
if [$((i%j)) -eq 0]
then
 is_prime=0
 break
fi
done
if [ $is_prime -eq 1 ]
then
 echo "$i is a prime number"
fi
done