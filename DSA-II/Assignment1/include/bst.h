#ifndef TNODE

typedef struct node {
  int val;
  struct node* left;
  struct node* right;
}tnode;


void inorderTraversal(tnode* root);

void preorderTraversal(tnode* root);

void postorderTraversal(tnode* root);

#endif

tnode* new_tnode(int val);

tnode* insert_bst(tnode* bst, int val);

int search_ele(tnode* bst, int target , int* count );

