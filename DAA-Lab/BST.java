class BinarySearchTree {
    static class Node {
        int key;
        Node left, right; //pointer, struct node type shi
        public Node(int item) { //constructor
            key = item;
            left = right = null;
        }
    }
    Node root;
    BinarySearchTree () {
        root = null;
    }
    void insert (int key) {
        root = insertionRec(root, key);
    } 
    Node insertionRec (Node root, int key) {
        if (root == null) {
            return new Node(key);
        } 
        if (key < root.key) {
            root.left = insertionRec(root.left, key);
        } else if(key > root.key) {
            root.right = insertionRec(root.right, key);
        }
        return root;
    }
    void delete (int key) {
        root = deletionRec(root, key);
    }
    Node deletionRec (Node root, int key) {
        if (root == null) {
            return root;
        } //traverse to node to be deleted
        if (key < root.key) {
            root.left = deletionRec(root.left, key);
        } else if(key > root.key) {
            root.right = deletionRec(root.right, key);
        }
        if (root.left == null) { //0 or 1 child
            return root.right;
        } else if (root.right == null) {
            return root.left;
        } else { //2 child
            root.key = minValue(root.right);
            root.right = deletionRec(root.right, root.key);
        }
        return root;
    }
    int minValue (Node root) {
        int minValue = root.key;
        while (root.left!= null) {
            minValue = root.left.key;
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
            System.out.print(root.key + " ");
            inorderRec(root.right);
        }
    }
    public static void main (String[] args) {
        System.out.println("Inserting 1, 3 and 4 in order in the BST: ");
        BinarySearchTree tree = new BinarySearchTree();
        tree.insert(1);
        tree.insert(3);
        tree.insert(4);
        tree.inorder();
	System.out.println();
	System.out.println("After deleting 1: ");
        tree.delete(1);
        tree.inorder();
    }
}
