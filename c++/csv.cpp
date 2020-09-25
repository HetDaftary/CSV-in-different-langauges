#include "CSV.hpp"
#define number_of_fields 5
int main() {
    csv_writer(csv_reader("../csv_files/Sample100.csv", ",", number_of_fields), ", ", number_of_fields, "../Results/C++/1.csv");
    csv_writer(csv_reader("../csv_files/Sample500.csv", ",", number_of_fields), ", ", number_of_fields, "../Results/C++/2.csv");
    return 0;
}