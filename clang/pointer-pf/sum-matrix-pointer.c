#include<stdio.h>

int i, j;

//for reading matrix
void read_matrix(int *ptr_matrix, int m, int n){
    for(i = 0; i < m; i++ ){
        for(j = 0; j < n; j++){
            scanf("%d", ptr_matrix);
            ptr_matrix++;
        }
    }
}

//for displaying a matrix
void display_matrix(int *ptr_matrix, int m, int n){
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", *ptr_matrix);
            ptr_matrix++;
        }
        printf("\n");
    }
}

//for displaying matrix locations
void display_matrix_location(int *ptr_matrix, int m, int n){
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%p\t", ptr_matrix);
            ptr_matrix++;
        }
        printf("\n");
    }
}

//for displaying matrix sum
void matrix_sum(int *ptr_matrix, int m, int n, int *ptr_sum){
    *ptr_sum = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            *ptr_sum += *ptr_matrix;
            ptr_matrix++;
        }
    }
}


int main(void){
    int matrix[10][10], m, n, sum;
    int *ptr_matrix = &matrix[0][0], *ptr_sum = &sum;

    printf("Enter Row and Column Size :: ");
    scanf("%d%d", &m, &n);

    printf("Enter Numbers :: ");
    read_matrix(ptr_matrix, m, n);
    printf("Entered Matrix :: \n");
    display_matrix(ptr_matrix, m, n);
    printf("Ented Matrix Locations :: \n");
    display_matrix_location(ptr_matrix, 10, 10);
    display_matrix_location(ptr_matrix, m, n);
    // matrix_sum(ptr_matrix, m, n, ptr_sum);
    printf("Sum of Matrix is :: %d\n", sum);

    return 0;
}
