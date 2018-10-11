#include<stdio.h>

int main(void){

	char string_array[10][10];
	int string_count, i;

	printf("Enter No of String :: ");
	scanf("%d", &string_count);

	printf("Enter Strings :: ");
	for(i = 0; i < string_count; i++){
		scanf("%s", string_array[i]);	
	}

	printf("Entered Strings are :: ");
	for (int i = 0; i < string_count; i++){
		printf("%s\t", string_array[i]);
	}
	printf("\n");

	return 0;
}
