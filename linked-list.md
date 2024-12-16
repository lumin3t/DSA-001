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
```

#### Insert at selected location

![image](https://github.com/user-attachments/assets/1078fbc9-9bdc-4350-aec7-371af8ecce63)

#### Delete front

![image](https://github.com/user-attachments/assets/2b5b0251-93af-4948-b68d-8fb66bed63cb)

```c
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
```

#### Delete rear

![image](https://github.com/user-attachments/assets/d6ba3909-9bac-47ec-b763-3b2b19d56292)

```c
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
```

#### Traversal

```c
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
• to left of Given node value
• to the right of given node vale
• into ordered list
• based on the position specified
Delete
• the node with the node value specified
• the node to the left of node value
• the node to the right of node value
• the node based on position
Search based on node value and update

### Implementation:

**Stack using Linked List**
• PUSH – Insert at front
• POP - Delete at front
**Queue using Linked List**
• Insert – Insert at rear
• Delete – Delete from front
