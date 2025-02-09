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


NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    NODE temp = first;
    first = first->next;
    //if (first != NULL) { //There exists a first node already
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
    if (ptr->next != NULL) {  //delete agin but dont work if it null so ye
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
        printf("%d", temp->data);
        if (temp->next != NULL) { //Looks cool but not really needed
            printf(" <=> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE first = NULL;
    int choice, pos;
    while (1) { // Write delete and insert ops separately to reduce lines
        printf("\nMenu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Front\n");
        printf("5. Delete Rear\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                first = insert_front(first);
                break;
            case 2:
                first = insert_rear(first);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                first = insert_at_position(first, pos);
                break;
            case 4:
                first = delete_front(first);
                break;
            case 5:
                first = delete_rear(first);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                first = delete_at_position(first, pos);
                break;
            case 7:
                display(first); 
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
