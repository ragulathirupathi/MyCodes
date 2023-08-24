#!/bin/bash
#The first shell script
echo "Starting the basic shell script"
echo "Tell your name"
read NAME
echo "Hi, $NAME"
VAL1=10
VAL2=30
echo $VAL1
echo $VAL2
readonly VAL1
VAL1=100 #This should generate the error
echo $$ # $ indicate the process ID
echo $0 # Indicate the file name

echo $1 #print the first argument
echo $2 #print the second argument
echo $? #print the last command status
echo $@ #print all the command line arguments
echo $* #print all the command line arguments
echo $! #process number of the backgroud process.
# $* $# will return the same except for the values "$*" "$@"
# "$*" will take the all command line arguments as a string sepearted by spaces while "$@" will take all the arguments into spererate and seperate
for TOKEN in $*
do
	echo $TOKEN
done

#using arrays

ARRAYNAME[0]="First elemnt"
ARRAYNAME[2]="Third elemnt"
ARRAYNAME[3]="Fourth elemnt"
ARRAYNAME[4]="Fifth elemnt"
ARRAYNAME[5]="Sixth elemnt"
#Display array values 

echo "First element, ${ARRAYNAME[0]}"


#print all the array values by


echo "All the array elements, ${ARRAYNAME[*]}"




