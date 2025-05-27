import java.util.*;
 class BST {
    //Node class
    static class Node {
        int key;
        Node left, right;
        //Node constructor
        public Node(int item) {
            key = item;
            left = right = null;
        }
    }
    Node root; //init global typa
    BST () { //constuctor for BST
        root = null;
    }
    void insert (int key) {
        root = insertRec(root, key);
    }
    Node insertRec (Node root, int key) {
        if (root == null) {
            return new Node(key);
        }
        if (key < root.key) {
            root.left = insertRec(root.left, key);
        } else if (key > root.key) {
            root.right = insertRec(root.right, key);
        }
        return root;
    }
    void delete ( int key) {
        root = deleteRec(root, key);
    }
    Node deleteRec(Node root, int key) {
        if (root == null) return root;
        if (key < root.key) {
            root.left = deleteRec(root.left, key);
        } else if (key > root.key) {
            root.right = deleteRec(root.right, key);
        } else {
            if (root.left == null) return root.right;
            else if (root.right == null) return root.left;
            root.key = minValue(root.right);
            root.right = deleteRec(root.right, root.key);
        }
        return root;
    }
    int minValue (Node root) {
        while(root.left != null) {
            root = root.left;
        }
        return root.key;
    }
    void inorder () {
        inorderRec(root);
    }
    void inorderRec (Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(" "+ root.key);
            inorderRec(root.right);
        }
    }
    public static void main(String[] args) {
        BST tree = new BST();

        // Insert elements
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);

        System.out.println("Inorder traversal:");
        tree.inorder();

        // Delete operations
        System.out.println("\n\nDelete 20:");
        tree.delete(20);
        tree.inorder();

        System.out.println("\n\nDelete 30:");
        tree.delete(30);
        tree.inorder();

        System.out.println("\n");
    }
}