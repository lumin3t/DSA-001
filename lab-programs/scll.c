//Singly circular linked list with header node 
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} node;
typedef struct node *NODE;

NODE getnode()  {
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
    while (ptr->next != head) { //Traverse to the last node
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
    while(ptr->next != head) {
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
    NODE head = getnode();
    head->next = head;
    int choice;
    while (1) {
        printf("\nEnter choice: (1): Insrt front (2): Insert rear (3): Delete front (4): Delete rear (5): Display (6): Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: head = insert_front(head); break;
            case 2: head = insert_rear(head); break;
            case 3: head = delete_front(head); break;
            case 4: head = delete_rear(head); break;
            case 5: display(head); break;
            case 6: exit(0);
            default: printf("Invalid choice"); break;
        }
    }
    return 0;
}