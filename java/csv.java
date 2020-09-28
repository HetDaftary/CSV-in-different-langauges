/**
 * 
 * @author Het Daftary
 * @since 28-09-2020
 * @version 2.0
 * @GitHub "https://github.com/HetDaftary/CSV_in_different_langauges/"
 * 
 * Simple library to read and write a CSV and generate random CSV files. 
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileWriter; 
import java.io.IOException;

class Field { // For generating random CSV files. 
    String field_name;
    int values0, values1;
    double values0d, values1d;

    Field(String field_name, int v0, int v1) {
        this.field_name = field_name;
        this.values0 = v0;
        this.values1 = v1;
    }

    Field(String field_name, int v0) {
        this.field_name = field_name;
        this.values0 = v0;
    }

    Field(String field_name, double v0, double v1) {
        this.field_name = field_name;
        this.values0d= v0;
        this.values1d = v1;
    }
}

class CSV {
    /**
     * 
     * This class is having all the code to read and write a CSV file. 
     * We will be using ArrayList of String[] here to store the data. 
     * The Row Zero has all the titles. 
     * Scanner module is used to read the information and normal file.write is used to write the file. 
     */

    public static ArrayList<String[]> csv_reader(String file_name, String delimiter, int number_of_fields) {
        ArrayList<String[]> data = new ArrayList<String[]>();

        try {
            File csv_File = new File(file_name);
            Scanner sc = new Scanner(csv_File);    
            while(sc.hasNext()) 
                data.add(sc.nextLine().split(delimiter, number_of_fields));
            sc.close();
        } catch(FileNotFoundException e) {
            System.out.println("Check the file name and path.");
        }
        return data;
    }

    public static void csv_writer(ArrayList<String[]> data, String file_name, String delimiter) {
        try {
            FileWriter csv_File = new FileWriter(file_name);
            int length_to_write = data.size();
            for(int i = 0; i < length_to_write; i++) {
                csv_File.write(String.join(delimiter, data.get(i)));
                csv_File.write("\n");
            }
            csv_File.close();
        } catch(IOException e) {
            System.out.println("IOExecption.");
        }
    }

    private static String generate_random_int(int lower, int upper) {
        return String.valueOf((lower + (int)((upper - lower)*Math.random())));
    }

    private static String generate_random_double(double lower, double upper) {
        return String.valueOf(lower + ((upper - lower)*(Math.random())));
    }

    private static String generate_random_string(int mode, int length) {
        char[] string_answer = new char[length];
        if (mode == 0) 
            for(int i = 0; i < length; i++) 
                string_answer[i] = (char)((int)(97 + (25)*Math.random()));
        else if (mode == 1) 
            for(int i = 0; i < length; i++) 
                string_answer[i] = (char)((int)(65 + (25)*Math.random()));
        else 
            for(int i = 0; i < length; i++) 
                string_answer[i] = (char)((int)(48 + (74)*Math.random()));
        return new String(string_answer);
    }

    public static void generate_random_csv(String file_name, String delimiter, Field[] fields, int capacity) {
        try {
            FileWriter fptr = new FileWriter(file_name);
            String[] to_write;
            int number_of_fields = fields.length;

            for (int i = 0; i < capacity; i++) {
                to_write = new String[number_of_fields];
                for (int j = 0; j < number_of_fields; j++) 
                    if (fields[j].field_name.equals("int")) 
                        to_write[j] = generate_random_int(fields[j].values0, fields[j].values1);
                    else if (fields[j].field_name.equals("float")) 
                        to_write[j] = generate_random_double(fields[j].values0d, fields[j].values1d);
                    else if (fields[j].field_name.equals("alphabets_lower_Case"))
                        to_write[j] = generate_random_string(0, fields[j].values0);
                    else if (fields[j].field_name.equals("alphabets_upper_Case"))
                        to_write[j] = generate_random_string(1, fields[j].values0);
                    else
                        to_write[j] = generate_random_string(2, fields[j].values0);
                fptr.write(String.join(delimiter, to_write) + "\n");
            } fptr.close();
        } catch(IOException e) {
            System.out.println("IO Execption.");
        }
    }
}

public class csv {
    /**
     * 
     * This is main class. It is used to test the code. 
     * We will create objects and call the methods of CSV class here.
     */

    public static void main(String[] args) {
        /**
         * 
         * If worked well, it will create 1.csv and 2.csv with delimiter ", " from Sample100.csv and Sample500.csv respectively with same data.
         */
        CSV.csv_writer(CSV.csv_reader("../csv_files/Sample100.csv", ",", 5), "../Results/Java/1.csv", ", ");
        CSV.csv_writer(CSV.csv_reader("../csv_files/Sample500.csv", ",", 5), "../Results/Java/2.csv", ", ");
        
        Field[] fields = new Field[5]; // [['int', 5, 10], ['float', 4, 6], ['alphabets_lower_Case', 5], ['alphabets_upper_Case', 7], ['random_string', 4]].
        fields[0] = new Field("int", 5, 10);
        fields[1] = new Field("float", (double)4, (double)6);
        fields[2] = new Field("alphabets_lower_Case", 5);
        fields[3] = new Field("alphabets_upper_Case", 7);
        fields[4] = new Field("random_string", 4);
        CSV.generate_random_csv("../Results/Java/3.csv", ",", fields, 20000);
    }
} 
