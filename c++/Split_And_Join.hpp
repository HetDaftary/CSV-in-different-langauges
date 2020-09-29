/**
 * 
 * @author Het Daftary
 * @version 2.0
 * @GitHub "https://github.com/HetDaftary/CSV_in_different_langauges"
 * This file has the split and join functions for using with CSV. 
 */

#include <iostream>
#include <string>
using namespace std;

string* split_String(string str, string delimiter, int number_of_fields) {
    string* data = new string[number_of_fields];
    int indexs[number_of_fields], len = str.length(), len_delimiter = delimiter.length(), count = 1;
    indexs[0] = 0;

    for(int i = 0; i < len - len_delimiter + 1; i++)
        if (!(str.substr(i, len_delimiter).compare(delimiter)))
            indexs[count++] = (i + len_delimiter);

    number_of_fields--;
    for(int i = 0; i < number_of_fields; i++)
        data[i] = str.substr(indexs[i], indexs[i + 1] - indexs[i] - 1);
    data[number_of_fields] = str.substr(indexs[number_of_fields], len - indexs[number_of_fields]);
    return data;
}

string join_Strings(string* data, string delimiter, int number_of_fields) {
    string str = "";
    number_of_fields--;

    for(int i = 0; i < number_of_fields; i++) 
        str += (data[i] + delimiter);
    str += data[number_of_fields];

    return str;
}