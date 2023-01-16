/*
    Ernest Izdebski
    2023-01-11

    A Java program that will accept three values from the keyboard and
    display their average to the screen.
*/

import java.util.Scanner;

public class AverageScore {
    public static void main(String[] args) { // main method
        Scanner scanner = new Scanner(System.in);
        System.out.println("please input 3 numbers"); // prompt for input
        float[] numbers = {
            scanner.nextFloat(), scanner.nextFloat(), scanner.nextFloat()
        }; // create array sized 3
        float average = (numbers[0] + numbers[1] + numbers[2]) / 3; // get array average
        System.out.println("Average: " + average); // display
    }
}
