#### Array representation of trees

```c
#include <stdio.h>

void create(int tree[]) {
    int n;       // Number of nodes
    int val;     // Value to insert
    int i;       // Current position in array
    int k;       // Loop counter

    printf("no. of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of each node: ");
    for(k = 1; k <= n; k++) {    // Loop for each node
        scanf("%d", &val);        // Get value to insert
        i = 1;                    // Start at position 1 (root)

        // Find the correct position to insert
        while(tree[i] != 0) {     // While current position is not empty
            if(val < tree[i])     // If value is less than current node
                i = 2 * i;        // Go to left child (2*i)
            else                  // If value is greater than current node
                i = 2 * i + 1;    // Go to right child (2*i + 1)
        }

        tree[i] = val;            // Insert value at empty position
    }
}

int main() {
    int tree[20] = {0};          // Initialize array with zeros
    int i;

    create(tree);                 // Create the tree

    // Print the array representation
    for(i = 1; i < 20; i++)
        printf("%d ", tree[i]);

    return 0;
}
```

Let's understand this with an example:

Say we want to insert: 5, 3, 7

```
Array: [0, 5, 3, 7, 0, ...]
```

The tree would look like this:

```
      5
     / \
    3   7
```

### Operations on a BST

#### Insert operation:

![[Pasted image 20241221175028.png]]

#### Delete operation:

```
Function deleteNode(root, key):
    If root is NULL:
        Return NULL  # Key not found

    # If key is smaller, go left
    If key < root.data:
        root.left = deleteNode(root.left, key)

    # If key is larger, go right
    Else If key > root.data:
        root.right = deleteNode(root.right, key)

    # If key is same as root's data, it's the node to be deleted
    Else:
        # Case 1: Node has no children (leaf node)
        If root.left is NULL and root.right is NULL:
            Free root
            Return NULL

        # Case 2: Node has one child
        Else If root.left is NULL:
            temp = root.right
            Free root
            Return temp
        Else If root.right is NULL:
            temp = root.left
            Free root
            Return temp

        # Case 3: Node has two children
        Else:
            temp = findMin(root.right)  # Find the smallest node in the right subtree
            root.data = temp.data  # Replace root's data with the smallest node's data
            root.right = deleteNode(root.right, temp.data)  # Delete the smallest node

    Return root

Function findMin(node):
    While node.left is not NULL:
        node = node.left
    Return node

```
