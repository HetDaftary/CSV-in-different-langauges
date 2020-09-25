'''
@author Het Daftary
@version 1.0
@GitHub "https://github.com/HetDaftary/CSV_in_different_langauges"
We have a CSV class and two static methods that could be used as needed. 
We are going with list of parts format to store data. 
'''

class CSV:
    @staticmethod
    def csv_reader(file_name, delimiter):
        fptr = open(file_name, "r")
        data = [x.strip().split(delimiter) for x in fptr.readlines()]
        # We are using list comprehension of Python to store the output of split in one line. 
        fptr.close()
        return data
    
    @staticmethod
    def csv_writer(data, delimiter, file_name):
        fptr = open(file_name, "w")
        for line in data:
            fptr.write(delimiter.join(line))
            fptr.write("\n")
        fptr.close()

CSV.csv_writer(CSV.csv_reader("../csv_files/Sample100.csv", ","), ", ", "../Results/Python/without_module/1.csv")
CSV.csv_writer(CSV.csv_reader("../csv_files/Sample500.csv", ","), ", ", "../Results/Python/without_module/2.csv")