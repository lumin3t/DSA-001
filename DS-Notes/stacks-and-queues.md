# Stacks

![image](https://github.com/user-attachments/assets/18ecf6ac-5f9b-44c4-a33c-a1a4b549dc42)
Definition: Refer unit 1

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
// Peek dsiaplys stack[top]
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

---

### Applications of Stacks:

Here’s a concise explanation of the **applications of stacks** in small paragraphs with examples:

##### 1. Conversion of Arithmetic Expression

Stacks are used to convert arithmetic expressions between notations, such as **infix** (e.g., `A + B`), **prefix** (e.g., `+ A B`), and **postfix** (e.g., `A B +`). For example, the **Shunting Yard Algorithm** uses a stack to convert infix expressions to postfix notation. The stack ensures that operators are placed correctly based on precedence and associativity. This is useful in compilers and calculators.

##### 2. Evaluation of Arithmetic Expression

Stacks are used to evaluate arithmetic expressions, especially in **postfix notation**. For example, to evaluate `3 4 + 5 *`, a stack is used to store operands.
For every character of postfix expression do

1. If operand, then, PUSH the character on stack
2. If operator, then,

- opnd2 POP( )
- opnd1 POP( )
- PUSH ( eval(opnd1 operator opnd2))
  Stack top contains the evaluated value

##### 3. Recursion

Stacks are essential for implementing **recursion** in programming. When a function calls itself, its state (e.g., variables, return address) is pushed onto the **call stack**. Once the recursive call completes, the state is popped, and the program resumes execution. For example, in calculating the factorial of a number, the stack keeps track of each recursive call until the base case is reached.

##### 4. Tree Traversal (Inorder, Preorder, Postorder)

Stacks are used in **iterative tree traversals** to simulate the recursive process. For example:

- **Inorder Traversal**: Left, Root, Right (e.g., `4, 2, 5, 1, 3`).
- **Preorder Traversal**: Root, Left, Right (e.g., `1, 2, 4, 5, 3`).
- **Postorder Traversal**: Left, Right, Root (e.g., `4, 5, 2, 3, 1`).

The stack keeps track of nodes to be visited, ensuring the correct order of traversal.

##### 5. Graph Traversal (BFS, DFS)

Stacks are used in **Depth-First Search (DFS)** for graph traversal. In DFS, nodes are explored as deep as possible before backtracking. For example, starting from node `A`, the stack is used to push and pop nodes like `A → B → D → C`. In contrast, **Breadth-First Search (BFS)** uses a queue to explore nodes level by level (e.g., `A → B → C → D`).

| **Application**               | **Example**                                       |
| ----------------------------- | ------------------------------------------------- |
| Conversion of Arithmetic Exp. | Infix `A + B` → Postfix `A B +` using a stack.    |
| Evaluation of Arithmetic Exp. | Evaluate `3 4 + 5 *` using a stack.               |
| Recursion                     | Factorial calculation using the call stack.       |
| Tree Traversal                | Inorder traversal of a binary tree using a stack. |
| Graph Traversal               | DFS traversal of a graph using a stack.           |

---

### Infix to Postfix and Prefix using Stacks:

##### Infix to postfix

![Innfix to Postfix](https://github.com/user-attachments/assets/95044e86-5463-45af-aa9c-c25197a07174)
(Same for Prefix but scan reversed infix and reverse the "postfix" in the end)

#### Algorithm: Infix to Postfix

Let **X** be an arithmetic expression written in infix notation. This algorithm finds the equivalent postfix expression **Y**.

1. Push `"("` onto the **Stack**, and add `")"` to the end of **X**.
2. Scan **X** from left to right and repeat **Steps 3 to 6** for each element of **X** until the **Stack** is empty.
3. If an **operand** is encountered, add it to **Y**.
4. If a **left parenthesis** `"("` is encountered, push it onto the **Stack**.
5. If an **operator** is encountered, then:
   1. Repeatedly pop from the **Stack** and add to **Y** each operator (on the top of the **Stack**) that has the **same precedence** or **higher precedence** than the current operator.  
      (i.e., if `input operator <= stack top operator`)
   2. Add the current operator to the **Stack**.  
       (i.e., if `input operator > stack top operator`)  
      **[End of If]**
6. If a **right parenthesis** `")"` is encountered, then:
   1. Repeatedly pop from the **Stack** and add to **Y** each operator (on the top of the **Stack**) until a **left parenthesis** `"("` is encountered.
   2. Remove the **left parenthesis** from the **Stack**.  
      **[End of If]**  
      **[End of If]**
7. **END**.

#### Algorithm: Infix to Prefix

Expression = (A+B^C)\*D+E^5

1. Reverse the infix expression. 5^E+D\*)C^B+A(
2. Make Every ‘(‘ as ‘)’ and every ‘)’ as ‘(‘ 5^E+D\*(C^B+A)
3. Convert expression to postfix form. A+(B*C-(D/E-F)*G)\*H
4. Reverse the postfix Expression

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
                while (stack[top] != '(') { // pop between (...)
                    postfix[j++] = pop();
                }
                pop(); // Pop '(' from stack
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (preceed(stack[top]) >= preceed(symbol)) { //higher precendance cant tolerate lower precendence
                    postfix[j++] = pop();
                }
                push(symbol); //pop the higher one then push
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

---

### Evaluation Algorithm

1. Add ) to postfix expression.
2. Read postfix expression Left to Right until ) encountered
3. If operand is encountered, push it onto Stack [End If]
4. If operator is encountered, Pop two elements
   - A -> Top element
   - B-> Next to Top element
   - Evaluate B operator A push B operator A onto Stack
5. Set result = pop
6. END

---

### Recursion

Recursion in C is a programming technique where a function calls itself to solve a problem by breaking it down into smaller subproblems. It typically involves a base case to stop the recursion and a recursive case that defines how the function calls itself.

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

# Queues

![image](https://github.com/user-attachments/assets/0f7b682f-bc00-4a4a-8e05-e61cc9362f36)
FIFO (First in First out)

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
            //yuh
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

### Types of queues

1. Normal queue
2. Circular queue
3. Double ended queue
4. Priority queue

---

### Circular Queue

In a **circular queue**, the last position connects back to the first, forming a circle. This structure avoids the need to shift elements and uses the space more efficiently. It works on FIFO principle and forms what's called as a "Ring buffer"
![Circular queue img](https://github.com/user-attachments/assets/0a3c13f3-7155-4eb2-8769-b54f068687de)

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

(Yuh so basically it's the same as normal array queue but with quirky (x+1)%SIZE stuff instead of simple x++)

---

### Deque (Double-Ended Queue)

A **deque** allows insertion and deletion from both ends. It can be **implemented with a singly linked list** (ez lab program)

#### Dequeue with SLL (Fill in the gaps)

```c
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
} node;
typedef struct node *NODE;
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
int main () {
	 NODE front = NULL;
	//menu
}
```

---

### Priority Queue

A **priority queue** assigns priorities to elements. Elements with a higher priority are dequeued first.
It’s a special type of queue where Insertion happens from rear end but deletion is based on priority (There are Ascending and Descending Priority Queues)

```c++
#include <bits/stdc++.h>
using namespace std;
// Structure for the elements in the priority queue
struct item {
    int value;
    int priority;
};
// Store the elements of the priority queue
item pr[10000];
// Pointer to the last index
int size = -1;
// Function to insert a new element into the priority queue
void enqueue(int value, int priority) {
    // Increase the size
    size++;
    // Insert the element
    pr[size].value = value;
    pr[size].priority = priority;
}

// Function to find the position of the element with the highest priority
int peek() {
    int highestPriority = INT_MIN;
    int ind = -1;

    // Check for the element with the highest priority
    for (int i = 0; i <= size; i++) {
        // If priority is the same, choose the element with the highest value
        if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value) {
            highestPriority = pr[i].priority;
            ind = i;
        } else if (highestPriority < pr[i].priority) {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    // Return the position of the element
    return ind;
}

// Function to remove the element with the highest priority
void dequeue() {
    // Find the position of the element with the highest priority
    int ind = peek();
    // Shift the elements one index back from the position of the element
    // with the highest priority
    for (int i = ind; i < size; i++) {
        pr[i] = pr[i + 1];
    }
    // Decrease the size of the priority queue by one
    size--;
}
int main() {
    // Function calls to insert elements as per their priority
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);
    // Stores the top element at the moment
    int ind = peek();
    cout << pr[ind].value << endl;
    // Dequeue the top element
    dequeue();
    // Check the top element
    ind = peek();
    cout << pr[ind].value << endl;
    // Dequeue the top element
    dequeue();
    // Check the top element
    ind = peek();
    cout << pr[ind].value << endl;
    return 0;
}
```

---

### Multiple stacks and queues in real-life applications

Multiple stacks and queues are used in various real-life applications to efficiently manage multiple data streams, independent workflows, and parallel processes. Here are some common scenarios where they come in handy:

##### 1. Memory management in operating systems

- **Multiple stacks**: Each process or thread has its own stack to manage function calls, local variables, and return addresses. This ensures that data from one process doesn’t interfere with another.
- **Multiple queues**: Operating systems use queues to manage tasks like high-priority vs. low-priority tasks in scheduling, I/O operations, and load balancing. For example, real-time tasks may be managed in one queue while background tasks are in another.

##### 2. Web servers and load balancing

- **Multiple queues**: Web servers handle multiple client requests simultaneously. Separate queues for different types of requests (e.g., read vs. write operations) help prioritize resources.
- **Multiple stacks**: Each connection might have its own stack to track the state of its request and response lifecycle, including nested functions or operations.

##### 3. Multi-user games

- **Multiple queues**: Multiplayer games manage simultaneous actions from various players. Actions for each player can be stored in a separate queue and processed in order of arrival.
- **Multiple stacks**: Each player’s character may have a separate stack for managing actions, especially when moves or spells involve nested sequences.

##### 4. Customer support systems

- **Multiple queues**: Customer support systems use queues to organize and prioritize requests based on urgency, type of issue, or customer tier. For example, VIP customers may have a dedicated queue with higher priority.

##### 5. Undo and redo mechanisms in applications

- **Multiple stacks**: Applications like text editors or graphic software allow users to undo or redo actions. Each document or project can have its own undo and redo stacks, enabling independent management of history for multiple files.

##### 6. Robotics and embedded systems

- **Multiple queues**: In robotics, each sensor or component might produce data at different rates. Multiple queues allow efficient data handling by separating and prioritizing inputs from sensors, motors, cameras, etc.
- **Multiple stacks**: Each robot task (e.g., navigation, object detection) might have its own stack to handle specific routines and manage function calls independently.

##### 7. Real-time data processing (e.g., IoT or finance)

- **Multiple queues**: Systems handle data from various sensors or data feeds. For example, a stock trading system might have separate queues for real-time data, historical data, and trade requests, ensuring timely processing.

##### 8. Printing systems

- **Multiple queues**: Printers in large organizations manage print jobs from multiple users or departments. Separate queues for high-priority jobs, color prints, and large documents ensure efficient and organized printing.
