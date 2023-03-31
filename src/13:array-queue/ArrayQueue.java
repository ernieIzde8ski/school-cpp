/*
    Ernest Izdebski
    2023-03-30

    A queued array.

    Copied from class notes; all bad behavior is [sic] from Wolfer.
*/


public class ArrayQueue {
    private String[] q; // holds queue elements
    private int front; // next item to be removed
    private int rear;  // next slot to fill
    private int size;  // Number of items in queue

    // constructor
    public ArrayQueue(int capacity) {
        q = new String[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    public int capacity() { return q.length; }

    public void enqueue(String s) {
        if (size == q.length) System.err.println("Queue Full");
        else {
            ++size;
            q[rear] = s;
            ++rear;
            if (rear == q.length) rear = 0;
        }
    }

    public String peek() {
        if (empty()) {
            System.err.println("Queue Empty"); return " ";
        }
        return q[front];
    }

    public String dequeue() {
        if (empty()) {System.err.print("Queue Empty"); return "";}
        --size;
        String value = q[front]; // remove from front
        q[front] = null;
        ++front; // update front
        if (front == q.length) front = 0;
        return value;
    }

    public boolean empty() {
        return size == 0; //1or0
    }

    public void printNames() {
        System.out.println("front = " + front + "; ");
        System.out.println("rear = " + rear + "\n");
        for (int k=0; k < q.length; k++) {
            if (q[k] != null)
                System.out.println(k + " "+ q[k]);
            else
                System.out.println(k + " ?");
            if (k != (q.length-1)) System.out.println("\n");
        }
    }
}
