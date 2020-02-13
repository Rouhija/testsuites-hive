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

varfolder=$(../ft_select ../../*)
sleep 1

if test -f "$varfolder/author"; then
	printf "$PINK%s%s$NORMAL\n" "Author:" $(cat $varfolder/author)
else
	printf "$RED%s$NORMAL\n" "error: no author file"
fi

export testdir=$varfolder
make re
