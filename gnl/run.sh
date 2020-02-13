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

varfolder=$(../select ../../*)
sleep 1

if test -f "$varfolder/author"; then
	printf "$PINK%s%s\n" "Author:" $(cat $varfolder/author)
else
	printf "$RED%s\n" "error: no author file"
fi

printf "$PINK%s$NORMAL\n" "compiling..."
export testdir=$varfolder
make fclean && make

printf "$PINK%s$NORMAL\n" "TEST LEAKS"
PROG_PATH="./test_gnl tests/test_null test_gnl asd asd"
($PROG_PATH >/dev/null 2>&1) &
PID=$!
sleep 3
RESULT=$(leaks $PID 2>/dev/null | grep 'total leaked bytes')
kill -9 $PID
printf "$NORMAL%s\n" "$RESULT"

sleep 1
printf "\n"

printf "$PINK%s$NORMAL\n" "TEST BASIC"
OUR=$(./test_gnl tests/test_normal)
CORRECT=$(cat tests/correct_normal)

if [ "$OUR" != "$CORRECT" ]; then
	printf "$RED%s$NORMAL\n" "[FAIL]"
	printf "$OUR\n"
	printf "$RED%s$NORMAL\n" "CORRECT RESULT"
	cat tests/correct_normal
else
	printf "%s $GREEN%s$NORMAL\n" "Test" "[OK]"
fi

printf "\n"

printf "$PINK%s$NORMAL\n" "TEST EMPTY"
OUR=$(./test_gnl tests/empty)
CORRECT=$(cat tests/empty)

if [ "$OUR" != "$CORRECT" ]; then
	printf "$RED%s$NORMAL\n" "[FAIL]"
	printf "$OUR\n"
	printf "$RED%s$NORMAL\n" "CORRECT RESULT"
	cat tests/correct_normal
else
	printf "%s $GREEN%s$NORMAL\n" "Test" "[OK]"
fi

printf "\n"

printf "$PINK%s$NORMAL\n" "TEST NULL"
OUR=$(./test_gnl tests/test_null)
CORRECT=$(cat tests/correct_null)

if [ "$OUR" != "$CORRECT" ]; then
	printf "$RED%s$NORMAL\n" "[FAIL]"
	printf "$OUR\n"
	printf "$RED%s$NORMAL\n" "CORRECT RESULT"
	cat tests/correct_null
else
	printf "%s $GREEN%s$NORMAL\n" "Test" "[OK]"
fi

printf "\n"

printf "$PINK%s$NORMAL\n" "TEST RETURN"
OUR=$(./test_gnl tests/test_null 123)
CORRECT=$(cat tests/correct_returns)

if [ "$OUR" != "$CORRECT" ]; then
	printf "$RED%s$NORMAL\n" "[FAIL]"
	printf "$OUR\n"
	printf "$RED%s$NORMAL\n" "CORRECT RESULT"
	cat tests/correct_returns
else
	printf "%s $GREEN%s$NORMAL\n" "Test" "[OK]"
fi

printf "\n"

printf "$PINK%s$NORMAL\n" "TEST BONUS"
OUR=$(./test_gnl tests/test_bonus1 tests/test_bonus2 asd)
CORRECT=$(cat tests/correct_bonus)

if [ "$OUR" != "$CORRECT" ]; then
	printf "$RED%s$NORMAL\n" "[FAIL]"
	printf "$OUR\n"
	printf "$RED%s$NORMAL\n" "CORRECT RESULT"
	cat tests/correct_bonus
else
	printf "%s $GREEN%s$NORMAL\n" "Test" "[OK]"
fi
