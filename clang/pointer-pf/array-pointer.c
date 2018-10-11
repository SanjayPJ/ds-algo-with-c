#include<stdio.h>

int i;

//displaying an array
void display_array(int arr[10], int range){
    int *ptr_arr = arr;
    for (i = 0; i < range; i++){
        printf("%d\t", *ptr_arr);
        ptr_arr++;
    }
    printf("\n");
}
//display another method
void display_array_other(int arr[10], int range){
    for (i = 0; i < range; i++){
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

//reading an array
void read_array(int arr[10], int range){
    int *ptr_arr = arr;
    for (i = 0; i < range; i++){
        scanf("%d", ptr_arr);
        ptr_arr++;
    }
}

//reading an array other method
void read_array_other(int arr[10], int range){
    for (i = 0; i < range; i++){
        scanf("%d", arr + i);
    }
}

int main(int argc, char const *argv[]){
    int arr[10], range;
    
    printf("Enter Range :: ");
    scanf("%d", &range);
    printf("Enter Numbers :: ");
    read_array(arr, range);
    display_array(arr, range);
    printf("The other Method\n");
    printf("Enter Numbers :: ");
    read_array_other(arr, range);
    display_array(arr, range);

    return 0;
}
