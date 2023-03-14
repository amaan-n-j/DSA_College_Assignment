#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}Node;

int stack_arr[100] , top;
int top = -1;

void arr_Push(int stack[] , int data){
	if(top == 100){
	       printf("Stack is full");
	}
	else{
		top++;
		stack[top] = data;
	}
}

void arr_pop(int stack[] ,int top_ref){
	if(top_ref == -1){
	       printf("Stack is empty!!");
	}
	else{
		top--;
	}
}

int main(){
	arr_Push(stack_arr, 10);
	arr_Push(stack_arr, 20);
	arr_Push(stack_arr, 30);
	arr_Push(stack_arr, 40);

	for(int i =0; i<top; i++){
		printf("Position:%d Value:%d \n",i, stack_arr[i]);
	}
	
	arr_pop(stack_arr, top );

	printf("Stack after removing one element\n");

	
	for(int i =0; i<top; i++){
		printf("Position:%d Value:%d \n",i, stack_arr[i]);
	}

}

