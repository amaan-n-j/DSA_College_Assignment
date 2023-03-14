// A simple C program for
// traversal of a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

// This function prints contents of linked list starting
// from the given node
void printList(struct Node* n)
{
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
	printf("\n");
}

void insert_start(struct Node** head_ref, int new_data){
	struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void insert_end(struct Node** head_ref , int new_data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* I_node  = *head_ref;
	while(I_node->next != NULL){
		I_node = I_node->next;
	}
	new_node->data = new_data;
	new_node->next = NULL;
	I_node->next = new_node;
}

void insert_after(struct Node** head_ref , int new_data, int index){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* I_node  = *head_ref;
	int i =0;
	while(i < index){
		I_node = I_node->next;
		i++;
	}
	struct Node* temp = I_node->next;
	I_node->next = new_node;
	new_node->data = new_data;
	new_node->next = temp;
}



int main()
{
	// allocate 3 nodes in the heap
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	struct Node* second = (struct Node*)malloc(sizeof(struct Node));
	struct Node* third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = NULL;

	// Function call
	printList(head);

	// Inserting element at the start 
	insert_start(&head, 0);
	printList(head);
	insert_end(&head, 5);
	printList(head);

	// Inserting element in between 
	insert_after(&head, 4, 3);
	printList(head);


	return 0;
}
