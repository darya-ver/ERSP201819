
#!/bin/bash

####
#### THIS FILE WILL RUN THE TESTS 1 TIME AND OUTPUT THE OUTPUT INTO 
#### FILES IN A DIRECTORY CALLED 'testingData'
####

# check if there are correct number of arguments
if [ $# -ne 1 ]; then
	echo -e "\nplease enter test name for file creation\n"
	exit 1
fi

echo -e "Starting test!!\n"

for i in {1..2}
do
  fileName="$1_test_$i.txt"
  echo -e "Completing test\t$i..."
  ./../../leveldb/build/db_bench > testingData/$fileName
  ./a.out
done
