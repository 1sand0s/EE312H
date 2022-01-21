#!/bin/bash

for ((i=20;i<=100;i+=10));
do
	echo "Hello"$i
	./generate_example.sh $i
	./measure_baseline_compile_time.sh "Baseline"$i
	for ((j=1;j<=10;j++));
	do
		var=$(echo "0.5*(2*0.1*$i*$j-0.1*$i)" | bc -l)
		./measure_make_compile_time.sh "file"${var%.*}".o" "Make"${var%.*}"_"$i
	done
done
