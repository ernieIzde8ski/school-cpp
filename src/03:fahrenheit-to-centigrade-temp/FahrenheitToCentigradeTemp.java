/*
    Ernest Izdebski
    2023-01-16

    Program to convert Fahrenheit temperatures to Centigrade.
*/

import java.util.Scanner;


public class FahrenheitToCentigradeTemp {
    // multiplier so it isn't calculated each time
    static double multiplier = 5.0 / 9.0;

    public static void displayConversion(double f) {
        double c = (f - 32.0) * FahrenheitToCentigradeTemp.multiplier;
        // String.format rounds the representation
        System.out.println(String.format("%.3fF = %.3fC",f, c));
    } 

    public static void main(String[] args) {
        // try handling command-line arguments first
        if (args.length > 0) {
            for (int i = 0; i < args.length; i++) {
                Double f = Double.parseDouble(args[i]);
                FahrenheitToCentigradeTemp.displayConversion(f);
            }
            return;
        }

        // read from standard input if no command-line arguments
        Scanner scanner = new Scanner(System.in);
        System.out.print("(Send an interrupt signal or close the input stream to exit)\n\n");
        while (true) {
            System.out.print("enter a temperature (F): ");
            FahrenheitToCentigradeTemp.displayConversion(scanner.nextDouble());
        }
    }
}
