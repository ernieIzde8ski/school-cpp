/*
    Ernest Izdebski
    2023-01-16

    A simple addition game.
*/

import java.util.Scanner;
import java.util.Random;

public class MathTutor {
    // program entry point
    public static void main(String[] args) {
        System.out.print("Welcome to Math Game.\n  Enter -1 or an interrupt signal to exit.\n\n\n");

        // initialize variables
        int resp, n0, n1;
        // int n0, n1;
        Random rand = new Random();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            // display question
            n0 = rand.nextInt(1000);
            n1 = rand.nextInt(1000);
            System.out.print("  " + n0 + "\n+ " + n1 + "\n______\n  ");
            resp = scanner.nextInt();
            // handle input
            if (resp == -1) break;
            if (resp == (n0 + n1)) System.out.print("correct!\n\n");
            else System.out.print("wrong . . .\n\n");
        }
        System.out.println("Goodbye!");
    }
}
