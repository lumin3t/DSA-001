#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
}; 

typedef struct node *NODE;
NODE root = NULL;

NODE createTree(char postfix[]) {
    NODE stack[20], temp;
    int top = -1;
    char symbol;

    for (int i = 0; (symbol = postfix[i]) != '\0'; i++) {
        temp = (NODE)malloc(sizeof(struct node)); // Allocate memory for a new node
        if (isalnum(symbol)) { // Operand
            temp->data = symbol; // Store the operand
            temp->llink = temp->rlink = NULL; // Initialize links to NULL
            stack[++top] = temp; // Push the node onto the stack
        } else { // Operator
            temp->data = symbol; // Store the operator
            temp->rlink = stack[top--]; // Right child
            temp->llink = stack[top--]; // Left child
            stack[++top] = temp; // Push the new subtree onto the stack
        }
    }
    return stack[top]; // Return the root of the tree
}

float eval(NODE root) {
    if (root == NULL) return 0; // Handle null case

    if (isdigit(root->data)) {
        return root->data - '0'; // Convert char to int
    }

    float leftVal = eval(root->llink); // Evaluate left subtree
    float rightVal = eval(root->rlink); // Evaluate right subtree

    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        default: return 0; // Handle unexpected cases
    }
}

int main() {
    printf("Try programiz.pro\n");
    char postfix[] = "33+";
    root = createTree(postfix);
    float ans = eval(root);
    printf("Ans: %f\n", ans);
    return 0;
}