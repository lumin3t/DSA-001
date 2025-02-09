#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h> // For isalnum() and isalpha()

// Define the structure of a binary tree node
struct node {
    int data;                // Data stored in the node (operand or operator)
    struct node *lchild;     // Pointer to the left child
    struct node *rchild;     // Pointer to the right child
};
typedef struct node *NODE;

// Global root node for the expression tree
NODE root = NULL;

// Function prototypes
NODE create_tree(char postfix[]);
float eval(NODE root);

int main() {
    char postfix[20];
    float result;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    // Create the expression tree from the postfix expression
    root = create_tree(postfix);

    // Evaluate the expression tree
    result = eval(root);

    // Print the result
    printf("Result = %f\n", result);

    return 0;
}

// Function to create an expression tree from a postfix expression
NODE create_tree(char postfix[]) {
    NODE temp, stack[20];  // Temporary node and stack for tree creation
    int i = 0, j = 0;      // Iterators for postfix and stack
    char symbol;

    // Process each character in the postfix expression
    for (i = 0; (symbol = postfix[i]) != '\0'; i++) {
        // Create a new node for the current character
        temp = (NODE)malloc(sizeof(struct node));
        temp->lchild = temp->rchild = NULL; // Initialize children as NULL
        temp->data = symbol;               // Assign the symbol to the node

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
