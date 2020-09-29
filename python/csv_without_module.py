'''
@author Het Daftary
@version 2.0
@GitHub "https://github.com/HetDaftary/CSV_in_different_langauges"
We have a CSV class and two static methods that could be used as needed. 
We are going with list of parts format to store data. 
Random module is a dependency for 2.0.
'''

import random

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

    @staticmethod
    def generate_random_int(lower, upper): # Helper for generate_random_csv.
        return str(random.randint(lower, upper + 1))
    
    @staticmethod
    def generate_random_double(lower, upper): # Helper for generate_random_csv.
        return str(lower + (random.random()) * (upper - lower))
    
    @staticmethod
    def generate_random_string(mode, length): # Helper for generate_random_csv.
        chars_for_use = [list(map(chr, list(range(ord('a'), ord('z') + 1)))), list(map(chr, list(range(ord('A'), ord('Z') + 1)))), list(map(chr, list(range(ord('a'), ord('z') + 1)))) + list(map(chr, list(range(ord('A'), ord('Z') + 1)))) + list(map(chr, list(range(ord('0'), ord('0') + 10))))]
        return ''.join([random.choice(chars_for_use[mode]) for i in range(length)])

    @staticmethod
    def generate_random_csv(file_name, delimiter, fields, capacity):
        '''
        The modes are as listed in the dictionary below. 
        We are taking inputs in list of list format. 
        ['int', 5, 7] generates int in 5 to 7 range. 
        ['float', 5.0, 7.0] generated random float in 5.0, 7.0
        ['alphabets_lower_Case', length] generates small alphabets list for given length
        Same for other string formats. 
        data_type_numbers = {'int': 0, 'float': 1, 'alphabets_lower_Case': 2, 'alphabets_upper_Case': 3, 'random_string': 4}
        '''
        number_of_fields = len(fields)
        fptr = open(file_name, "w")
        for i in range(capacity):
        	to_write = [] # We start with the list format. Then join and write to the file.
        	for i in range(number_of_fields):
        		if fields[i][0] == 'int':
        			to_write.append(CSV.generate_random_int(fields[i][1], fields[i][2]))
        		elif fields[i][0] == 'float':
        			to_write.append(CSV.generate_random_double(fields[i][1], fields[i][2]))
        		elif fields[i][0] == 'alphabets_lower_Case':
        			to_write.append(CSV.generate_random_string(0, fields[i][1]))
        		elif fields[i][0] == 'alphabets_upper_Case':
        			to_write.append(CSV.generate_random_string(1, fields[i][1]))
        		else:
        			to_write.append(CSV.generate_random_string(2, fields[i][1]))
        	fptr.write(delimiter.join(to_write) + '\n')
        fptr.close()

CSV.csv_writer(CSV.csv_reader("../csv_files/Sample100.csv", ","), ", ", "../Results/Python/without_module/1.csv")
CSV.csv_writer(CSV.csv_reader("../csv_files/Sample500.csv", ","), ", ", "../Results/Python/without_module/2.csv")
CSV.generate_random_csv("../Results/Python/3.csv", ",", [['int', 5, 10], ['float', 4, 6], ['alphabets_lower_Case', 5], ['alphabets_upper_Case', 7], ['random_string', 4]], 20000)
