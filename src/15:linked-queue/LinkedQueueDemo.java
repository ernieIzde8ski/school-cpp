/*
    Ernest Izdebski
    2023-03-31

    A demo of LinkedQueue.
*/

public class LinkedQueueDemo {
    public static void main(String[] args) {
        LinkedQueue queue = new LinkedQueue();
        
        //add 4 names
        System.out.println("Adding : enqueue : Amy Bob Chuck");
        queue.enqueue("Amy");
        queue.enqueue("Bob");
        queue.enqueue("Chuck");

        System.out.println("\nPrinting names in Queue\n");
        System.out.println(queue);

        System.out.println("\nRemoving : dequeue names:");
        queue.dequeue();
        queue.dequeue();

        System.out.println(queue);

        System.out.println("\nAdding names in queue: ");
        queue.enqueue("Freddy");
        queue.enqueue("Liam");
        queue.enqueue("Briana");

        System.out.println("\nPrinting names in stack\n");
        //queue.print()
        System.out.println(queue);
    }
}
