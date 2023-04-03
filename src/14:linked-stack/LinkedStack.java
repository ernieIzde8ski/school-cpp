/*
    Ernest Izdebski
    2023-03-31

    No idea. Copied from class notes.
*/


public class LinkedStack {
    private class Node {
        String value;
        Node next;

        Node(String val, Node n) {
            value = val;
            next = n;
        }
    }

    private Node top = null;

    public boolean empty() { return top == null; }

    public void push(String s) {top = new Node(s, top); }

    public String pop() {
        if (empty()) {
            System.err.print("empty");
            return "";
        } else {
            String retValue = top.value;
            top = top.next;
            return retValue;
        }
    }

    public String peek() {
        if (empty()) { System.err.print("empty"); return ""; }
        else return top.value;
    }

    public void print() {
        Node p = top;
        while (p != null) {
            System.out.print(p.value + "\n");
            p = p.next;
        }
    }
}
