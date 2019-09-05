#!/bin/bash

rm teste.txt
mkdir teste_out

#Iterate all files
for filename in *.torrent; do
	#echo  "Reading $filename"

	var="$(./read_torrent_filename $filename)"
	#echo "$(./read_torrent_filename $filename)"
	#"$(./read_torrent_filename $filename)"
	#OUT = "$(./read_torrent_filename filename)"
	
	#OUT2 = $(pwd)
	
	#echo $var
	echo $var >> teste.txt
	
	#echo ${var}_${filename#./}
	
	cp "$filename" "teste_out/${var}_${filename#./}"
	#echo $OUT
	
done