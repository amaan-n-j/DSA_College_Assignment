#include<stdio.h>
#include<stdlib.h>

// Here we are using recursion to solve the tower of hanoi problem

void TOH(int n , int TA , int TB , int TC){
	if (n>0){

		TOH(n-1, TA, TC,TB); 
		printf("(%d,%d)",TA,TC); //the ordered pair of the source and destination tower is printed
		TOH(n-1,TB,TA,TC);
	}
}

int main(){
	TOH(3,1,2,3);
	return 0;
}
