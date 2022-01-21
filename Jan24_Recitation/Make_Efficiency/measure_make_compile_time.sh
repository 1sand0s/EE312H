#!/bin/bash

echo "Make"
for ((i=0;i<5;i++));
do
	rm main.o log
	touch -d "1 hour ago" $1
	/bin/time -f %U make 2>> $2
done
