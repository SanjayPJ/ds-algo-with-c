#include<stdio.h>

void factorial(int *ptrnum, long *ptrfact){
    int i;
    *ptrfact = 1;
    for(i = 1; i <= *ptrnum; i++){
        *ptrfact = *ptrfact * i; 
    }
}

int main(){
    int num;
    long fact;
    int *ptrnum = &num;
    long *ptrfact = &fact;

    printf("Enter Number:: ");
    scanf("%d", &num);
    factorial(ptrnum, ptrfact);
    printf("factorial of %d is %ld\n", num ,fact);

    return 0;
}