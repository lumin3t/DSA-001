#include<stdio.h>
#include<stdlib.h>
//Dequeue with Singly linked list
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
        exit(1);  // Exit if memory allocation fails
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
	int option, choice;
	NODE front = NULL;
	while (1) {
		printf("\nEnter option (1): Entry restricted (2): Exit restricted (3): Display (4): Exit :");
		scanf("%d", &option);
		switch (option) {
			case 1: printf("Enter choice (1): Insert (2): Delete front (3): Delete rear");
					scanf("%d", &choice);
					switch (choice) {
						case 1: front = insert_rear(front); break;
						case 2: front = delete_front(front); break;
						case 3: front = delete_rear(front); break;
						default: printf("Invalid choice"); break;
					} break;
			case 2: printf("Enter choice (1): Insert front (2): Insert rear (3): Delete");
		    		scanf("%d", &choice);
					switch (choice) {
						case 1: front = insert_front(front); break;
                    	case 2: front = insert_rear(front); break;
                    	case 3: front = delete_front(front); break;
                    	default: printf("Invalid choice"); break;
					} break;
			case 3: display(front); break;
			case 4: exit(0);
			default: printf("Invalid option"); break;
		}
	}
	return 0;
}