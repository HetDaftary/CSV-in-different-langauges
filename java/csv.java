/**
 * 
 * @author Het Daftary
 * @since 24-09-2020
 * @version 1.0
 * @GitHub "https://github.com/HetDaftary/CSV_in_different_langauges/"
 * 
 * Simple library to read and write a CSV. 
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import javax.xml.crypto.Data;

import java.io.FileWriter; 
import java.io.IOException;

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
        CSV.csv_writer(CSV.csv_reader("../csv_files/Sample100.csv", ",", 5), "../Results/1.csv", ", ");
        CSV.csv_writer(CSV.csv_reader("../csv_files/Sample500.csv", ",", 5), "../Results/2.csv", ", ");
    }
} 
