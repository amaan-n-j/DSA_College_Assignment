#include<stdio.h>
#include<stdlib.h>
#include"searching.h"
#include"sorting.h"

int main(){
	int n, target, ch, i ,j , k;

	printf("1- Linear Search\n");
	printf("2- Binary Search\n");
	printf("3- Selection Sort\n");
	printf("4- Bubble Sort\n");
	printf("5- Insertion Sort\n");
	printf("Enter Choice:");
	scanf("%d", &ch);
	if(ch == 1 || ch ==2){
		printf("Enter the number of elements of the array to be generated:");
		scanf("%d",&n);
		int array[n];
		for(i = 0; i <n;i++){
			printf("Enter the %d element",i);
			scanf("%d",&array[i]);
		}

		//printing the array
		for(j = 0; j <n ;j++){
			printf("%d ",array[j]);
		}

		//taking target
		printf("\nEnter the target to find :");
		scanf("%d",&target);
		
		if(ch == 1){
			linear_search(array, n , target);
		}
		else{
			binary_search(array, n , target);
		}
	}
	else if(ch == 3||ch == 4 || ch == 5 ){
	
		printf("Enter the number of elements of the array to be generated:");
		scanf("%d",&n);
		int array[n];
		// making array with random numbers from 1-100
		for(i = 0 ; i < n ;i++){
			array[i] = rand() %100 +1;
		}
		
		//printing the array
		for(j = 0; j <n ;j++){
			printf("%d ",array[j]);
		}

		if(ch == 3){
			//selection sort
		      	selection_sort(array,n);	
			
			printf("\n Printing after Selection sort\n");
			//printing the array after selection sort
			for(j = 0; j <n ;j++){
				printf("%d ",array[j]);
			}
		}
		else if(ch == 4){
			//bubble sorting
			bubble_sort(array , n);

			printf("\n Printing after Bubble sort\n");
			//printing the array after bubble sort
			for(j = 0; j <n ;j++){
				printf("%d ",array[j]);
			}
		}
		else{
			//insertion sorting
			insertion_sort(array , n);

			printf("\n Printing after insertion sort\n");
			//printing the array after insertion sort
			for(j = 0; j <n ;j++){
				printf("%d ",array[j]);
			}
		}
	}

}
