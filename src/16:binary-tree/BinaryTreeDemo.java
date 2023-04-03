/*
    Ernest Izdebski
    2023-04-03

    A demo of BinaryTree.
*/

public class BinaryTreeDemo {
    public static void main(String[] args) {
        BinaryTree binTree = new BinaryTree();

        System.out.print("\n\npreorder traversal is : ");
        binTree.preorder();

        System.out.print("\n\ninorder traversal is : ");
        binTree.inorder();

        System.out.print("\n\npostorder traversal is : ");
        binTree.postorder();

        System.out.println();
    }
}
