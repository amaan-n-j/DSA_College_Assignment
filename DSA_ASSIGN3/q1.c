#include<stdio.h>
#define size 10
int main(){
    int n ;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int array[size];

    //Taking the elements form user 
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element: ", i+1);
        scanf("%d", &array[i]);
    }

    //reversing the elements
    for (int k = 0; k < n/2; k++)
    {
        int temp = array[k];
        array[k] = array[n-1-k] ;
        array[n-1-k] = temp;
    }

    //printing the element

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    
    
    
}
