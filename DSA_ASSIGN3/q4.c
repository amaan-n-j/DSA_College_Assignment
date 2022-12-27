#include<stdio.h>
#define size 20

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

    int sum = 0;
    for (int k = 0; k < n; k += 2)
    {      
	    sum += array[k];
    }

    printf("The sum of even elements is %d.", sum);

    return 0;
}
