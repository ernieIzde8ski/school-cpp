/*
    Ernest Izdebski
    2023-01-17

    Creates and displays an array of 10 employees, each represented by an array of hours.
*/


import java.util.Scanner;
import java.util.Arrays;

public class EmployeeHoursArray {
    // method for displaying array of employees
    public static void displayAllEmployeeHours(int[][] arr) {
        for (int[] elem : arr) {
            System.out.println("\t" + Arrays.toString(elem));
        }
    };


    // program entry point
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("How many employees?");
        int totalEmployees = scanner.nextInt();
        int[][] allEmployeeHours = new int[totalEmployees][];

        // populate array of employee hours
        for (int i = 0; i < totalEmployees; i++) {
            System.out.print("How many shifts for employee no. " + i + "?\t");
            int totalShifts = scanner.nextInt();
            int[] employeeHours = new int[totalShifts];
            System.out.println("\tHow many hours...");
            for (int j = 0; j < totalShifts; j++) {
                System.out.print("\t\tfor shift #" + j + "?\t");
                employeeHours[j] = scanner.nextInt();
            }
            allEmployeeHours[i] = employeeHours;
        }

        System.out.println("All employees:");
        EmployeeHoursArray.displayAllEmployeeHours(allEmployeeHours);
    
    }
}
