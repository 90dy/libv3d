#!/bin/bash
# Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

name=libv3d.a

cc=gcc
cflag='-Wall -Wextra -Werror -O3 -fno-stack-protector -std=c99 -D '$1
ar="ar rc"
rm="rm -rf"

incdir=(inc)
srcdir=($(basename -a $(find src -type d)))
objdir=${srcdir[@]/src/obj}
dbgdir=${srcdir[@]/src/dbg}

rm Makefile

function	append()
{
	/bin/echo -e $1 >> Makefile
}

function	append_var()
{
	if [ "$3" == '' ]
	then
		append $1'\t\t\t=\t'$2
	else
		append $1'\t\t\t=\t'$2' \'
		for val in "${@:3}"
		do
			append '\t\t\t\t\t\t'$val' \'
		done
	fi
}

append_var "NAME\t" $name
append_var "\nCC\t\t" $cc
append_var "CFLAG\t" $cflag
append_var "\nAR\t\t" $ar
append_var "\nRM\t\t" $rm

function	append_vardir()
{
	bvardir=$(echo $1 | tr '[a-z]' '[A-Z]')
	append_var '\n'$bvardir'_DIR\t' $(echo $1 | tr '[A-Z]' '[a-z]')
	for dir in "${@:2}"
	do
		append_var $bvardir'_'$(expr substr $dir 1 3 | tr '[a-z]' '[A-Z]')'_DIR' $1/$dir
	done
	append_var $bvardir'_ALL_DIR' $1'\x20\'
	for dir in "${@:2}"
	do
		append '\t\t\t\t\t\t'$1/$dir' \'
	done
}

append_vardir ${incdir[@]}
append_vardir ${srcdir[@]}
append_vardir ${objdir[@]}
append_vardir ${dbgdir[@]}

append_var	'\nINC\t\t' '-I\x20'${incdir[@]}

function	append_vardirfiles()
{
	bvardir=$(echo $1 | tr '[a-z]' '[A-Z]')
	append_var '\n'$bvardir'\t\t' $(basename -a $(find $1 -maxdepth 1 -type f | grep -e '\.c$'))
	for dir in "${@:2}"
	do
		files=("$(basename -a $(find $1/$dir -maxdepth 1 -type f | grep -e '\.c$') 2>/dev/null)")
		append_var \
			'\n'$bvardir'_'$(expr substr $dir 1 3 | tr '[a-z]' '[A-Z]')'\t' \
			${files[@]}
	done
	append_var '\n'$bvardir'_ALL\t' '$('$bvardir')\x20\'
	for dir in "${@:2}"
	do
		append '\t\t\t\t\t\t$('$bvardir'_'$(expr substr $dir 1 3 | tr '[a-z]' '[A-Z]')') \'
	done
}

append_vardirfiles ${srcdir[@]}

function	append_vardirdepfiles()
{
	bvardir=$(echo $2 | tr '[a-z]' '[A-Z]')
	append_var '\n'$bvardir'\t\t' '$(patsubst\x20%.c,\x20$('$bvardir'_DIR)/'$1',\x20$(SRC))'
	for dir in "${@:3}"
	do
		vardir=$(expr substr $dir 1 3 | tr '[a-z]' '[A-Z]')
		append_var \
			$bvardir'_'$vardir'\t' \
			'$(patsubst\x20%.c,\x20$('$bvardir'_'$vardir'_DIR)/'$1',\x20$(SRC_'$vardir'))'
	done
	append_var $bvardir'_ALL\t' '$('$bvardir')\x20\'
	for dir in "${@:3}"
	do
		append '\t\t\t\t\t\t$('$bvardir'_'$(expr substr $dir 1 3 | tr '[a-z]' '[A-Z]')') \'
	done
}

append_vardirdepfiles '%.o' ${objdir[@]}
append_vardirdepfiles '%.out' ${dbgdir[@]}

function	append_rule()
{
	append $1'\t\t\t:\t'$2
	if [ "$3" != '' ]
	then
		append '\t\t\t\t\t\t'$3
	fi
}

append_rule '\n\nall\t\t' '$(OBJ_ALL_DIR)\x20$(NAME)'
append_rule '\n$(NAME)\t' '$(OBJ_ALL)' '$(AR)\x20$@\x20$^'
append_rule '\ndebug\t' '$(DBG_ALL_DIR)\x20$(DBG_ALL)' './bin/debug.sh\x20$(DBG_ALL)'

function	append_deprule()
{
	bvardir=$(echo $3 | tr '[a-z]' '[A-Z]')
	append_rule '\n$('$bvardir')\t' \
		'$('$bvardir'_DIR)/'$1'\x20:\x20$(SRC_DIR)/%.c' \
		$2
	for dir in ${@:4}
	do
		vardir=$(expr substr $dir 1 3 | tr '[a-z]' '[A-Z]')
		append_rule '\n$('$bvardir'_'$vardir')' \
			'$('$bvardir'_'$vardir'_DIR)/'$1'\x20:\x20$(SRC_'$vardir'_DIR)/%.c' \
			$2
	done
	append '\n$('$bvardir'_ALL_DIR)\t\t:'
	append '\t\t\t\t\t\tmkdir -p $@'
}

append_deprule '%.o' '$(CC)\x20$(CFLAG)\x20-o\x20$@\x20-c\x20$<\x20$(INC)' ${objdir[@]}
append_deprule '%.out' '$(CC)\x20$(CFLAG)\x20-o\x20$@\x20$<\x20$(INC)\x20||\x20/bin/true' ${dbgdir[@]}

append '\nclean\t\t\t\t:'

append '\t\t\t\t\t\trm -rf $(OBJ_ALL_DIR) $(DBG_ALL_DIR)'

append '\nfclean\t\t\t\t:\tclean'

append '\t\t\t\t\t\trm -f $(NAME) $(NAME_HOSTTYPE)'

append '\nre\t\t\t\t\t:\tfclean all'

append '\n.PHONY\t\t\t\t:\tall\x20clean\x20flcean\x20re'
