/**
 * 
 * @author Het Daftary
 * @version 2.1
 * @GitHub "https://github.com/HetDaftary/CSV_in_different_langauges"
 * This file has the split and join functions for using with CSV. 
 * In Version 2.1 we are updaing the code to work with vector<stirng> and not string* to eliminate number_of_fields.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split_String(string str, string delimiter) {
    vector<string> data;
    vector<int> indexs;
    int len = str.length(), len_delimiter = delimiter.length(), count = 1;
    indexs.push_back(0);

    for(int i = 0; i < len - len_delimiter + 1; i++)
        if (!(str.substr(i, len_delimiter).compare(delimiter)))
            indexs.push_back(i + len_delimiter);

    int number_of_fields = indexs.size() - 1;
    for(int i = 0; i < number_of_fields; i++)
        data.push_back(str.substr(indexs[i], indexs[i + 1] - indexs[i] - 1));
    data.push_back(str.substr(indexs[number_of_fields], len - indexs[number_of_fields]));
    return data;
}

string join_Strings(vector<string> data, string delimiter) {
    string str = "";
    int number_of_fields = data.size() - 1;

    for(int i = 0; i < number_of_fields; i++) 
        str += (data[i] + delimiter);
    
    str += data[number_of_fields];

    return str;
}