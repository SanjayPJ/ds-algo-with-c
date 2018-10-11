#include <stdio.h>

int main(int argc, char const *argv[])
{
	char str[10];
	int string_length = 0, i;

	printf("Enter string :: ");
	scanf("%s", str);

	for(i = 0; str[i]!='\0'; i++ ){
		string_length++;
	}

	printf("%s\n", str);
	printf("Length of String :: %d\n", string_length);

	return 0;
}