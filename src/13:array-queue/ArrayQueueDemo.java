/*
    Ernest Izdebski
    2023-03-30

    A demo of ArrayQueue.

    Copied (but not corrected) from class notes.
*/

public class ArrayQueueDemo {
    public static void main(String[] args) {
        String str;
        ArrayQueue queue = new ArrayQueue(4);
        str = "Queue has capacity ";
        System.out.println(str + queue.capacity());

        String names[] = {"Liam", "Breanna", "Nora", "Evie"};

        System.out.println(" Adding names: ");

        for (String s: names) {
            System.out.print(s + " ");
            queue.enqueue(s);
        }

        System.out.println("State of queue is : ");
        //System.out.println(queue); //toString
        queue.printNames();

        // Remove 2 names
        System.out.println("Removing 2 names : ");
        queue.dequeue();
        queue.dequeue();
        
        // Add a nmae
        System.out.println("Adding the name Abby: ");
        queue.enqueue("Abby");
        System.out.println("State of queue is : ");
        //System.out.println(queue); //toString
        queue.printNames();
    }
}
