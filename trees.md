### Trees terminology

- **Root Node** - The starting node of the tree.
- **Sub-trees** - Subsections of the main tree.
- **Leaf Node** - The terminal node without children.
- **Path** - A connected series of edges.
- **Ancestor Node** - Preceding nodes on a path.
- **Descendant Node** - Succeeding nodes on a path.
- **Level Number** - Level assigned to each node.
- \*_Degree_ - Child count of a node.
- **In-degree** - Incoming edges to a node.
- **Out-degree** - Outgoing edges from a node.

#### Types of trees

- General
- Unary/ Binary/ Ternary/ N-ary Trees
- Binary search tree
- Forests
- Expression trees

> Other terminology: Parent, sibling, leaf node, depth, degree, edge (path), height,

Similar binary trees have same structure, copies are copies of eachother (structure and elements)

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

![image](https://github.com/user-attachments/assets/d619c656-ed9f-4ff0-a66b-cba7af8f8f1f)

```c
struct node {
	int data;
	struct node *rchild, *lchild;
};
typedef struct node *NODE;
NODE root = NULL;
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

### Expression tree

![image](https://github.com/user-attachments/assets/644906e7-2df2-4e11-843f-93c1037629db)

```c
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h> // For isalnum() and isalpha()

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
typedef struct node *NODE;

NODE root = NULL;

NODE create_tree(char postfix[]);
float eval(NODE root);

void main() {
    char postfix[20];
    float result;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    root = create_tree(postfix);
    result = eval(root);
    printf("Result = %f\n", result);
}

// Function to create an expression tree from a postfix expression
NODE create_tree(char postfix[]) {
    NODE temp, stack[20];  // Temporary node and stack for tree creation
    int i = 0, j = 0;
    char symbol;

    // Process each character in the postfix expression, traverse till null
    for (i = 0; (symbol = postfix[i]) != '\0'; i++) {
        // Create a new node for the current character
        temp = (NODE)malloc(sizeof(struct node));
        temp->lchild = temp->rchild = NULL;
        temp->data = symbol;

        if (isalnum(symbol)) {
            // If the symbol is an operand, push it onto the stack
            stack[j++] = temp;
        } else {
            // If the symbol is an operator
            temp->rchild = stack[--j];  // Pop the right child from the stack
            temp->lchild = stack[--j]; // Pop the left child from the stack
            stack[j++] = temp;         // Push the operator node back onto the stack
        }
    }

    return stack[--j]; // The last node in the stack is the root of the tree
}

// Function to evaluate the expression tree
float eval(NODE root) {
    float num;

    // Switch on the node's data to check if it's an operator or operand
    switch (root->data) {
        case '+':
            return eval(root->lchild) + eval(root->rchild); // Evaluate left and right and add
        case '-':
            return eval(root->lchild) - eval(root->rchild); // Evaluate left and right and subtract
        case '/':
            return eval(root->lchild) / eval(root->rchild); // Evaluate left and right and divide
        case '*':
            return eval(root->lchild) * eval(root->rchild); // Evaluate left and right and multiply
        case '^':
            return pow(eval(root->lchild), eval(root->rchild)); // Evaluate left and right and raise to power
        default:
            if (isalpha(root->data)) {
                // If the node is a variable, ask the user for its value
                printf("Enter the value of %c: ", root->data);
                scanf("%f", &num);
                return num;
            } else {
                // If the node is a numeric operand, convert it to a float
                return (root->data - '0');
            }
    }
}
```

### Binary tree traversal

```c
#include <stdio.h>
#include <stdlib.h>

// Binary tree traversal
struct Node {
    int data;
    struct Node *llink, *rlink;
};

typedef struct Node *NODE;
NODE root = NULL;

// Function to allocate memory for a new node
NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->llink = temp->rlink = NULL;
    return temp;
}

// Function to check if left child should be created
int isleftchild(NODE root) {
    printf("Do you want to create a left child for %d? Yes(1), No(0): ", root->data);
    int ch;
    scanf("%d", &ch);
    return ch;
}

// Function to check if right child should be created
int isrightchild(NODE root) {
    printf("Do you want to create a right child for %d? Yes(1), No(0): ", root->data);
    int ch;
    scanf("%d", &ch);
    return ch;
}

// Recursive function to create the binary tree
void create(NODE root) {
    if (isleftchild(root)) {
        root->llink = getnode();
        printf("Enter data for left child of %d: ", root->data);
        scanf("%d", &root->llink->data);
        create(root->llink);
    }
    if (isrightchild(root)) {
        root->rlink = getnode();
        printf("Enter data for right child of %d: ", root->data);
        scanf("%d", &root->rlink->data);
        create(root->rlink);
    }
}

// Preorder traversal: Root -> Left -> Right
void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

// Postorder traversal: Left -> Right -> Root
void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->llink)
        postorder(root->rlink);
        printf("%d ", root->data);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->llink);
        printf("%d ", root->ata);
        inorder(root->rlink);
    }
}

// Main function
int main() {
    root = getnode();
    printf("Enter root data: ");
    scanf("%d", &root->data);
    create(root)

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}
```

### Threaded binary tree
