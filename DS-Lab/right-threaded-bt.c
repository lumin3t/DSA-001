#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the threaded binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
    int RT; // Thread bit: 1 if right pointer is a thread, 0 if it points to a child
};

// Define NODE as a pointer to a struct node for brevity
typedef struct node *NODE;

// Global head node (though generally better to pass it as a parameter)
NODE head = NULL;

// Function to create the initial tree (can be called multiple times to add nodes)
NODE create(int item, NODE head);

// Function to insert a node as the left child
void insert_left(int item, NODE ptr);

// Function to insert a node as the right child
void insert_right(int item, NODE ptr);

// Function to perform inorder traversal of the tree
void inorder(NODE head);

// Function to find the inorder successor of a node
NODE inorder_successor(NODE ptr);

int ch, i, n, item; // Removed 'choice' as it wasn't used

int main() {
    // clrscr();  // Remove or replace with a cross-platform clear screen if needed

    while (1) {
        printf("\n1. Create tree\n2. Inorder\n3. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of nodes to create\n");
                scanf("%d", &n);
                if (head == NULL) { // Create the head node if it doesn't exist
                    head = (NODE)malloc(sizeof(struct node));
                    if (head == NULL) {
                        perror("Memory allocation failed");
                        exit(1);
                    }
                    head->right = head;  // Head's right points to itself initially
                    head->left = NULL;
                    head->RT = 0;
                }
                for (i = 1; i <= n; i++) {
                    printf("Enter data for node %d: ", i);
                    scanf("%d", &item);
                    head = create(item, head); // Update head after each insertion
                }
                break;

            case 2:
                inorder(head);
                break;

            case 3:
                exit(0); // Use exit(0) for successful termination

            default:
                printf("Invalid choice\n");
        }
    }

    return 0; // Added return statement for main
}

NODE create(int item, NODE head) {
    NODE curptr, ptr;

    if (head->left == NULL) { // If the tree is empty (only head exists)
        insert_left(item, head);
        return head; // Return head after inserting the first node
    }

    curptr = head->left; // Start from the first actual node (left of head)

    while (curptr != head) {  // Traverse the tree until you find the right place
        ptr = curptr;       // Keep track of the parent node

        if (item < curptr->data) {
            if (curptr->left != NULL) {
                curptr = curptr->left;
            } else {
                break; // Found the place to insert as left child
            }
        } else { // item >= curptr->data
            if (item > curptr->data && curptr->RT == 1)
            {
                break; // Found the place to insert as right child
            }
            else if (item > curptr->data && curptr->RT == 0)
            {
                curptr = curptr->right;
            }
            else if(item == curptr->data)
            {
                printf("Duplicate data not allowed\n");
                return head;
            }
        }
    }

    if (item < ptr->data) {
        insert_left(item, ptr);
    } else {
        insert_right(item, ptr);
    }
    return head; // Return head after insertion
}

void insert_left(int item, NODE ptr) {
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
                        perror("Memory allocation failed");
                        exit(1);
                    }
    newnode->left = NULL;
    newnode->data = item;
    newnode->right = ptr; // Thread to the parent
    newnode->RT = 1;      // Mark as threaded
    ptr->left = newnode;
    ptr->RT = 0; // Parent is no longer threaded
}

void insert_right(int item, NODE ptr) {
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
                        perror("Memory allocation failed");
                        exit(1);
                    }
    newnode->left = NULL;
    newnode->data = item;
    newnode->right = ptr->right; // Inherit the thread from the parent
    newnode->RT = ptr->RT;      // Inherit the thread bit from the parent
    ptr->right = newnode;
    ptr->RT = 0; // Parent is no longer threaded
}

void inorder(NODE head) {
    if (head == NULL || head->left == NULL) { // Check if the tree is empty
        printf("\nNo nodes\n");
        return;
    }

    NODE temp = head->left; // Start from the first node in the inorder sequence

    while (temp != head) {
        printf("%d=>", temp->data);
        temp = inorder_successor(temp);
    }
    printf("\n"); // Add a newline after printing the inorder sequence
}

NODE inorder_successor(NODE ptr) {
    if (ptr->RT == 1) { // If right pointer is a thread, return it
        return ptr->right;
    }

    NODE temp = ptr->right; // Otherwise, go to the right subtree
    while (temp->left != NULL) { // Find the leftmost node in the right subtree
        temp = temp->left;
    }
    return temp;
}