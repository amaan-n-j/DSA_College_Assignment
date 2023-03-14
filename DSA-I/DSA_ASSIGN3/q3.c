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

    for (int i = n; i >=0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d ", array[j]);
        }
        printf("\n");
        
    }
    

}
