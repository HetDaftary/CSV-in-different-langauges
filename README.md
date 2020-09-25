# CSV_in_different_langauges
We will write some code to read and write a CSV file with C, C++, Java and Python.
There are two codes for python, To read and write with CSV module and without CSV module. 
The basic logic for code in all the languages is same. 
Source for CSV files: https://www.appsloveworld.com/sample-csv-file/.

Task: Read the CSV files with delimiter "," and write it with delimiter ", ".
Version: 1.0

Logic:nd TRP game
Read part:
We read the file in line by line manner. 
We split the line using split function to split the data with delimiter. 
We store this output to the data and give the data back.

Write part: 
We join the parts using join function. 
Then we write this line using file write operation. 

For Python: 
We are using just string operations split and joinof Python . 
We are using a list which will store all the list of words. 

For Java:
We are ArrayList of String array which stores all the parts of String in Java. 

For C++: 
We are writing the new library for split and join funcitons. 
We are using vector of String* here. 
The string pointer stores all the parts here. 

For C:
We are using a dynamic array like ArrayList of Java.
We are making modules for Split and Join, ArrayList and CSV in this part. 
