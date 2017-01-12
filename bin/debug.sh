# Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

#!/bin/bash

for arg in "$@"
do
	if [ ! -e $arg ]
	then
		/bin/echo -e "\e[33m[ ./$arg ] No file\e[0m"
	else
		./$arg
		if [ $? ]
		then
			/bin/echo -e "\e[33m[ ./$arg ] \e[32mSuccess\e[0m"
		else
			/bin/echo -e "\e[33m[ ./$arg ] \e[31mFailed line $?\e[0m"
		fi
	fi
done