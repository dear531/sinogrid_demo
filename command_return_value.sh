#!/bin/bash
nc -zv 127.0.0.1 22
if [ $? -eq 0 ]; then
	echo $?
fi
nc -zv 127.0.0.1 23
i=$?
if [ $i -eq 1 ]; then
	echo $i;
fi
