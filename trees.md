A **Binary Tree** is a hierarchical data structure where each node has at most two children, typically referred to as the left and right children. The tree starts with a root node, and every node can have zero, one, or two child nodes.

![image](https://github.com/user-attachments/assets/0eabe9a8-98ef-478c-83ae-e73c7be45286)

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

---

### Types of Binary Trees:

![image](https://github.com/user-attachments/assets/68fde9bc-e716-41d3-8339-0e2a2fb2213c)

1. **Full Binary Tree**: Every node has either zero or exactly two children.
2. **Complete Binary Tree**: Every level of the tree is completely filled, except possibly for the last level, which is filled from left to right.
3. **Perfect Binary Tree**: All interior nodes have two children, and all leaf nodes are at the same level.
4. **Balanced Binary Tree**: The height of the left and right subtrees of any node differs by at most 1.
5. **Degenerate (or Pathological) Tree**: Each parent node has only one child, making it essentially a linked list.
6. **Binary Search Tree (BST)**: A binary tree where for every node, the left child’s value is less than the node’s value, and the right child’s value is greater than the node’s value.

#### Applications:

##### Real-time applications of Binary Trees

- [DOM in HTML.](https://www.geeksforgeeks.org/dom-document-object-model/)
- File explorer
- Evaluate an expression
- Routing Algorithms

##### Hierarchical Data Representation

    - File systems and folder structures.
    - Organizational charts.
    - XML/HTML parsing.

##### Applications of Binary Search Trees (BST)

Efficient searching, insertion, and deletion operations (average time complexity: O(log n) and best time complexity : O(Log n) in case of [AVL](https://www.geeksforgeeks.org/introduction-to-avl-tree/) and [Red Black](https://www.geeksforgeeks.org/introduction-to-red-black-tree/) Trees).
Implementing associative arrays, maps, and sets with sorted order of data.

##### Applications of Binary Heap Tree

- Expression Trees
  - Representing arithmetic expressions where internal nodes are operators and leaf nodes are operands.
  - Used in compilers and calculators.
- Huffman Coding Tree
  - Used in data compression algorithms (e.g., Huffman coding for lossless compression).
- Decision Trees
  - Machine learning algorithms for classification and regression problems.
  - Representing conditional decision processes.
- Traversal-Based Operations
  - Preorder, inorder, and postorder traversals for various computations like expression evaluation or tree reconstruction.

Other terminology: Parent, sibling, leaf node, depth, degree, edge (path), height

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

#### Linked list representation

![image](https://github.com/user-attachments/assets/d619c656-ed9f-4ff0-a66b-cba7af8f8f1f)

```c
struct node {
	int data;
	struct node *rchild, *lchild;
};
typedef struct node *NODE;
NODE root = NULL;
```

### Binary tree traversal

![image](https://github.com/user-attachments/assets/786a2748-da27-4843-bc28-0c1257cbe470)

1. **Inorder (Left, Root, Right)**: 2 3 5 6 7 9
2. **Preorder (Root, Left, Right)**: 5 3 2 7 6 9
3. **Postorder (Left, Right, Root)**: 2 3 6 9 7 5

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
    //Create node for tree, init rlink and llink to NULL
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

### BST

Special varient where the left child has value lesser than root and right child has value greater than root

- left skewed
- right skewed

### Operations on a BST

#### Search operation:

![search op](https://github.com/user-attachments/assets/1e696e22-12f8-45e9-be5a-f76ef6d1e1e9)

#### Insert operation:

![[Pasted image 20241221175028.png]]

#### Delete operation:

- No child
  ![image](https://github.com/user-attachments/assets/0dab8f09-6d82-4216-ade7-b6670519c288)

- One child
  ![image](https://github.com/user-attachments/assets/aa78b894-a23f-436d-a9ac-78e04dbc7a04)

- Two children
  (rightmost child of the left subtree or the leftmost child of the right subtree, these give inorder predecessor and succerssors respectively.)
  ![image](https://github.com/user-attachments/assets/3dd3988a-b102-46a7-baa2-5f2d04acd77c)

##### Lab program for operations on BST

```c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct node {
    int data;                  // Data stored in the node
    struct node *llink;        // Pointer to the left child
    struct node *rlink;        // Pointer to the right child
};
typedef struct node *NODE;

// Function prototypes
NODE insertion(NODE);
NODE deletion(NODE);
void inorder(NODE);
NODE getnode();

void main() {
    int option;
    NODE root;

    clrscr();  // Clear screen
    root = getnode();  // Initialize the root node
    printf("Enter the data for root node\n");
    scanf("%d", &root->data);

    // Main menu loop
    while (1) {
        printf("\nTree operations\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Insert an element
                root = insertion(root);
                getch();  // Wait for a key press
                clrscr(); // Clear screen
                break;

            case 2: // Delete an element
                root = deletion(root);
                getch();
                clrscr();
                break;

            case 3: // Display the tree in inorder traversal
                printf("\nInorder traversal\n");
                inorder(root);
                getch();
                clrscr();
                break;

            case 4: // Exit the program
                exit(0);

            default: // Invalid option
                printf("Invalid choice\n");
        }
    }
}

// Function to insert an element into the binary tree
NODE insertion(NODE root) {
    NODE prev, temp, temp1;
    int item;
    temp1 = getnode();  // Create a new node
    printf("Enter the data: ");
    scanf("%d", &temp1->data);
    printf("%d is successfully inserted\n", temp1->data);
    item = temp1->data;  // Get the data to be inserted
    prev = NULL;         // Initialize parent node
    temp = root;         // Start traversal from root
    // Traverse the tree to find the correct position
    while (temp != NULL) {
        prev = temp;  // Keep track of the parent node
        if (item < temp->data) {
            temp = temp->llink;  // Move to the left child
        } else {
            temp = temp->rlink;  // Move to the right child
        }
    }
    // Attach the new node as a left or right child
    if (item < prev->data) {
        prev->llink = temp1;  // Attach as left child
    } else {
        prev->rlink = temp1;  // Attach as right child
    }
    return root;  // Return the updated tree
}

// Function to allocate memory for a new node
NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));  // Allocate memory for the node
    temp->llink = temp->rlink = NULL;          // Initialize child pointers to NULL
    return temp;
}

// Function to delete an element from the binary tree
NODE deletion(NODE root) {
    NODE cur, parent, suc, q;
    int item;

    if (root == NULL) {
        printf("No elements in tree\n");
        return root;  // If tree is empty, return
    }

    printf("Enter the element to be deleted: ");
    scanf("%d", &item);

    parent = NULL;  // Initialize parent node
    cur = root;     // Start traversal from root

    // Traverse the tree to find the node to delete
    while (cur != NULL && item != cur->data) {
        parent = cur;  // Keep track of parent node
        if (item < cur->data) {
            cur = cur->llink;  // Move to the left child
        } else {
            cur = cur->rlink;  // Move to the right child
        }
    }

    // If the element is not found
    if (cur == NULL) {
        printf("%d not found", item);
        return root;
    }

    // Case 1 and 2: Node has 0 or 1 child
    if (cur->llink == NULL) {
        q = cur->rlink;  // Assign the right child (or NULL)
    } else if (cur->rlink == NULL) {
        q = cur->llink;  // Assign the left child
    } else {
        // Case 3: Node has 2 children
        suc = cur->rlink;  // Leftmost child of the right subtree
        while (suc->llink != NULL) {
            suc = suc->llink;
        }
        suc->llink = cur->llink;  // Link left subtree of the deleted node
        q = cur->rlink;           // Assign right subtree
    }

    // Attach the replacement node to the parent
    if (cur == parent->llink) {
        parent->llink = q;
    } else {
        parent->rlink = q;
    }

    free(cur);  // Free memory for the deleted node
    printf("%d is successfully deleted\n", item);
    return root;
}

// Function for inorder traversal (Left -> Root -> Right)
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->llink);    // Traverse the left subtree
        printf("%d=>", root->data);  // Print the root node data
        inorder(root->rlink);    // Traverse the right subtree
    }
}
```

### Expression tree

![image](https://github.com/user-attachments/assets/644906e7-2df2-4e11-843f-93c1037629db)

**Infix**: Inorder
**Prefix**: Preorder
**Postfix**: Postorder

#### Lab program for evaluation of expression tree

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
}
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

#### Sorting of BST :

Construct a BST and perform inorder traversal

### Threaded Binary Tree:

In a linked representation of a binary tree, the number of null links (null pointers) are actually more than nonnull pointers. Almost (n+1) null pointers where theres 2n in total!!

A **threaded binary tree** is a binary tree in which **null pointers** (left and right pointers of leaf nodes) are replaced with **threads** that point to the in-order predecessor or successor of the node. According to this idea we are going to replace all the null pointers by the appropriate pointer values called threads.
We gotta distinguish normal pointer and a thread. So, we have these 5 fields:
![image](https://github.com/user-attachments/assets/73640c60-b666-4df9-9fa6-15f345585820)

### Types of Threading:

##### 1. **One-Way Threading**:

![image](https://github.com/user-attachments/assets/61f7c39a-ab31-4827-856c-85ca10b2332b)

In **one-way threading**, only one of the null pointers (usually the right pointer) is replaced by a thread. A thread points to the **in-order successor** of the node. This allows for efficient in-order traversal (going to the next node in the traversal sequence) without needing extra data structures.

- **Advantages**: Saves memory by utilizing null pointers for efficient traversal.
- **Disadvantages**: One-way threading limits bidirectional traversal; for example, moving backwards in the tree isn't possible without a different structure.

##### 2. **Two-Way Threading**: ![image](https://github.com/user-attachments/assets/128fcea8-18e3-47ff-bca9-41b2e897f15d)

- **Advantages**: Bidirectional traversal is possible. Both forward and backward movements through the tree are supported, making traversal more flexible.
- **Disadvantages**: More complex implementation and potentially more memory usage compared to one-way threading because both null pointers are utilized for threading.

##### 3. Two-Way Threading with Header node

![image](https://github.com/user-attachments/assets/03602eaf-d072-461b-a4fb-f6c60e132b29)
A **Two-Way Threaded Binary Tree with a Header Node** is a binary tree where both **null left and right pointers** of leaf nodes are replaced with **threads** that point to the **in-order predecessor** and **in-order successor**. A **header node** is added to simplify traversal, pointing to the first and last nodes of the tree. This allows **efficient in-order traversal** without recursion or a stack.

##### Advantages of Threaded Binary Trees:

- **Efficient Traversal**: In-order, pre-order, and post-order traversals can be done without recursion or a stack, saving memory.
- **Space Optimization**: Replaces null pointers with threads, saving additional memory.
- **Faster Traversal**: Threaded binary trees make traversal faster by eliminating the need for a stack or queue.

##### Disadvantages of Threaded Binary Trees:

- **Complexity in Construction**: Constructing and maintaining threaded binary trees is more complex than regular binary trees.
- **Insertion and Deletion Complexity**: Inserting or deleting nodes can require additional handling to update the threads correctly, adding overhead.
- **Limited Use Cases**: Threaded binary trees are mostly used when traversal speed is a priority and may not be suitable for applications where frequent insertions and deletions are required.

#### Lab program for Right threaded Binary Tree (COPY PASTED)

```c
#include <stdio.h>
#include <stdlib.h>  // Include stdlib for malloc
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int RT;  // Right thread flag
};
typedef struct node *NODE;
NODE head = 0;

NODE create(int item, NODE head);
void insert_left(int item, NODE ptr);
void insert_right(int item, NODE ptr);
void inorder(NODE head);
NODE inorder_successor(NODE ptr);

int ch, i, n, item, choice;

void main()
{
    // You already have a global head variable, no need to declare it here
    head = (NODE)malloc(sizeof(struct node));
    head->right = head;  // Points to itself
    head->left = 0;      // No left child initially
    head->RT = 0;        // Right thread flag
    while (1)
    {
        printf("\n1. Create tree\n2. Inorder\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number of nodes to create: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("Enter data for node %d: ", i);
                scanf("%d", &item);
                head = create(item, head);
            }
            break;
        case 2:
            inorder(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}

NODE create(int item, NODE head)
{
    NODE curptr, ptr;
    if (head->left == 0)
    {
        insert_left(item, head);
        return head;
    }
    curptr = head->left;
    while (curptr != head)
    {
        ptr = curptr;
        if (item < curptr->data)
        {
            if (curptr->left != 0)
                curptr = curptr->left;
            else
                break;
        }
        else
        {
            if (item > curptr->data)
            {
                if (curptr->RT == 0)
                    curptr = curptr->right;
                else
                    break;
            }
        }
    }
    if (item < curptr->data)
    {
        insert_left(item, ptr);
        return head;
    }
    else
    {
        if (item > curptr->data && curptr->RT == 1)
            insert_right(item, ptr);
    }

    return head;
}

void insert_left(int item, NODE ptr)
{
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->data = item;
    ptr->left = newnode;
    newnode->right = ptr;
    newnode->RT = 1;  // Mark it as a right thread
}

void insert_right(int item, NODE ptr)
{
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->data = item;
    NODE temp = ptr->right;
    ptr->right = newnode;
    newnode->right = temp;
    ptr->RT = 0;
    newnode->RT = 1;  // Mark it as a right thread
}

void inorder(NODE head)
{
    NODE temp;
    if (head->left == 0)
    {
        printf("\nNo nodes\n");
        return;
    }
    temp = head;
    while (1)
    {
        temp = inorder_successor(temp);
        if (temp == head)
            return;
        printf("%d => ", temp->data);
    }
}

NODE inorder_successor(NODE ptr)
{
    NODE temp = ptr->right;
    if (ptr->RT == 1)
        return temp;
    while (temp->left != 0)
        temp = temp->left;
    return temp;
}

```
