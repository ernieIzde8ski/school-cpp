/*
    Ernest Izdebski
    2023-01-15

    Tool for displaying estimated cost of a paint job, given rooms with
    specified dimensions and the price of paint per gallon.
*/

import java.util.Scanner;

public class PaintJobEstimator {
    
    // define constants
    static double paintGallonsPerSquareFoot = 1.0 / 115.0;
    static double laborHoursPerSquareFoot = 8.0 / 115.0;
    static double costPerLaborHour = 18.00;

    // define variables
    double paintPricePerGallon;
    double squareFeetOfPaint;

    // not quite a constructor but fairly close to it
    public void loadFromStandardInput() {
        Scanner keyboard = new Scanner(System.in);
        // get paint cost
        System.out.print("what is the current cost of paint per gallon? ");
        this.paintPricePerGallon = keyboard.nextFloat();
        // get area of rooms
        System.out.print("how many rooms? ");
        int totalRooms = keyboard.nextInt();
        
        this.squareFeetOfPaint = 0;
        System.out.println("How many square feet...");
        for (int i = 1; i <= totalRooms; i++) { // index at 1 for user legibility
            System.out.print("\t... in room #" + i + "? ");
            this.squareFeetOfPaint += keyboard.nextFloat();
        }
        System.out.println();
        keyboard.close();
    }


    // methods start here
    public double getTotalGallonsRequired() {
        return PaintJobEstimator.paintGallonsPerSquareFoot * this.squareFeetOfPaint;
    }

    public double getTotalLaborRequired() {
        return PaintJobEstimator.laborHoursPerSquareFoot * this.squareFeetOfPaint;
    }

    public double getPaintCost(double paintGallons) {
        return paintGallons * this.paintPricePerGallon;
    }

    public double getLaborCost(double laborHours) {
        return laborHours * PaintJobEstimator.costPerLaborHour;
    }
    
    public double sumTotalCost(double paintCost, double laborCost) {
        return paintCost + laborCost;
    }


    // entry point into program here
    public static void main(String[] args) {
        System.out.println();
        // load class
        PaintJobEstimator estimator = new PaintJobEstimator();
        estimator.loadFromStandardInput();

        // perform calculations
        double totalGallons = estimator.getTotalGallonsRequired();
        double totalLabor = estimator.getTotalLaborRequired();
        double paintCost = estimator.getPaintCost(totalGallons);
        double laborCost = estimator.getLaborCost(totalLabor);
        double totalCost = estimator.sumTotalCost(paintCost, laborCost);

        // display
        System.out.println("Total gallons of paint | " + totalGallons);
        System.out.println("Total hours of labor   | " + totalLabor);
        System.out.println("Total paint cost       | " + paintCost + " $");
        System.out.println("Total labor cost       | " + laborCost + " $");
        System.out.println("Final cost             | " + totalCost + " $");
    }
}
