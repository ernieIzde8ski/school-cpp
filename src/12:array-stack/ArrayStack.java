/*
    Ernest Izdebski
    2023-03-29

    An array on the stack.

    Copied from class notes, hence the fact that some things aren't
    to my liking (writing to standard error instead of throwing an
    exception and the array not being generic, for example).
*/


public class ArrayStack {
    private int[] s; // holds stack elements
    private int top; // stack pointer

    // constructor
    public ArrayStack(int capacity) {
        this.s = new int[capacity];
        this.top = 0; // stack pointer
    }

    public boolean empty() { return this.top == 0; }

    public void push(int x) {
        if (this.top == this.s.length) System.err.println("error: stack full");
        else {
            this.s[this.top] = x;
            ++this.top;
        }
    }

    public int pop() {
        if (this.empty()) {
            System.err.println("error: stack empty");
            return 0;
        } else {
            --this.top;
            return this.s[this.top];
        }
    }

    public int peek() {
        if (this.empty()) {
            System.err.println("error: stack empty");
            return 0;
        } else return this.s[this.top-1];
    }
}
