#!/bin/bash

#Repeat for source file count 20 to 100
for ((i=20;i<=100;i+=10));
do
	#Generate source and header files#
	./generate_example.sh $i

	#Measure compile time using baseline approach#
	./measure_baseline_compile_time.sh "Baseline"$i

	#Divide the source files into deciles#
	for ((j=1;j<=10;j++));
	do
		#Get the median file in each decile#
		var=$(echo "0.5*(2*0.1*$i*$j-0.1*$i)" | bc -l)

		#Edit the median file and measure compile time using make#
		./measure_make_compile_time.sh "file"${var%.*}".o" "Make"${var%.*}"_"$i
	done
done
