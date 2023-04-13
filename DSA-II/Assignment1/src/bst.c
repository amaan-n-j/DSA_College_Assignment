#include<stdio.h>
#include<stdlib.h>

typedef struct node {
   int val;
   struct node* left;
   struct node* right;
}tnode;


tnode* new_tnode(int val){
	tnode* temp = (tnode*)malloc(sizeof(tnode));
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

tnode* insert_bst(tnode* bst, int val){
	if( bst == NULL){
		return new_tnode(val);
	}
	if( val < bst->val){
		bst->left = insert_bst(bst->left,val);
	}
	else if(val > bst->val){
		bst->right = insert_bst(bst->right,val); 
	}
	return bst;
}

// Search a bst
//return a number of comparison taken to find the element
int search_ele(tnode* bst, int target , int* count ){
	if(bst == NULL){
		(*count)++;
		return 0;
	}
	if(bst->val == target) {
		(*count)++;
		return 1;
	}
	if(bst->val > target){
		(*count)++;
		return search_ele(bst->left,target,count);
	}
	else{	
		(*count)++;
		return search_ele(bst->right,target,count);
	}
	return 0;
}








