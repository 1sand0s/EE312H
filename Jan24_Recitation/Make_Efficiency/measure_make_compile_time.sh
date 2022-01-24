#!/bin/bash

echo "Make"

#Repeat procedure 5 times for averaging to remove noise
for ((i=0;i<5;i++));
do
	rm main.o log

	#Change date modified to force rebuild
	touch -d "1 hour ago" $1

	#Invoke make to rebuild executable and measure build time
	/bin/time -f %U make 2>> $2
done
