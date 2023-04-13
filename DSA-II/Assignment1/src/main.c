#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../include/binarytree.h"
#include"../include/bst.h"

int toss(){
        return rand()  % 2;
}

tnode* insertNode(tnode* root, int data) {
   if (root == NULL) {
	   return createNode(data);
   }if (toss() == 1) {
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

int bt_comparison(FILE* ptrfile, FILE* ptr_samp, int num_lines){
	int i , count, target, avg_sum;
	target = 0;
	tnode* bt = bt_file(ptrfile,num_lines);
	rewind(ptr_samp);
	avg_sum  = 0;
	for(i = 0 ; i < 155 ; i++){
		count  = 0;
		fscanf(ptrfile,"%d",&target);
		search_bt(bt,target,&count);
		avg_sum += count;
	}
	avg_sum  = avg_sum / (155);
	return avg_sum;
}

int bst_comparison(FILE* ptrfile, FILE* ptr_samp, int num_lines){
	int i , count, target, avg_sum;
	target = 0;
	tnode* bst = bst_file(ptrfile,num_lines);
	rewind(ptr_samp);
	avg_sum  = 0;
	for(i = 0 ; i<155; i++){
		count  = 0;
		fscanf(ptrfile,"%d",&target);
		search_ele(bst,target,&count);
		avg_sum += count;
	}
	avg_sum  = avg_sum / (155);
	return avg_sum;
}

void print_data(FILE* pfile, FILE* psamp, int num_lines){
	int a = bt_comparison(pfile,psamp,num_lines);
	rewind(pfile);
	rewind(psamp);
	int b = bst_comparison(pfile,psamp,num_lines);		
	printf("%d\t%d\n",a,b);

}
int main(int argc, char const *argv[]){
	//Creating the file pointers 
        FILE * pfile1 = fopen(argv[1],"r");
 
        FILE * pfile2 = fopen(argv[2],"r");
 
        FILE * pfile3 = fopen(argv[3],"r");

        FILE * pfile4 = fopen(argv[4],"r");

        FILE * pfile5 = fopen(argv[5],"r");

	FILE * comp_sample = fopen(argv[2],"r");
	
	print_data(pfile1,comp_sample,5000);
	fclose(pfile1);
	
	print_data(pfile2,comp_sample,10000);
	fclose(pfile2);

	print_data(pfile3,comp_sample,100000);
	fclose(pfile3);

	print_data(pfile4,comp_sample,100000);
	fclose(pfile4);

	print_data(pfile5,comp_sample,1000000);
	fclose(pfile5);
	fclose(comp_sample);


	return 0;
}

