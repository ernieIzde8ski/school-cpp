/*
    Ernest Izdebski
    2023-03-31

    No idea. Copied from class notes.
*/


public class LinkedQueue {
    private class Node {
        String value;
        Node next;

        Node(String val, Node n) {
            value = val;
            next = n;
        }
    }

    private Node front = null;
    private Node rear = null;

    /* public LinkedQueue() {
        value = "";
        next = null;
    }
    */

    public void enqueue(String s) {
        if (rear != null) {
            rear.next = new Node(s, null);
            rear = rear.next;
        } else {
            rear = new Node(s, null);
            front = rear;
        }
    }

    public boolean empty() {
        return front == null;
    }

    public String peek() {
        if (empty()) {
            System.out.println("empty");
            return " ";
        }
        else return front.value;
    }

    public String dequeue() {
        if (empty()) {
            System.out.println("empty");
            return " ";
        }
        else {
            String value = front.value;
            front = front.next;
            if (front == null) rear = null;
            return value;
        }
    }

    public void print() {
        Node p = front;
        while (p != null) {
            System.out.print(p.value);
            p = p.next;
        }
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        Node p = front;
        while (p != null) {
            str.append(p.value + " ");
            p= p.next;
        }
        return str.toString();
    }
}
