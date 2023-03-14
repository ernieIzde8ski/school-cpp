/*
    Ernest Izdebski
    2023-03-06

    A demo of the LinkedList class.
*/


// constants for LinkedListDemo.main
class Constants {
    // values to initialize the linked list with
    public static int rangeLowerBound = 0;
    public static int rangeUpperBound = 10;
    public static int rangeStep = 2;

    // index/value of newly inserted item
    public static int addIndex = 2;
    public static int addValue = 3;

    // index of newly popped item
    public static int popIndex = 5;

    // value of newly popped item
    public static int popValue = 2;
}

public class LinkedListDemo {
    // simple range function
    // should be obvious
    public static int[] range(int start, int stop, int step) {
        int len = -Math.floorDiv(-(stop - start), step); // ceil div
        int[] resp = new int[len];
        int j = start;
        for (int i = 0; i < len; i++) {
            resp[i] = j;
            j += step;
        }
        return resp;
    }

    // overload with step defaulting to 1
    public static int[] range(int start, int stop) {
        return LinkedListDemo.range(start, stop, 1);
    }

    public static void main(String[] args) {
        System.out.println("This is a demo of the LinkedList class.");
        //// constructor
        LinkedList<Integer> linkedList = new LinkedList<Integer>();
        System.out.println("Created empty list: " + linkedList.toString());
        //// first implementation of add method
        System.out.println();
        System.out.println("Appending initial values to string...");
        int[] range = LinkedListDemo.range(Constants.rangeLowerBound, Constants.rangeUpperBound,
                                           Constants.rangeStep);
        for (int i : range) linkedList.add(i);
        linkedList.print();
        //// second implementation of add method
        System.out.println("\nAdding value " + Constants.addValue + " at index " +
                           Constants.addIndex + ".");
        linkedList.add(Constants.addIndex, Constants.addValue);
        linkedList.print();
        //// first implementation of remove method
        System.out.println("\nPopping value at index " + Constants.popIndex + ".");
        int value = linkedList.remove(Constants.popIndex);
        System.out.println("Node had value " + value + "." );
        linkedList.print();
        //// second implementation of remove method
        System.out.println("\nPopping element with value " + Constants.popValue + ".");
        // have to explicitly type-cast so that the overload doesn't
        // default to the first implementation
        boolean success = linkedList.remove((Integer)Constants.popValue);
        System.out.println("Node removal was " + (success ? "" : "un") + "successful.");
        linkedList.print();
    }
}
