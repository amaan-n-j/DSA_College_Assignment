#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void printRandoms(int upper,
                            int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
        (upper + 1));
        printf("%d\n", num);
    }
}

int main(int argc, char const *argv[]){
	
	long long int upper_range = atoi(argv[1]);
	long long int count = atoi(argv[2]);
	printRandoms(upper_range,count);

	return 0;
}
