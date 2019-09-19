#!/bin/bash
rm -f data
rm -f data.lock
if [ ! -f data ]; then echo 0 > data; fi


if ln data data.lock
then
	counter=0
	while [[ $counter != 100 ]]; do
		(( counter = counter + 1 ))
		num=`tail -1 data`
		expr $num + 1 >> data
	done
	rm data.lock
fi
