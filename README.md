# CSV_in_different_langauges
We will write some code to read and write a CSV file with C++, Java and Python.
There are two codes for python, To read and write with CSV module and without CSV module. 
The basic logic for code in all the languages is same. 
Source for CSV files: https://www.appsloveworld.com/sample-csv-file/.

Task: 
1. Read the CSV files with delimiter "," and write it with delimiter ", ".
2. Generate a Random CSV file. Delimiter for this ",".

@version: 2.1

Logic:
Read part:
We read the file in line by line manner. 
We split the line using split function to split the data with delimiter. 
We store this output to the data and give the data back.

Write part: 
We join the parts using join function. 
Then we write this line using file write operation. 

Random part: 
We have support to generate some random numbers, random strings and random from some given data. We will generate the things as required and parse it to string and join with the delimiter. 

For Python: 
We are using just string operations split and join functions of Python. 
We are using a list which will store all the list of words. 

For Java:
We are ArrayList of String array which stores all the parts of String in Java. 

For C++: 
We are writing the new library for split and join funcitons. 
We are using vector of vector<String> here. 
The string pointer stores all the parts here. 
