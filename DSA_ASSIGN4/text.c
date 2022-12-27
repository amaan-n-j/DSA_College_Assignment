#include<stdio.h>

int main(){
	int array[5] = {1,2,3,4,5};
	printf("%d",array[-5]);
	array[-100] = 79;
	printf("%d", array[-100]);
	return 0;
}
