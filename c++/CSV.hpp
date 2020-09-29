/**
 * 
 * @author Het Daftary
 * @version 2.0
 * @GitHub "https://github.com/HetDaftary/CSV_in_different_langauges"
 * This file has the read and write funcitons for CSV file. 
 * We will be using vector of string* here to store data. 
 * Version 2.0 has a feature to generate Random CSV files. 
 */

#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Split_And_Join.hpp"

class Field {
    public:
    string field_name;
    int lower_int, upper_int;
    double lower_double, upper_double;
    Field(string field_name, int lower_int, int upper_int) { // For int.
        this -> field_name = field_name;
        this -> lower_int = lower_int;
        this -> upper_int = upper_int;
    }

    Field(string field_name, int lower_int) { // For strings. 
        this -> field_name = field_name;
        this -> lower_int = lower_int;
        this -> upper_int = 0;
    }

    Field(string field_name, double lower_double, double upper_double) { // For double.
        this -> field_name = field_name;
        this -> lower_double = lower_double;
        this -> upper_double = upper_double;
    }
};

vector<string*> csv_reader(string file_name, string delimiter, int number_of_fields) {
    fstream csv_file;
    vector<string*> data;
    string temp_line;
    csv_file.open(file_name, ios::in);

    if(csv_file.is_open()) 
        while (getline(csv_file, temp_line)) 
            data.push_back(split_String(temp_line, delimiter, number_of_fields));
    else
        cout << "Check the file name and path" << endl;
    csv_file.close();
    return data;
}

void csv_writer(vector<string*> data, string delimiter, int number_of_fields, string file_name) {
    fstream csv_file;
    csv_file.open(file_name, ios::out);
    if(csv_file.is_open()) 
        for(string* parts: data)
            csv_file << join_Strings(parts, delimiter, number_of_fields) << "\n";
    else
        cout << "Error" << endl;
    csv_file.close();
}

string generate_random_int(int lower, int upper) {
    return to_string(lower + (rand() % (upper - lower)));
}

string generate_random_double(double lower, double upper) {
    double f = (double)rand() / RAND_MAX;
    return to_string(lower + f * (upper - lower));
}

string generate_random_string(int mode, int length) {
    string answer = "";
    static const char for_lower_case[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    static const char for_upper_case[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    static const char for_random_str[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


    if (mode == 0) // Lower case alphabets.
        for (int i = 0; i < length; i++)     
            answer = answer + for_lower_case[rand() % 26];
    else if (mode == 1) // Upper case alphabets.
        for (int i = 0; i < length; i++) 
            answer = answer + for_upper_case[rand() % 26];
    else if (mode == 2) // Random strings.
        for (int i = 0; i < length; i++)
            answer = answer + for_random_str[rand() % 74];
    return answer + "\0";
}

void generate_random_csv(string file_name, string delimiter, int capacity, vector<Field> fields) {
    /**
     * 
     * Using vectors over array because it gives us an easy way to process the things and,
     * Vector library is already used by other functions. Thus, dependencies do not increase. 
     */
    fstream fptr;
    string* to_write; 
    int count = 0, i, j, number_of_fields = fields.size();

    fptr.open(file_name, ios::out);

    if (fptr.is_open()) {
        for (i = 0; i < capacity; i++) {
            to_write = new string[number_of_fields];
            count = 0;
            for(Field i: fields) {
                
                if (!(i.field_name.compare("int"))) 
                    to_write[count++] = generate_random_int(i.lower_int, i.upper_int);
                else if (!(i.field_name.compare("float")))
                    to_write[count++] = generate_random_double(i.lower_double, i.upper_double);
                else if (!(i.field_name.compare("alphabets_lower_Case")))
                    to_write[count++] = generate_random_string(0, i.lower_int);
                else if (!(i.field_name.compare("alphabets_upper_Case")))
                    to_write[count++] = generate_random_string(1, i.lower_int);
                else
                    to_write[count++] = generate_random_string(2, i.lower_int);
            }

            fptr << join_Strings(to_write, delimiter, number_of_fields) + "\n";
        }
    } else {
        cout << "Error" << endl;
    } fptr.close();
}