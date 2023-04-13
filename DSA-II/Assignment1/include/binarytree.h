
#define TNODE

typedef struct node {
  int val;
  struct node* left;
  struct node* right;
}tnode;


void inorderTraversal(tnode* root);

void preorderTraversal(tnode* root);

void postorderTraversal(tnode* root);

tnode* createNode(int value);

tnode* insertLeft(tnode* root, int value);

tnode* insertRight(tnode* root, int value);

int Height(tnode* bt);

void print_levelnodes(tnode* bt, int level);

void  levelorder(tnode* bt);

int  search_bt(tnode* bt, int target, int *count);

