
#include<stdio.h>

int min(int a, int b){
	int m = a;
	if( b < m ){
		m = b;
	}
	return m;
}

int main(){
	int a = min(12, 34);
	printf("%d", a);
	return 0;
}
