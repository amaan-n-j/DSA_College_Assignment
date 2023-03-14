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


    int target ;
    printf("Enter the target elements:");
    scanf("%d",&target);

    int lesser_target = -999999 , greater_target = 999999;

    for (int i = 0; i < n; i++)
    {
        if (array[i] > target )
        {
            if (array[i] < greater_target)
            {
                greater_target = array[i];
            }
            
        }
        else if (array[i] == target)
        {
            greater_target = target;
            lesser_target = target;
            break;
        }
        
        else
        {
            if (array[i] > lesser_target)
            {
                lesser_target = array[i];
            }

        }
        
    }

    printf("Lesser Number:%d \n", lesser_target);
    printf("Greater Number: %d \n", greater_target);
    
    return 0;
}
