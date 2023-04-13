#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../include/binarytree.h"
#include"../include/bst.h"
int toss(){
	return rand()% 2;
}

tnode* insertNode(tnode* root, int data) {
    srand(time(0));	
    if (root == NULL) {
        return createNode(data);
    } else if (toss() == 1) {
        root->right = insertNode(root->right, data);
    } else {
        root->left = insertNode(root->left, data);
    }
    return root;
}

tnode*  bt_file(FILE *ptrfile, int count){
	int a , i;
	tnode* root;
	fscanf(ptrfile,"%d",&a);
	root = createNode(a);
	for(i = 0 ; i < count ; i++ ){
		fscanf(ptrfile,"%d",&a);
		printf("%d\t%d\n",i,a);
	        insertNode(root,a);
	}
	return root;
}

tnode* bst_file(FILE *ptrfile, int count){

	int a, i ;
        a = 0;
        fscanf(ptrfile,"%d",&a);
        tnode* bst = new_tnode(a);
        tnode* bst_ref = bst;
        for(i = 0; i< count ; i++ ){
                fscanf(ptrfile,"%d",&a);
                bst_ref = insert_bst(bst_ref,a);
        }
	return bst;
}

int main(int argc, char const *argv[]){
	//Creating the file pointers 
	FILE * pfile1 = fopen(argv[1],"r");
	
	/*FILE * pfile2 = fopen(argv[2],"r");
	
	FILE * pfile3 = fopen(argv[3],"r");

	FILE * pfile4 = fopen(argv[4],"r");

	FILE * pfile5 = fopen(argv[5],"r");

	tnode* bt1 = bt_file(pfile1,2000);
	tnode* bt2 = bt_file(pfile2,20000);
	tnode* bt3 = bt_file(pfile3,200000);
	tnode* bt4 = bt_file(pfile4,2000000);
	tnode* bt5 = bt_file(pfile5,20000000);

	printf("Printing --------------------------------------\n");
	inorderTraversal(bt1);
	*/
	
	// Creating bst 
	
	//tnode* bst1 = bst_file(pfile1,2000);
	int count = 0 ;
	
	tnode* bst1 = bt_file(pfile1,50000);
	
	printf("\n");
	inorderTraversal(bst1);
	printf("\n");
	search_bt(bst1,5757 ,&count);
	printf("The Number of comparision made: %d",count);
	return 0;	
}

