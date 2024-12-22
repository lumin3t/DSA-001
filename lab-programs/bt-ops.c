#include <stdio.h>
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
        suc = cur->rlink;  // Find the inorder successor
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
