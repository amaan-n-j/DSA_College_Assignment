#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
}Node;

Node* createBT(){
	int ch2;
	Node* temp  =(Node*)malloc(sizeof(Node));

	printf("Enter data / '-1' to quit:");
	scanf("%d", &ch2);

	if(ch2 != -1){
		
		temp->data = ch2;

		printf("\n Entering the Left Node");

		Node* left_node = createBT();

		temp->left = left_node;

		printf("\n Entering the Right Node");

		Node* right_node = createBT();

		temp->right = right_node;

		return temp;
	}
	return NULL;
	
}

int isBTEmpty(Node* bt){
	if(bt == NULL){
		return 1;
	}
	return 0;
}

Node* leftChild(Node* bt){
	if(isBTEmpty(bt->left)){
		printf("Error: Binary Tree is empty");
		return bt;
	}else{
		return bt->left;
	}
}

Node* rightChild(Node* bt){
	if(isBTEmpty(bt->right)){
		printf("Error: Binary Tree is empty");
		return bt;
	}else{
		return bt->right;
	}
}

void inorder(Node* bt){
	if(bt){
		inorder(bt->left);
		printf("%d  ", bt->data);
		inorder(bt->right);
	}
}

void preorder(Node* bt){
	if(bt){
		printf("%d  ",bt->data);
		preorder(bt->left);
		preorder(bt->right);
	}
}

void postorder(Node* bt){
	if(bt){
		preorder(bt->left);
		preorder(bt->right);
		printf("%d  ",bt->data);
	}
} 

int Height(Node* bt){
	if(bt == NULL){
		return 0;
	}
	else{
		int Left_height = Height(bt->left);
		int Right_height = Height(bt->right);

		if(Left_height > Right_height){
			return (Left_height + 1);
		}else{
			return (Right_height + 1);
		}

	}

}

void print_levelnodes(Node* bt, int level){
	if(bt == NULL){
		return;
	}if(level == 1){
		printf("%d ",bt->data);
	}else if(level>1){
		print_levelnodes(bt->left,level-1);
		print_levelnodes(bt->right,level-1);
	}
}

void  levelorder(Node* bt){
	int h = Height(bt);
	int i ;
	for(i = 0; i< h; i++){
		print_levelnodes(bt,i);
	}	

}

int main(){
	Node* bt = createBT();

	//Indorder
	printf("Printing the inorder traversal");
	inorder(bt);
	printf("\n");

	//Preorder
	printf("Printing the Preorder traversal");
	preorder(bt);
	printf("\n");

	//Postorder traversal
	printf("Printing the Post traversal");
	postorder(bt);
	printf("\n");
	
	//Level Order
	printf("Printing the level traversal");
	levelorder(bt);
	printf("\n");

	//Height of the bt
	printf("The height of the binary tree is %d",Height(bt));
	
	//Total Nodes in the tree
	printf("The total number of nodes %d",CountNodes(bt));
	return 0;
}
