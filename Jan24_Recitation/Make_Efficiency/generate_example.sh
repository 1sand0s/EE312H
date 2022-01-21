#!/bin/bash

rm *.c* *.h* *.o* *makefile*

echo "main.o: main.c file1.h file1.o" >> "makefile" 
echo -e "\tgcc main.c -o main.o *.o*" >> "makefile" 

for ((i=1; i<$1; i++));
do
	vHeader="file"$i".h"
	vSource="file"$i".c"

	echo "#include \"file"$i".h\"" >> $vSource
	echo "void print"$i"(){" >> $vSource
	echo "    print"$(($i+1))"();" >> $vSource
	echo "}" >> $vSource

        echo "#ifndef FILE"$i >> $vHeader
        echo "#define FILE"$i >> $vHeader
	echo "#include \"file"$(($i+1))".h\"" >> $vHeader
	echo "void print"$i"();" >> $vHeader
        echo "#endif" >> $vHeader

	echo "file"$i".o: file"$i".c file"$i".h file"$(($i+1))".o" >> "makefile"
	echo -e "\tgcc -c file"$i".c -o file"$i".o" >> "makefile" 
done

vHeader="file"$1".h"
vSource="file"$1".c"

echo "#include \"file"$1".h\"" >> $vSource
echo "void print"$1"(){" >> $vSource
echo "    printf(\"Hello World\");" >> $vSource
echo "}" >> $vSource

echo "#ifndef FILE"$1 >> $vHeader
echo "#define FILE"$1 >> $vHeader
echo "#include <stdio.h>" >> $vHeader
echo "void print"$1"();" >> $vHeader
echo "#endif" >> $vHeader

echo "file"$1".o: file"$1".c file"$1".h" >> "makefile" 
echo -e "\tgcc -c file"$1".c -o file"$1".o" >> "makefile" 

vSource="main.c"

echo "#include \"file1.h\"" >> $vSource
echo "int main(){" >> $vSource
echo "    print1();" >> $vSource
echo "    return 0;" >> $vSource
echo "}" >> $vSource


echo "clean:" >> "makefile"
echo -e "\trm *.o*" >> "makefile"
