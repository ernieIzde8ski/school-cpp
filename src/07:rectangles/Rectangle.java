/*
    Ernest Izdebski
    2023-01-27

    A Rectangle class, with methods for handling properties like length, width, and area.
*/


public class Rectangle {
    // properties
    private double len;
    private double wid;

    // constructors
    Rectangle(double len, double wid ) {
        this.len = len;
        this.wid = wid;
    }
    
    Rectangle() { this(0.0, 0.0); }

    // setters
    public void setLength(double len) { this.len = len; }
    public void setWidth(double wid) { this.wid = wid; }

    // getters
    double getLength() { return this.len; }
    double getWidth() { return this.wid; }
    
    double getPerimeter() { return (this.len * 2.0) + (this.wid * 2.0); }
    double getArea() { return this.len * this.wid; }
}
