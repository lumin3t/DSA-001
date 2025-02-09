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
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d ", root->data);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->llink);
        printf("%d ", root->data);
        inorder(root->rlink);
    }
}

// Main function
int main() {
    root = getnode();
    printf("Enter root data: ");
    scanf("%d", &root->data);
    create(root);
    
    printf("\nInorder Traversal: ");
    inorder(root);
    
    printf("\nPreorder Traversal: ");
    preorder(root);
    
    printf("\nPostorder Traversal: ");
    postorder(root);
    
    return 0;
}
