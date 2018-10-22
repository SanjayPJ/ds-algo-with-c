#include <stdio.h>

int main(void){
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int max = arr[0], i;

    for(i = 0; i < 7; i++){
        if (arr[i] > max ){
            max = arr[i];
        }
    }
    printf("%d\n", max);

    return 0;
}