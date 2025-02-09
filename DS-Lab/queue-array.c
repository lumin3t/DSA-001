#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int front = -1, rear = -1;
int queue[MAX];
void enqueue () {
    if(rear == MAX-1) {
        printf("Full.");
        return;
    }
    int item;
    printf("Emter element: ");
    scanf("%d", &item);
    if (front == -1) { //First insertion
        front = 0; //Cuz you are inserting from rear but if a queue has eleemnts front shouldnt be 0
    }
    queue[++rear] = item;
    return;
}
void dequeue() {
    if(front == -1) {
        printf("Empty.");
        return;
    }
    printf("Removed");
    if (front == rear) { //First deletion
        front = rear = -1;
        printf("Removed.");
        return;
    }
    front++; //Increment first so it points to the next
    return;
}
void display() {
   if(front== -1) {
        printf("Empty.");
        return;
    }
    for (int i =front; i<=rear; i++) {
        printf("%d ", queue[i]);
    }
    return;
}
int main() {
    // Write C code here
    int option;
    while (1) {
        printf("\nEnter option? 1:enqueue 2:dequeue 3:display 4:exit ? ");
        scanf("%d", &option);
        switch (option) {
            case 1: enqueue(); 
                    break;
            case 2: dequeue(); 
                    break;
            case 3: display(); 
                    break;
            case 4: exit(0); 
        }
    }
    return 0;
}