/*
    Ernest Izdebski
    2023-03-06

    A class that implements a linked list.
*/

/* private class for nodes, supporting generics instead of exclusively strings */
class Node<T> {
    /* attributes */
    T value;
    Node<T> next;

    /* constructors */
    Node(T value, Node<T> next) {
        this.value = value;
        this.next = next;
    }

    // calls the other constructor with null for the 'next' value
    Node(T value) { this(value, null); }
}

public class LinkedList<T> {
    /* attributes */
    private Node<T> first; // initial element
    private Node<T> last;  // final element

    /* constructors */
    // empty constructor
    LinkedList() { this.first = null; this.last = null; }

    /* methods */
    public boolean isEmpty() { return this.first == null; }

    // returns length of list
    public int size() {
        int resp = 0;
        Node node = this.first;
        while (node != null) {
            ++resp;
            node = node.next;
        }
        return resp;
    }

    // appends an element to the list
    public void add(T elem) {
        if (this.isEmpty()) {
            // initialize list with new element
            this.first = new Node<T>(elem);
            this.last = this.first;
        } else {
            // create node at end of list
            this.last.next = new Node<T>(elem);
            this.last = this.last.next;
        }
    }

    // inserts an element at a given position
    public void add(int index, T elem) {
        if (index < 0 || index > this.size())
            throw new IndexOutOfBoundsException("got: " + index);
        if (index == 0) {
            // special case: new elements start at the beginning
            // and have the original first element as their node
            this.first = new Node<T>(elem, this.first);
            if (this.last == null) this.last = this.first;
            return;
        }
        // finding the node that precedes the position of the node we want
        Node<T> pred = this.first;
        for (int k = 1; k < index; k++) pred = pred.next;
        // move new node into position
        pred.next = new Node<T>(elem, pred.next);
        // check if new node is the last node
        if (pred.next.next == null) this.last = pred.next;
    }

    // Removes a node at a given index from the array. Returns the
    // value of the node.
    public T remove (int index) {
        if (index < 0 || index >= this.size())
            throw new IndexOutOfBoundsException("got: " + index);
        T resp;
        // special case: first element
        if (index == 0) {
            resp = this.first.value;
            this.first = this.first.next;
            if (this.first == null) this.last = null;
        } else {
            // find node at position index-1
            Node<T> pred = this.first;
            for (int k = 1; k < index; k++) pred = pred.next;
            // store value to return and pop the node
            resp = pred.next.value;
            pred.next = pred.next.next;
            // null check
            if (pred.next == null) this.last = pred;
        }
        return resp;
    }

    // Removes an element matching the given parameter.
    // Returns success status.
    public boolean remove(T elem) {
        if (this.isEmpty()) return false;
        // special case for initial equals
        if (elem.equals(this.first.value)) {
            this.first = this.first.next;
            if (this.first == null) this.last = null;
            return true;
        }
        // looping over array to find the preceding node
        Node<T> pred = this.first;
        while (pred.next != null && !pred.next.value.equals(elem))
            pred = pred.next;
        // end of array reached, no matching node found
        if (pred.next == null) return false;
        // pred.next.value is matching, so discard pred.next
        // perform null check in case pred.next.next was the last element
        pred.next = pred.next.next;
        if (pred.next == null) this.last = null;
        return true;
    }

    // Traverses the list and prints all of its elements to standard output
    // Assumes that T.value supports type-casting to strings
    public void print() {
        System.out.print("[\t");
        for (Node<T> ref = this.first; ref != null; ref = ref.next)
            System.out.print(ref.value + "\t");
        System.out.print("]\n");
    }

    // Generates a string representation of the list
    // Assumes that T.value supports type-casting to strings
    public String toString() {
        StringBuilder resp = new StringBuilder("[\t");
        // walk through list as a for loop, appending values to builder
        for (Node<T> ref = this.first; ref != null; ref = ref.next)
            resp.append(ref.value + "\t");
        resp.append("]");
        return resp.toString();
    }
}
