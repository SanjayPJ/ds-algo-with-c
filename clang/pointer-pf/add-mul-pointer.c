#include<stdio.h>

int i, j;

void read_matrix(int matrix[10][10], int m, int n);
void display_matrix(int matrix[10][10], int m, int n);

int main(){
    
    int matrix[10][10], matrix1[10][10], m, n, m1, n1, opt;

    printf("Enter row and col size of first matrix :: ");
    scanf("%d%d", &m, &n);
    printf("Enter row and col size of second matrix :: ");
    scanf("%d%d", &m1, &n1);

    printf("Enter Elements of 1st matrix :: ");
    read_matrix(matrix, m, n);
    printf("Enter Elements of 2nd matrix :: ");
    read_matrix(matrix1, m1, n1);

    do{
        printf("1. Add\n");
        printf("2. Multiply\n");
        printf("3. Display\n");
        printf("Choose Your option :: ");
        scanf("%d", &opt);

        if(opt == 1){
            printf("Adding...\n");
        }else if(opt == 2){
            printf("Multiplying...\n");
        }else if(opt == 3){
            printf("Displaying 1st matrix :: \n");
            display_matrix(matrix, m, n);
            printf("Displaying 2nd matrix :: \n");
            display_matrix(matrix1, m1, n1);
        }
    }while(opt != 1 && opt != 2 && opt != 3);
    
    return 0;
}

//for reading the matrix
void read_matrix(int matrix[10][10], int m, int n){
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d ", (*(matrix + i) + j));
        }
    }
}

// for displaying the matrix
void display_matrix(int matrix[10][10], int m, int n){
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}