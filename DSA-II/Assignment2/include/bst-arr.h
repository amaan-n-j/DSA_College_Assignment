typedef struct bst
{
	int *tree; 
	int size;
	int last_index;
}bst;

void init_bst(bst *t, int n);

void insert(bst *t, int x);

void inorder_traverse(bst t, int p);

void preorder_traverse(bst t, int p);

void postorder_traverse(bst t, int p);

int isComplete(bst t);

int height(bst t);

int leaf_count(bst t);

void level_traversal(bst t);
