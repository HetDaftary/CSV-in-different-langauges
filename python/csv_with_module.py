'''
@author Het Daftary
@version 1.0
@GitHub "https://github.com/HetDaftary/CSV_in_different_langauges"
'''

import csv

def read(file_name, delimiter):
    with open(file_name, "r") as fptr:
        data = csv.reader(fptr, delimiter=",")
    return data

def write(data, file_name):
    with open(file_name, "w") as fptr:
        writer = csv.writer(fptr)
        writer.writerows(data)

write(read("../csv_files/Sample100.csv", ","), "../Results/Python/with_module/1.csv")
write(read("../csv_files/Sample500.csv", ","), "../Results/Python/with_module/2.csv")