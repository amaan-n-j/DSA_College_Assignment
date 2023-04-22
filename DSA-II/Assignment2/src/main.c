#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../include/queue.h"
#include "../include/bst-arr.h"

int main()
{
    bst x;
	init_bst(&x, 20);

	insert(&x, 8);
	insert(&x, 5);
	insert(&x, 10);
	insert(&x, 3);
	insert(&x, 7);
	insert(&x, 9);
	insert(&x, 11);
	
    if(isComplete(x))
    {
        printf("Tree is Complete\n");
    }
    else
    {
        printf("Tree is not Complete\n");
    }

    level_traversal(x);

    printf("\n");

    printf("The height of the tree %d\n",height(x));

    printf("The Leaf nodes of tree %d \n",leaf_count(x));
    return 0;
}
