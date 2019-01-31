#!/bin/bash
echo -e "Starting test!!\n"

for i in {1..20}
do
  fileName="$1_test_$i.txt"
  echo -e "Completing test\t$i..."
  cat ogTest.txt > testingData/$fileName
done
