#include<stdio.h>
int main( ) {
	int x[5] = {1,2,3,4,5};
	int* p ;

	p=&x[1];
	printf("%p \n",p);
	return 0;
}
