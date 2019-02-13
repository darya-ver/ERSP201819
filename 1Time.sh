
#!/bin/bash

####
#### THIS FILE WILL RUN THE TESTS 1 TIME AND OUTPUT THE OUTPUT INTO 
#### FILES IN A DIRECTORY CALLED 'testingData'
####

echo -e "Starting test!!\n"

for i in {1..20}
do
  fileName="$1_test_$i.txt"
  echo -e "Completing test\t$i..."
  ./../leveldb/build/db_bench > testingData/$fileName
done
