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

printf "$WHITE%s$NORMAL\n" "provide project folder:"
read varfolder

if test -f "../../$varfolder/author"; then
	printf "$PINK%s\n%s\n" "Author:" $(cat ../../$varfolder/author)
else
	printf "$RED%s\n" "error: no author file"
fi

while [ 1 -le 3 ]
do
	printf "$WHITE%s\n\t%s\n\t%s\n\t%s$NORMAL\n" "choose test:" "0 - compile" "1 - basic" "9 - quit"
	read vartest

	if [ $vartest = "9" ] ; then
		exit 1
	fi

	if [ $vartest = "0" ] ; then
		cd ../../$varfolder
		make fclean
		make 
		make clean
		cd -
	fi

	if [ $vartest = "1" ] ; then
		printf "$PINK%s$NORMAL\n" "BASIC TESTS"
		i=0
		while [ $i -le 0 ]
		do
			OUR=$(../../$varfolder/ft_ls basic_tests/testdir_$i)
			printf "$OUR\n"
			i=$(( $i + 1 ))
		done
		printf "\n"
	fi
done
