# ERSP201819

### GETTING AWS

The first step in this project is getting an [AWS](https://lightsail.aws.amazon.com/ls/webapp/home/instances) 
Virtual Machine.
  
//////     SHAYAN PLEASE EXPLAIN THIS PART        /////// 

### HOW TO GET THE CODE TO YOUR LOCAL DEVICE

Before starting anything else, please go to [Level DB's website](https://github.com/google/leveldb) to learn
how to download `LevelDB` onto your virtual machine. 

### HOW TO GET THIS CODE ONTO YOUR VM

Navigate to the directory in your terminal where you would like to store this directory. 
Type the following into your terminal and that will download the repo onto your machine. 

```git clone https://github.com/darya-ver/ERSP201819.git ```

### REPO FILE EXPLANATION

There are a few folders in the drive that you need to be aware of. 

* `GraphData`: This contains the python files that generate the graphs, as well as 
the `.png` files that contain the graphs themselves. 
    * `Figure 1: Throughput LevelDB.png`: Throughput graph between old and new kernel versions.
    * `Figure 2: Bandwidth LevelDB.png`: Bandwidth graph between old and new kernel versions.
    * `displayGraph.py`: Python file that displays the graph
    * `displayGraph.pyc`: IDK WHAT THIS DOES BONNIE PLEASE HELP
    * `getLists.py`: Extracts the lists from a text file into a python file.

* `dataExtraction`: This is where the bulk of the magic happens. 
    * `FullTest.sh`: This is the bash script that runs all the tests 20 times. 
    * `a.out`: This is the executable that is created when you compile the `.cpp` file.
    * `dataNode.hpp`, `dataVector.hpp`, `dataVector.cpp`: The are the C++ files that have the data structures that are used to keep the data alltogether. 
    * `extractData.cpp`: This file contains methods that extra the data from the files that have the output data and put them into the appropriate nodes and data structures so that the data is all in one place. 
    * `main2.cpp`: This runs the `extractData.cpp` methods and stores the results as a list into a file so that a python scipt can extra the lists.


* `additionalFiles`: This directory contains extra files that you do not need to know about. 



