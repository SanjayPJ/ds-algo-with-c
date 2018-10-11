#include<stdio.h>

void swap(int *ptra, int*ptrb){
    int temp;
    temp = *ptra;
    *ptra = *ptrb;
    *ptrb = temp;
}

void swap_other_method(int *ptra, int *ptrb){
    *ptra = *ptra + *ptrb;
    *ptrb = *ptra - *ptrb;
    *ptra = *ptra - *ptrb;
}

int main(int argc, char const *argv[]){
    int a, b;
    int *ptra = &a, *ptrb = &b;
    
    printf("Enter two numbers :: ");
    scanf("%d%d", &a, &b);
    printf("Enterd Numbers :: %d %d\n", a, b);
    printf("printing using simple swap method\n");
    swap(ptra, ptrb);
    printf("Swaped Numbers :: %d %d\n", a, b);
    printf("printing using the other swap method\n");
    swap_other_method(ptra, ptrb);
    printf("Swaped Numbers :: %d %d\n", a, b);

    return 0;
}
