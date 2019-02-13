
#!/bin/bash

#### 
#### FullTest.sh
#### 
#### THIS FILE WILL RUN THE TESTS 20 TIMES AND OUTPUT THE OUTPUT INTO 
#### FILES IN A DIRECTORY CALLED 'testingData'
####

# check if there are correct number of arguments
if [ $# -ne 1 ]; then
	echo -e "\nplease enter test name for file creation\n"
	exit 1
fi

echo -e "Starting tests!!\n"

for i in {1..20}
do
  fileName="$1_test_$i.txt"
  echo -e "Completing test\t$i..."
  ./../../leveldb/build/db_bench 1> testingData/$fileName 2> extraText.txt
  ./a.out
done

echo -e "\nSuccessfully ran all tests"
rm extraText.txt
