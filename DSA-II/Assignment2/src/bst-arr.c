#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../include/bst-arr.h"
#include "../include/queue.h"

void init_bst(bst *t, int n) 
{
	int i;
	t->tree = (int *)malloc(sizeof(int) * n);
	t->size = n;
	for (i = 0; i < n; i++)
    {
        t->tree[i] = INT_MIN;
    } 
	t->last_index = 0;
	return;
}

void insert(bst *t, int x) 
{
	int i = 0;
	if (t->tree[0] == INT_MIN)
	{
		t->tree[0] = x;
		return;
	}
	while (i < t->size && t->tree[i] != INT_MIN)
	{
		if (t->tree[i] == x)
        { 
			return;
        }
		if (t->tree[i] < x)
        { 
			i = 2 * i + 2;
        }
		else
        {
			i = 2 * i + 1;
        }
	}
	if (i < t->size)
    {
		t->tree[i] = x;
		if(t->last_index < i) 
			t->last_index = i;
    }
	return;
}

void inorder_traverse(bst t, int p)
{
	if (p< t.size && t.tree[p] != INT_MIN)
	{
		inorder_traverse(t, 2 * p + 1); 
		printf("%d ", t.tree[p]);		  
		inorder_traverse(t, 2 * p + 2); 
	}
	return;
}

void preorder_traverse(bst t, int p)
{
    if (p< t.size && t.tree[p] != INT_MIN)
	{
        printf("%d ", t.tree[p]);
		preorder_traverse(t, 2 * p + 1); 		  
		preorder_traverse(t, 2 * p + 2); 
	}
	return;  
}

void postorder_traverse(bst t, int p)
{
    if (p< t.size && t.tree[p] != INT_MIN)
	{
		postorder_traverse(t, 2 * p + 1); 		  
		postorder_traverse(t, 2 * p + 2);
        printf("%d ", t.tree[p]);
	}
	return;  
}

int isComplete(bst t)
{
	int i;
	int x = 1;
	for (i = 0; i < t.size - 1; i++)
	{
		if (t.tree[i] == INT_MIN && t.tree[i + 1] != INT_MIN)
		{
			x = 0;
			break;
		}
	}
	return x;
}

int height(bst t){
	if(t.tree == NULL) return 0;
	int i , j, h;
	h = 0;
	for(i = 1 ; i < t.size ; i*=2){
		for(j = 0 ; j < i ; j++){
			if(t.tree[j] != INT_MIN){
				j = i;
				i *= 2;
				h++;
			}
			else{
				return h;
			}

		}
	}
}

int leaf_count(bst t){
	if (t.tree == NULL)return 0;
	queue q;
	initQ(&q);
   	int count_ref = 0 , q_ref = 0;
   	enqueueQ(&q,0);
    	while (!isEmptyQ(q) && q_ref <=  t.last_index)
   	{
        	q_ref = dequeueQ(&q);
       	 	if (t.tree[2*q_ref+1] != INT_MIN)
           		enqueueQ(&q,2*q_ref+1);
        	if (t.tree[2*q_ref+2] != INT_MIN)
	            	enqueueQ(&q,2*q_ref+2);
       		if (t.tree[2*q_ref+1] == INT_MIN && t.tree[2*q_ref+2] == INT_MIN)
           		 count_ref++;
 	 }
   	 return count_ref;
}

void level_traversal(bst t){
	if (t.tree == NULL ) return ;
	int i ;
	for(i = 0 ; i <= t.last_index; i++){
		if(t.tree[i] != INT_MIN){
			printf("%d ",t.tree[i]);
		}
	}

}


