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

if [ $# -l 2 ]; then
	printf "$CYAN%s\n" "usage: ./init.sh <test> <folder>"
	exit 1
fi

if [ $1 = "gnl" ]; then
	cd gnl
	./run.sh "../$2"
	exit 1
fi

if [ $1 = "fillit" ]; then
	cd fillit
	./run.sh "../$2" $3
	exit 1
fi

if [ $1 = "ft_printf" ]; then
	cd ft_printf
	./start.sh "../$2"
	./test_printf a
	exit 1
fi