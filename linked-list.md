Arrays require **contiguous memory**, which can be challenging to allocate, especially for large arrays. Their size is **fixed** during declaration, limiting flexibility in dynamic scenarios. (STATIC)
**Stack**:  
Stores **automatic** (local) and **static** variables. Limited size, faster access. Managed automatically.
**Heap**:  
Stores dynamically allocated memory (`malloc`). Large, flexible, but slower access. Requires manual management
![Stack and heap](https://github.com/user-attachments/assets/47fad86e-70bb-4778-bd58-e445b64e3286)

### Linked Lists

- Linked Lists are a data structure that store data in the form of a chain. The structure of a linked list is such that each piece of data has a connection to the next one (and sometimes the previous data as well). Each element in a linked list is called a node.

![Linked list](https://github.com/user-attachments/assets/bea9eaeb-b8b0-4163-af5c-e176bb52e16b)

- It's implemented using **self-referential structures**, where a structure contains a pointer to another structure of the same type:
  ```c
  struct Node {
      int data;
      struct Node* next;
  };
  ```
- This allows **dynamic memory allocation** and flexible resizing compared to arrays.
- **`malloc`** dynamically allocates memory from the heap:
  ```c
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  ```
- **`sizeof()`** determines the size of a data type or structure at compile-time, making `malloc` portable across platforms.

#### Advantages:

1. Because of the chain-like system of linked lists, you can add and remove elements quickly. This also doesn't require reorganizing the data structure unlike arrays or lists. Linear data structures are often easier to implement using linked lists.
2. Linked lists also don't require a fixed size or initial size due to their chainlike structure.

### Linked list in memory

(One of 3 examples)

![img2](https://github.com/user-attachments/assets/2ec4e503-2a06-4e8d-9095-30ff82ca8cf9)

```c
//DMA in heap
typedef struct list {
	int info;
	struct list *link;
} node;
typedef struct list * NODE;
NODE start = NULL;
```

### Linked list operations

#### Insert front

![insert front](https://github.com/user-attachments/assets/33b65ac4-a7f8-4d82-8ea6-95d223ce8eed)

```c
NODE insert_front (NODE front) {
    NODE temp;
    temp = getnode(); //Allocate memory for new node
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = front; //New node links to current first node
    front = temp; //First node is now temp
    return front;
}
```

#### Insert rear

![insert rear](https://github.com/user-attachments/assets/34f4c23a-5e67-4a45-a5b4-c0abbccc7ff0)

```c
NODE insert_rear (NODE front) {
    NODE temp, ptr;
    temp = getnode();
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (front == NULL) { //List is empty and it's the first insertion
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
```

#### Insert at selected location

![image](https://github.com/user-attachments/assets/1078fbc9-9bdc-4350-aec7-371af8ecce63)

#### Delete front

![image](https://github.com/user-attachments/assets/2b5b0251-93af-4948-b68d-8fb66bed63cb)

```c
NODE delete_front (NODE front) {
    NODE temp;
    if (front == NULL) {
        printf("List is empty");
        return front;
    }
    temp = front; //Link the temp to first node
    printf("%d deletd", temp->data);
    front = front->link; //Link the front to the next node
    free(temp);
    return front;
}
```

#### Delete rear

![image](https://github.com/user-attachments/assets/d6ba3909-9bac-47ec-b763-3b2b19d56292)

```c
NODE delete_rear (NODE front) {
    NODE prev, ptr;
    if (front == NULL) {
        printf("List is empty");
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
```

#### Traversal

```c
void display (NODE front) {
    NODE temp;
    if (front == NULL) {
        printf("List is empty");
        return;
    }
    temp = front;
    for (temp = front; temp != NULL; temp = temp->link) {
        printf("%d ", temp->data);
    }
}
```

#### Search and Update

```c
void search_and_update(NODE head) {
    int searchValue, updateValue;
    printf("Enter value to search: ");
    scanf("%d", &searchValue);

    NODE temp = head;
    while (temp != NULL) {
        if (temp->data == searchValue) {
            printf("Value %d found.\n", searchValue);
            printf("Enter new value to update: ");
            scanf("%d", &updateValue);
            temp->data = updateValue;
            printf("Value updated to %d.\n", updateValue);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", searchValue);
}
```

### Other operations:

Insert

- to left of Given node value
- to the right of given node value
- into ordered list
- based on the position specified
  Delete
- the node with the node value specified
- the node to the left of node value
- the node to the right of node value
- the node based on position
  Search based on node value and update

### Implementation:

**Stack using Linked List**

- PUSH – Insert at front
- POP - Delete at front
  **Queue using Linked List**
- Insert – Insert at rear
- Delete – Delete from front

### Doubly linked list

SLLs allow traversal in only one direction, making reverse traversal or operations inefficient and increasing overall complexity.
DLL allows for traversal in both directions

#### Memory representation

![image](https://github.com/user-attachments/assets/b044138b-07e7-4624-8781-3deed257dafe)

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node* NODE;

NODE getnode() { // Function to create a new node
    NODE temp;
    temp = (NODE)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    return temp;
}

NODE insert_front(NODE first) {
    NODE temp = getnode();
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = first;
    temp->prev = NULL;
    if (first != NULL) { //First exists
        first->prev = temp;
    } //.If not the inserted node is the first
    return temp;
}

NODE insert_rear(NODE first) {
    NODE temp = getnode(), ptr;
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL; //Cuz last node
    if (first == NULL) { // First node insertion
        temp->prev = NULL;
        return temp;
    }
    ptr = first;
    while (ptr->next != NULL) { // Traverse to the last node
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return first;
}

NODE insert_at_position(NODE first, int pos) {
    NODE temp, ptr;
    int i;
    if (pos == 1) {
        return insert_front(first); // Directly call insert_front for the first position
    }
    temp = getnode(); // Create new node
    printf("Enter data: ");
    scanf("%d", &temp->data);
    ptr = first;
    for (i = 1; i < pos - 1 && ptr != NULL; i++) { // Traverse to the (pos-1)th node or stop if the list ends
        ptr = ptr->next;
    }
    // If ptr is NULL, it means pos is invalid
    if (ptr == NULL) {
        printf("Invalid position\n");
        free(temp); // Free the unused node
        return first;
    }
    // Insert the new node after ptr
    temp->next = ptr->next;
    temp->prev = ptr;
    // Adjust the next node's previous pointer if it exists
    if (ptr->next != NULL) {
        ptr->next->prev = temp;
    }
    ptr->next = temp; // Update ptr's next pointer
    return first;
}

NODE delete_front(NODE irst) {
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    NODE temp = first;
    first = first->next;
    //if (first != NULL) {//There exists a first node
        first->prev = NULL;
    //}
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return first;
}

NODE delete_rear(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    if (first->next == NULL) { // Theres only one node
        printf("Deleted: %d\n", first->data);
        free(first);
        return NULL;
    }
    NODE ptr = first;
    while (ptr->next != NULL) { // Traverse to the last node
        ptr = ptr->next;
    }
    printf("Deleted: %d\n", ptr->data);
    ptr->prev->next = NULL;
    free(ptr);
    return first;
}

NODE delete_at_position(NODE first, int pos) {
    NODE ptr = first;
    int i;
    if (pos == 1) {
        return delete_front(first);
    }
    for (i = 1; i < pos && ptr != NULL; i++) { //Traverse to (pos-1)th node
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Invalid position\n");
        return first;
    }
    ptr->prev->next = ptr->next; //basically youre deleting ptr like -> issoke if null
    if (ptr->next != NULL) {  //delete agin but dont work if it null so ye
        ptr->next->prev = ptr->prev; //now delete like this <-
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("No nodes\n");
        return;
    }
    NODE temp = first;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL) { //Looks cool but not really needed
            printf(" <=> ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int main () {
	 NODE first = NULL;
	//choice menu
}
```

### Singly Circular linked lists

#### Memory representation

![image](https://github.com/user-attachments/assets/1ad8149f-d562-4c7f-8e36-986ed54b467e)

![image](https://github.com/user-attachments/assets/cb4b5e9a-c49c-46c2-81e4-b16961469062)

```c
//Singly circular linked list with header node
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} node;
typedef struct node *NODE;

NODE getnode()  {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

NODE insert_front(NODE head) {
    NODE temp;
    temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = head->next;
    head->next = temp;
    return head;
}
NODE delete_front (NODE head) {
    NODE temp;
    if (head->next == head) {
        printf("Empty list");
        return head;
    }
    temp = head->next;
    printf("Deleted %d", temp->data);
    head->next = temp->next;
    free(temp);
    return head;
}
NODE insert_rear (NODE head) {
    NODE temp, ptr;
    temp = getnode();
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    ptr = head;

    while (ptr->next != head { //Traverse to the last node
        ptr=ptr->next;
    }
    ptr->next = temp;
    temp->next = head;
    return head;
}

NODE delete_rear (NODE head) {
    NODE ptr, prev;
    if (head->next == head) {
        printf("Empty list");
        return head;
    }
    while(ptr->next != head) { //traverse to last node
        prev = ptr;
        ptr = ptr->next;
    }
    printf("Deleted");
    prev->next = ptr->next;
    free(ptr);
    return head;
}
void display (NODE head) {
    NODE temp;
    if (head->next == head) {
        printf("Empty list");
        return;
    }
    temp = head->next;
    for(temp=head->next; temp != head; temp = temp->next) {
        printf("%d ", temp->data);
    }
}
int main () {
	 NODE head;
	 head->next = head;
	 //Choices menu
}
```

### Applications of Linked lists

#### Polynomial representation

![image](https://github.com/user-attachments/assets/bdb3b9d1-0b0e-4875-81df-5e27536b3cd2)

1. **Define Node Structure**:
   - Each node contains `coefficient`, `power`, and a pointer to the `next` node.
2. **Input Polynomials**:
   - Create two linked lists to represent the two polynomials.
3. **Add Polynomials**:
   - Traverse both lists simultaneously.
   - If the powers match, add the coefficients and create a new node for the resultant list.
   - If the powers don’t match, insert the node with the higher power into the resultant list.
4. **Display Result**:
   - Traverse the resultant list and print the polynomial.

![image](https://github.com/user-attachments/assets/27c467e8-48de-48fd-bfc1-33d68dacf4e6)

```
POLYNOMIAL ADDITION ALGORITHM
----------------------------
Data Structure: Linked List(coef, exp, next)
Input: Two polynomials P1, P2 in decreasing order of exponents

Algorithm:
1. While P1 and P2 are not empty:
   - Compare exponents
   - If equal: Add coefficients, append to result
   - If P1.exp > P2.exp: Append P1 term to result
   - If P2.exp > P1.exp: Append P2 term to result
   - Move to next term of used polynomial
2. Append remaining terms from non-empty polynomial

Example:
P1: 3x^2 + 2x^1
P2: 4x^2 + 1x^0
Result: 7x^2 + 2x^1 + 1x^0
```

**Points to keep in Mind while working with Polynomials**:

- The sign of each coefficient and exponent is stored within the coefficient and the exponent itself
- Additional terms having equal exponent is possible one
- The storage allocation for each term in the polynomial must be done in ascending and descending order of their exponent

#### Sparse Matrix representation

Cuz normal way is a waste of memory
![image](https://github.com/user-attachments/assets/bd975ec3-3182-487f-997f-7a0e31f94b63)

- A sparse matrix is a matrix where a large proportion of the elements have a value of zero.
- In a linked list representation of such a matrix, zero value elements are not represented, saving space.

BUT for some reason in the assignment it says using ARRAYS and we had the same for internals too so

#### Sparse Matrix using arrays

```c
#include <stdio.h>

// Structure to represent a non-zero element in the sparse matrix
struct Element {
    int row, col, value;
};

int main() {
    int rows, cols, numNonZero;

    // Input the dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input the number of non-zero elements
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numNonZero);

    // Create an array to store non-zero elements
    struct Element sparseMatrix[numNonZero];

    // Input non-zero elements
    printf("Enter non-zero elements (row, column, value):\n");
    for (int i = 0; i < numNonZero; i++) {
        scanf("%d %d %d", &sparseMatrix[i].row, &sparseMatrix[i].col, &sparseMatrix[i].value);
    }

    // Display the sparse matrix
    printf("\nSparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numNonZero; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }

    return 0;
}
```

###### Output:

```bash
Enter the number of rows and columns: 4 4
Enter the number of non-zero elements: 4
Enter non-zero elements (row, column, value):
0 1 5
1 2 8
2 0 3
3 3 7
Sparse Matrix Representation:
Row     Column  Value
0       1       5
1       2       8
2       0       3
3       3       7
```

(Write actual matrix representation after this)
