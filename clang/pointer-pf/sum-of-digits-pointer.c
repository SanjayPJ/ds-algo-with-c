#include<stdio.h>

void sum_of_digits(int temp, int *ptr_sum){
    int i;
    *ptr_sum = 0;
    while(temp > 0){
        *ptr_sum += (temp % 10);
        temp /= 10;
    }
}

int main(int argc, char const *argv[]){
    int num, sum, temp;
    int *ptr_sum = &sum;

    printf("Enter a Number :: ");
    scanf("%d", &num);
    temp = num;
    sum_of_digits(temp, ptr_sum);
    printf("Sum of Digits of %d is %d\n", num, sum);

    return 0;
}
