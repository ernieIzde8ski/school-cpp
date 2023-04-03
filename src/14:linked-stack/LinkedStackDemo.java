/*
    Ernest Izdebski
    2023-03-31

    A demo of LinkedStack. Copied from class notes.
*/

public class LinkedStackDemo {
    public static void main(String[] args) {
        LinkedStack st = new LinkedStack();
        System.out.println("pushing : Amy Bob Chuck");
        st.push("Amy");
        st.push("Bob");
        st.push("Chuck");

        System.out.println("\nPrinting names in stack\n");
        st.print();

        System.out.println("\nPopping name:");
        String name = st.pop();
        System.out.println("\nPopped: " + name);

        System.out.println("\nPrinting names in stack\n");
        st.print();
    }
}
