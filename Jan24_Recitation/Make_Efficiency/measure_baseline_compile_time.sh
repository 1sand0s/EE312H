#!/bin/bash

echo "Baseline"
for ((i=0;i<5;i++));
do
	rm main.o
	/bin/time -f %U gcc *.c* -o main.o 2>> $1
done
