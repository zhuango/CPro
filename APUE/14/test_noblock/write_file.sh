#!/bin/bash
line="sdfwefsdff";
filename="shell.file";
exec 4> $filename
num=1;
while [ "$num" != "1000000" ]
do
	echo "$line" >& 4;
#echo "$line" >> $filename;
	num=$(($num+1));
done

