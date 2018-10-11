#include<stdio.h>

int main(int argc, char const *argv[]){
    int id_source = 23, id2_source = 34;
    int *id = &id_source, *id2 = &id2_source;
    // int* id, id2; //wrong

    printf("%p %p", id, id2);
    
    return 0;
}
