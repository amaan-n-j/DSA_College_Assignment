#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next ;
}Node;

void add(Node ** head , int new_data){
	Node * new_node  = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}

void print_LL(Node* head){
	Node * new = head;
	while(new != NULL){
		printf("%d ", new->data);
		new = new->next;
	}
}

void reverse_LL(Node** head){
	Node* prev = NULL;
	Node* next = NULL;
	Node* current = *head;
	while(current !=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}


int main(){
	Node * head  = NULL;
	add(&head , 50);
	add(&head , 40);
	add(&head , 30);
	add(&head , 20);
	add(&head , 10);
	print_LL(head);
	// reverisng the linked list
	reverse_LL(&head);
	// printing after reversing the list
	printf("\n");
	print_LL(head);
	return 0;

}
