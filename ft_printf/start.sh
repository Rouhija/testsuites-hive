#!/bin/sh

BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PINK="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
NORMAL="\033[0;39m"

if [ $# -eq 0 ]; then
	printf "$CYAN%s\n" "ft_printf: usage: ./start.sh <folder>"
	exit 1
fi

if test -f "../$1/author"; then
	printf "$PINK%s%s$NORMAL\n" "Author:" $(cat ../$1/author)
else
	printf "$RED%s$NORMAL\n" "error: no author file"
fi

export testdir=$1
make re
