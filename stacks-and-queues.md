# Stacks

#### Example: Array representation of Stack and it's operations

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int stack[SIZE];
int push (int top) {
    int item;
    if (top == SIZE-1) {
        printf("Stack is full");
        return top;
    }
    printf("Enter number to be pushed: ");
    scanf("%d", &item);
    stack[++top] = item;
    printf("Item pushed to stack\n");
    return top;
}
int pop (int top) {
    if (top == -1) {
        printf("Stack is empty");
        return top;
    }
    printf("%d Element popped", stack[top]);
    top--;
    return top;
}
void display (int top) {
    if (top == -1) {
        printf("Stack is empty");
    }
    printf("\nStatus of stack: ");
    for (int i =0; i<SIZE; i++) {
        printf("%d ", stack[i]);
    }
}
int main() {
    // Write C code here
    printf("UwU");
    int top=-1, option;
    while (1) {
        printf("\nEnter choice: ");
    scanf("%d", &option);
    switch(option) {
        case 1: top = push(top);
                break;
        case 2: top = pop(top);
                break;
        case 3: display(top);
                break;
        case 4: exit(0);
                break;
        default: printf("Invalid choice");
                break;
    }
    }
    return 0;
}
```

### Infix to Postfix and Prefix using Stacks:

```c
// Infix to Postfix and Prefix using stacks
#include <stdio.h>
#include <string.h>
char stack[20], infix[20], postfix[20];
int top = -1;
void push(char symbol) {
  stack[++top] = symbol;
}
char pop() {
    return stack[top--];
}
int preceed(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        case ')':
        case '(': return 0;
        case '#': return -1;
    }
    return 0;
}
void infixtopostfix() {
    int len = strlen(infix);
    int j = 0;
    char symbol;
    push('#'); // Initialize stack with #
    for (int i = 0; i < len; i++) {
        symbol = infix[i]; // Get symbol from infix expression
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while (stack[top] != '(') {
                    postfix[j++] = pop();
                }
                pop(); // Pop '(' from stack
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (preceed(stack[top]) >= preceed(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol; // Add operands directly to postfix
        }
    }
    while (top > 0) { // Pop remaining operators
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate postfix expression
}
int main() {
    printf("Enter infix expression: ");
    scanf("%s", infix);
    // Convert infix to postfix
    infixtopostfix();
    printf("Postfix expression: %s\n", postfix);
    // Prepare for prefix conversion by reversing infix expression
    int len = strlen(infix);
    for (int h = 0; h < len / 2; h++) {
        char temp = infix[h];
        infix[h] = infix[len - h - 1];
        infix[len - h - 1] = temp;
    }
    // Swap '(' and ')' for prefix conversion
    for (int h = 0; h < len; h++) {
        if (infix[h] == '(') {
            infix[h] = ')';
        } else if (infix[h] == ')') {
            infix[h] = '(';
        }
    }
    // Convert modified infix (for prefix) to postfix
    infixtopostfix();
    // Reverse postfix to get prefix expression
    printf("Prefix expression: ");
    for (int i = strlen(postfix) - 1; i >= 0; i--) {
        printf("%c", postfix[i]);
    }
    printf("\n");
    return 0;
}
```

### Recursion

Recursion is a technique that breaks down a complex problem into smaller problems, and then solves those smaller problems to solve the original problem. It's used in many disciplines, including computer science, mathematics, linguistics, and logic

Here are example programs in C for each of the requested recursive algorithms:

---

### 1. Factorial

```c
#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n = 5; // Example value
    printf("Factorial of %d is %d\n", n, factorial(n));
    return 0;
}
```

### 2. Binomial Coefficient (nCr)

```c
#include <stdio.h>

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main() {
    int n = 5, k = 2; // Example values
    printf("Binomial Coefficient C(%d, %d) is %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}
```

### 3. Greatest Common Divisor (GCD)

```c
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a = 48, b = 18; // Example values
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}
```

### 4. Fibonacci Sequence

```c
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Number of terms
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
```

### 5. Tower of Hanoi

```c
#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, C are the rods
    return 0;
}
```

---

## Queues

#### Example: Implementation using array and queue operations

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int rear = -1, front = -1, queue[20];

void main() {
    int ch = 1, option;
    clrscr();

    while (ch) {
        printf("Queue operations\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                qinsert();
                getch();
                clrscr();
                break;
            case 2:
                qdelete();
                getch();
                clrscr();
                break;
            case 3:
                qdisplay();
                getch();
                clrscr();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");
                break;
        }
    }
}

qinsert() {
    int num;
    if (rear == (SIZE - 1)) {
        printf("Queue is full\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &num);
    queue[++rear] = num;
    printf("%d is successfully inserted\n", num);
    if (front == -1)
        front++;
    return;
}

qdelete() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear) {
        printf("Deleted element: %d", queue[front]);
        front = -1;
        rear = -1;
        return;
    }
    printf("Deleted element: %d", queue[front]);
    front++;
    return;
}

qdisplay() {
    int i;
    if (front == -1) {
        printf("queue is empty\n");
        return;
    }
    printf("status of queue is\n");
    for (i = front; i <= rear; i++)
        printf("%d\t", queue[i]);
}
```

---

### 1. Circular Queue

In a **circular queue**, the last position connects back to the first, forming a circle. This structure avoids the need to shift elements and uses the space more efficiently. It works on FIFO principle and forms what's called as a "Ring buffer"
![[Pasted image 20241215012906.png]]

```c
#include<stdio.h>
#define SIZE 5  // Define the size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) { //Similar to the cache thing, making usre it doesnt extend 5
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;  // First element case
    rear = (rear + 1) % SIZE; //basically rear++ unless it extends 5, it goes back to 0 etc
    queue[rear] = value;
    printf("%d added to the queue\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d removed from the queue\n", queue[front]);
    if (front == rear) { //i.e there is only one element
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE; //Doing front++ basicaly to move ptr
    }
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break; //Stop when i reaches the last element
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Queue Operations\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

```

---

### 2. Deque (Double-Ended Queue)

A **deque** allows insertion and deletion from both ends. It can be **implemented with a singly linked list**

#### Code Example (Deque)

```c
NODE getnode() {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node)); //Initialize the memory size for the new node created
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if memory allocation fails
    }
    return temp;
}
NODE insert_front (NODE front) {
    NODE temp;
    temp = getnode(); //Allocate memory for new node
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = front; //New node links to current first node
    front = temp; //First node is now temp
    return front;
}
NODE delete_front (NODE front) {
    NODE temp;
    if (front == NULL) {
        printf("Dequeue is empty");
        return front;
    }
    temp = front; //Link the temp to first node
    printf("%d deletd", temp->data);
    front = front->link; //Link the front to the next node
    free(temp);
    return front;
}
NODE insert_rear (NODE front) {
    NODE temp, ptr;
    temp = getnode();
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (front == NULL) { //Deqeue is empty and it's the first insertion
        front = temp;
        return front;
    }
    ptr = front; //Start from the fornt
    while (ptr->link!= NULL) { //traverse to the last node
        ptr = ptr->link;
    }
    ptr->link = temp; //Add the new node at the end
    return front;
}
NODE delete_rear (NODE front) {
    NODE prev, ptr;
    if (front == NULL) {
        printf("Dequeue is empty");
        return front;
    }
    if (front->link == NULL) { //If there is only one node in the list
        free(front);
        return NULL;
    }
    ptr = front;
    while (ptr->link != NULL) { //Traverse to the last node
        prev = ptr;
        ptr = ptr->link;
    }
    printf("%d Deleted", ptr->data);
    free(ptr);
}
void display (NODE front) {
    NODE temp;
    if (front == NULL) {
        printf("Dequeue is empty");
        return;
    }
    temp = front;
    for (temp = front; temp != NULL; temp = temp->link) {
        printf("%d ", temp->data);
    }
}
```

### Explanation

- **insertFront/insertRear**: Inserts elements at front or rear. Handles wraparounds.
- **deleteFront/deleteRear**: Removes elements from front or rear.
- **display**: Shows all elements from `front` to `rear`.

---

### 3. Priority Queue

A **priority queue** assigns priorities to elements. Elements with a higher priority are dequeued first.

---

## Multiple Stacks

Imagine you have a bunch of boxes, and you want to put different things in each box. That's like having multiple stacks!

A stack is like a pile of things, where you can only add or remove things from the top. Imagine you have a stack of books. You can put a new book on top, or take the book on top off.

Now, let's say you have three different piles of things - one for your toys, one for your school supplies, and one for your clothes. That's like having three different stacks!

Here's how you can create multiple stacks in code:

```c
#define MAX_STACKS 3
int top[MAX_STACKS] = {-1, -1, -1};
char stacks[MAX_STACKS][100];

// Push an item onto a stack
void push(int stack_num, char item) {
    if (top[stack_num] >= 99) {
        printf("Stack %d is full!\n", stack_num);
        return;
    }
    stacks[stack_num][++top[stack_num]] = item;
    printf("Pushed %c onto stack %d\n", item, stack_num);
}

// Pop an item from a stack
char pop(int stack_num) {
    if (top[stack_num] == -1) {
        printf("Stack %d is empty!\n", stack_num);
        return '\0';
    }
    return stacks[stack_num][top[stack_num]--];
}
```

In this example, we have three stacks (`MAX_STACKS = 3`). Each stack has its own `top` index, which keeps track of the last item added to the stack.

The `push()` function adds an item to the top of the selected stack, and the `pop()` function removes and returns the item from the top of the selected stack.

You can use these functions to add and remove items from each of your three stacks, just like you can add and remove books from your different piles of things.

## Multiple Queues

Queues are a bit different from stacks. In a queue, you add things to the back and take them out from the front, like waiting in line at the grocery store.

Now, let's say you have three different lines - one for your friends, one for your family, and one for your teachers. That's like having three different queues!

Here's how you can create multiple queues in code:

```c
#define MAX_QUEUES 3
#define QUEUE_SIZE 10
int front[MAX_QUEUES] = {-1, -1, -1};
int rear[MAX_QUEUES] = {-1, -1, -1};
char queues[MAX_QUEUES][QUEUE_SIZE];

// Enqueue an item into a queue
void enqueue(int queue_num, char item) {
    if (rear[queue_num] == QUEUE_SIZE - 1) {
        printf("Queue %d is full!\n", queue_num);
        return;
    }
    if (front[queue_num] == -1) {
        front[queue_num] = 0;
    }
    queues[queue_num][++rear[queue_num]] = item;
    printf("Enqueued %c into queue %d\n", item, queue_num);
}

// Dequeue an item from a queue
char dequeue(int queue_num) {
    if (front[queue_num] == -1) {
        printf("Queue %d is empty!\n", queue_num);
        return '\0';
    }
    char item = queues[queue_num][front[queue_num]];
    if (front[queue_num] == rear[queue_num]) {
        front[queue_num] = -1;
        rear[queue_num] = -1;
    } else {
        front[queue_num]++;
    }
    return item;
}
```

In this example, we have three queues (`MAX_QUEUES = 3`). Each queue has its own `front` and `rear` indices, which keep track of the first and last items in the queue.

The `enqueue()` function adds an item to the back of the selected queue, and the `dequeue()` function removes and returns the item from the front of the selected queue.

We can use these functions to add and remove items from each of your three queues, just like we can wait in line and get served at each of your different lines.
