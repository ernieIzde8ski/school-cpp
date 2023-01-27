/*
    Ernest Izdebski
    2023-01-27

    A Circle class, for handling radius, area, and such.
*/


public class Circle {
    // properties
    static double PI = 3.14159;
    double radius;

    // constructors
    Circle(double radius) { this.radius = radius; }
    Circle() { this(0.0); }

    // setters
    void setRadius(double radius) { this.radius = radius; }

    // getters
    double getRadius() { return this.radius; }
    double getDiameter() { return this.radius * 2; }
    double getCircumference() { return this.PI * this.radius * 2; }
    double getArea() { return this.PI * this.radius * this.radius; }
}
