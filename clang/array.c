
#include <stdio.h>

//can also use void
int main()
{
    int i, var;
    //declaring and intializing array
    int mark[10] = {1, 3, 4, 6};
    printf("Display all the elements from the array\n");
    for(i = 0; i < 10; i++ ){
        printf("%d\t", mark[i]);
    }
    printf("\n");
    printf("Enter position of the element :: ");
    scanf("%d", &var);
    printf("Element :: %d\n", mark[var-1]);
    printf("Enter a number to insert it into 3rd position of array :: ");
    scanf("%d", &var);
    mark[2] = var;
    printf("Element :: %d\n", mark[2]);
    return 0;
}
