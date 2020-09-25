#include <vector>
#include <fstream>
#include "Split_And_Join.hpp"

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
        cout << "Error";
    csv_file.close();
}