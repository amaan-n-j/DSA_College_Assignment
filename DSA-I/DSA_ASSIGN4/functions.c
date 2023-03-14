#include<stdio.h>
int swap(int array[], int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int linear_search(int array[], int size, int target){
	for(int i = 0; i < size ; i++){
		if(target == array[i]){
			printf("Target found at %d index.",i);
			return i;
		}
	}
	printf("Target not found.");
	return -1;
}

int binary_search(int array[] , int size, int target){
	int low , mid, high;
	low = 0;
	high = size -1;
	while(high >= low){
		mid = (high+low)/2;
		if(array[mid] == target){
			printf("Target found at %d", mid);
			return mid;
		}else if(array[mid] > target){
			high = mid -1;
		}else{
			low = mid + 1;
		}
	}
}


void bubble_sort(int array[] ,int size){
		int i , j ;
		for(i = 0 ; i < size; i++){
			for(j = 0; j< size-1-i; j++){
				if(array[j] > array[j+1]){
					swap(array, &array[j], &array[j+1]);
				}
			}
		}
}

void selection_sort(int array[], int size){
	int i , j, min ;
	for(i =0; i<size; i++){
		min = i;
		for(j = i ; j< size; j++){
			if(array[min]>array[j]){
				min = j;
			}
		}
		if(min != i){
			swap(array, &array[i], &array[min]);
		}
	}
}

void insertion_sort(int array[], int size){
	int i,j,temp ;
	for(i = 0; i<size; i++){
		temp = array[i];
		j = i-1;
		while(j>=0 && array[j]> temp){				
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
		}
	}

