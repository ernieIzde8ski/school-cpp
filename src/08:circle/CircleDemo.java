/*
    Ernest Izdebski
    2023-01-27

    A demonstration of the Circle class.
*/

import java.util.Arrays;
import java.util.Scanner;

public class CircleDemo {
    // function for displaying a circle's dimensions to standard output
    public static void displayCircle(Circle circle) {
        System.out.println("Circle(radius=" + circle.getRadius() + ")");
        System.out.println(": area:          " + circle.getArea());
        System.out.println(": diameter:      " + circle.getDiameter());
        System.out.println(": circumference: " + circle.getCircumference());
    }

    // program entry point
    public static void main(String[] args) {
        // handle command-line arguments if present, for debugging purposes
        if (args.length != 0) {
            for (String radius : args) {
                Circle circle = new Circle(Double.parseDouble(radius));
                CircleDemo.displayCircle( circle);
                System.out.println();
            }
        } else {
            // define
            Circle circle = new Circle();
            Scanner scanner = new Scanner(System.in);
            // populate
            System.out.print("Enter a radius: ");
            circle.setRadius(scanner.nextDouble());
            // display
            CircleDemo.displayCircle(circle);
        }
    }
}
