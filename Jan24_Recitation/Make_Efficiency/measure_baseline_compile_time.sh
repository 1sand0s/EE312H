#!/bin/bash

echo "Baseline"

#Repeat procedure  times for averaging to remove noise
for ((i=0;i<5;i++));
do
	rm main.o

	#Compile all .c files in the present directory and measure build time
	/bin/time -f %U gcc *.c* -o main.o 2>> $1
done
