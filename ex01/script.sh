#!/bin/bash

BLUE="\e[94m"
ENDCOLOR="\e[0m"

echo -e "${BLUE}./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"${ENDCOLOR}"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo -e "${BLUE}./RPN \"7 7 * 7 -\"${ENDCOLOR}"
./RPN "7 7 * 7 -"

echo -e "${BLUE}./RPN \"1 2 * 2 / 2 * 2 4 - +\"${ENDCOLOR}"
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo -e "${BLUE}./RPN \"(1 + 1)\"${ENDCOLOR}"
./RPN "(1 + 1)"

echo -e "${BLUE}./RPN \"5 0 /\"${ENDCOLOR}"
./RPN "5 0 /"

echo -e "${BLUE}./RPN \"5 - 7\"${ENDCOLOR}"
./RPN "5 - 7"

echo -e "${BLUE}./RPN \"2 - 7 -\"${ENDCOLOR}"
./RPN "2 - 7 -"

echo -e "${BLUE}./RPN \"- 5 5\"${ENDCOLOR}"
./RPN "- 5 5"

echo -e "${BLUE}./RPN \"5 2 7 -\"${ENDCOLOR}"
./RPN "5 2 7 -"