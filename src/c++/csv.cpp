/**
 * 
 * @author Het Daftary
 * @version 2.1
 * @GitHub "https://github.com/HetDaftary/CSV_in_different_langauges"
 * This file helps us to test the things by putting everything together. 
 */

#include "CSV.hpp"

int main() {
    csv_writer(csv_reader("../csv_files/Sample100.csv", ","), ", ", "../Results/C++/1.csv");
    csv_writer(csv_reader("../csv_files/Sample500.csv", ","), ", ", "../Results/C++/2.csv");
    
    // [['int', 5, 10], ['float', 4, 6], ['alphabets_lower_Case', 5], ['alphabets_upper_Case', 7], ['random_string', 4]].
    vector<Field> fields = {Field("int", 5, 10), Field("float", 4.0, 6.0), Field("alphabets_lower_Case", 5), Field("alphabets_upper_Case", 7), Field("random_string", 4)};

    generate_random_csv("../Results/C++/3.csv", ",", 20000, fields);
    return 0;
}