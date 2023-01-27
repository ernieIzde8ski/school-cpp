/*
    Ernest Izdebski
    2023-01-27

    A demonstration of the Rectangle class.
*/


public class RectangleDemo {
    // program entry point
    public static void main(String[] args) {
        // initialize box
        Rectangle box = new Rectangle();
        box.setLength(10); box.setWidth(20);

        // display box
        System.out.println("Box length: " + box.getLength());
        System.out.println("Box width:  " + box.getWidth());
        System.out.println("Box area:  " + box.getArea());
    }
}
