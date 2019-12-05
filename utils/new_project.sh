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

printf "$WHITE%s$NORMAL" "Project name: "
read project

printf "$WHITE%s$NORMAL" "Author: "
read author

mkdir $project
printf "$CYAN%s %s$NORMAL\n" "Initializing" "$project"
git clone https://github.com/Rouhija/libft templibft
mv templibft $project/libft
rm -rf $project/libft/.git
mkdir $project/srcs
mkdir $project/includes
echo ".DS_Store\n*.a\n*.o\na.out\n.vscode" > $project/.gitignore
echo $author > $project/author
touch $project/srcs/$project.c
touch $project/includes/$project.h

