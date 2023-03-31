/*
    Ernest Izdebski
    2023-03-29

    A demo of ArrayStack.

    Copied but not corrected from class notes.
*/

public class ArrayStackDemo {
    public static void main(String[] args) {
        String str;
        ArrayStack st=  new ArrayStack(5);
        str = "pushing 10 20 onto the stack.";
        System.out.println(str);

        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        st.push(60);

        str = "Value at the top of the stack is ";
        System.out.println(str + st.peek());

        str = "poping and Printing all values: ";
        System.out.println(str);
        while (!st.empty())
            System.out.println(st.pop() + " ");
    }
}
