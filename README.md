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
    * `getLists.py`: Extracts the lists from a text file into a python file.

* `dataExtraction`: This is where the bulk of the magic happens. 
    * `FullTest.sh`: This is the bash script that runs all the tests 20 times. 
    * `a.out`: This is the executable that is created when you compile the `.cpp` file.
    * `dataNode.hpp`, `dataVector.hpp`, `dataVector.cpp`: The are the C++ files that have the data structures that are used to keep the data alltogether. 
    * `extractData.cpp`: This file contains methods that extra the data from the files that have the output data and put them into the appropriate nodes and data structures so that the data is all in one place. 
    * `main2.cpp`: This runs the `extractData.cpp` methods and stores the results as a list into a file so that a python scipt can extra the lists.


* `additionalFiles`: This directory contains extra files that you do not need to know about. 

### HOW TO RUN TESTS

Navigate to the `dataExtraction` directory from the main directory. 

* First, you need to run your tests given the configuration you have currently set up. To do this, run the `FullTest.sh` file as such:

    * "File Name" is the beginning of the file name that you want your data files to have. 
    * "Dictory Name" is the dictory where you would like these files to be saved into. 

`./FullTest.sh [FILE NAME] [DIRECTORY NAME]`


Example call:

`./FullTest.sh originalTest originalTestFolder`

* Now, you will need to run the C++ that extracts the data you just generated into a more legible format. Type the following commands in order to compile the `main2.cpp` file:

`g++ -std=c++11 main2.cpp`

(`g++` is the C++ compiler, `-std=c++11` tells compile what version of C++ is being used, and `main2.cpp` is the name of the file we are compiling.)

This command will create `a.out`, the executable. To run it, simply type 

`./a.out`

and that should run the methods. 

### HOW TO SWITCH KERNEL VERSIONS

//////     SHAYAN PLEASE EXPLAIN THIS PART        /////// 

### HOW TO RUN TESTS (pt. 2)

Repeat steps in the "HOW TO RUN TESTS" to run old the other version of the kernel. Make sure to put in a separate directory so that when you extra the data, it doesn't get mixed up with the first data you generated. 

### HOW TO GENERATE GRAPHS

Now that you have your data for 2 different kernel versions, it's time to get this data into a graph! 

After tests are ran, navigate to the `graphData` directory from the main directory. 

Edit `getLists.py` to change the file path to the one containing all the newly generated data. 

Optional: in `getLists.py`, edit the `info` array that is passed into `drawBoxPlot` to change the labels on the graph.

Run `python3 getLists.py` and two graphs (both throughput and bandwith) will be display one after another, and they are  automatically saved under the `graphData` directory named after their titles.

<!-- * This is a bullet point -->
<!-- * This is another.  -->
