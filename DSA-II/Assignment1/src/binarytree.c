#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int val;
  struct node* left;
  struct node* right;
}tnode;

// Inorder traversal
void inorderTraversal(tnode* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ", root->val);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(tnode* root) {
  if (root == NULL) return;
  printf("%d ", root->val);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(tnode* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->val);
}

// Create a new Node
tnode* createNode(int value) {
  tnode* newNode = malloc(sizeof(tnode));
  if(!newNode)
	  return newNode;
  newNode->val = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
tnode* insertLeft(tnode* root, int value) {
  root->left = createNode(value);
  if(!root->left)
	  return root;
  return root->left;
}

// Insert on the right of the node
tnode* insertRight(tnode* root, int value) {
  root->right = createNode(value);
  if(!root->right)
	  return root;
  return root->right;
}

//Height of the binary tree
int Height(tnode* bt){
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

// Nodes at the ith Level
void print_levelnodes(tnode* bt, int level){
        if(bt == NULL){
                return;
        }if(level == 1){
                printf("%d ",bt->val);
        }else if(level>1){
                print_levelnodes(bt->left,level-1);
                print_levelnodes(bt->right,level-1);
        }
}

// Level Order Traversal
void  levelorder(tnode* bt){
        int h = Height(bt);
        int i ;
        for(i = 0; i< h; i++){
                print_levelnodes(bt,i);
        }

}

// Searching the element
// return the comparison made to serach the element 
int  search_bt(tnode* bt, int target, int *count){
	if(bt == NULL) return 0;
	
	if(bt->val == target ){
		return 1;
	}
	(*count)++;
	
	if(search_bt(bt->left,target,count)) return 1;
	
	if(search_bt(bt->right,target,count)) return 1;
	
	return 0;

}








