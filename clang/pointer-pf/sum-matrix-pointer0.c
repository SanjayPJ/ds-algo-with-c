#include<stdio.h>

int i, j;

void read_matrix(int matrix[10][10], int m, int n);
void display_matrix(int matrix[10][10], int m, int n);

int main(int argc, char const *argv[]){

    int matrix[10][10], m, n;
    
    printf("Enter row and col size :: ");
    scanf("%d%d", &m, &n);

    read_matrix(matrix, m, n);
    display_matrix(matrix, m, n);

    return 0;
}

//for reading the matrix
void read_matrix(int matrix[10][10], int m, int n){
    printf("Enter Elements of the matrix :: ");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d ", (*(matrix + i) + j));
        }
    }
}

// for displaying the matrix
void display_matrix(int matrix[10][10], int m, int n){
    printf("Entered matrix is :: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}