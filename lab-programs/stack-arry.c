#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int top = -1;
int stack[MAX];
int push (int top) {
    if(top == MAX-1) { //MAX-1
        printf("Full.");
        return top;
    }
    int item;
    printf("Emter element: ");
    scanf("%d", &item);
    stack[++top] = item;
    return top;
}
int pop(int top) {
    if(top== -1) {
        printf("Empty.");
        return top;
    }
    printf("Removed");
    top--;
    return top;
}
void display(int top) {
   if(top== -1) {
        printf("Empty.");
        return;
    }
    for (int i =0; i<=top; i++) {
        printf("%d ", stack[i]);
    }
}
int main() {
    // Write C code here
    int option;
    while (1) {
        printf("\nEnter option? 1:push 2:pop 3:display 4:exit ? ");
        scanf("%d", &option);
        switch (option) {
            case 1: top=push(top); 
                    break;
            case 2: top=pop(top); 
                    break;
            case 3: display(top); 
                    break;
            case 4: exit(0); 
        }
    }
    return 0;
}