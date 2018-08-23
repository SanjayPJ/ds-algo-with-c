

#include<stdio.h>

int min(int num1, int num2);

int main(){
	int num1 = 56, num2 = 67;
	int min22 = min( num1, num2 );
	printf("%d\n", min22);
	printf("%d\n", min( 6, 89));
	return 0;
}

int min( int num1, int num2){
	if( num1 < num2 ){
		return num1; 
	}else{
		return num2;
	}
}
