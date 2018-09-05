#include<stdio.h>

int display(int arr[], int range){
	int i;
	for(i = 0; i < range; i++ ){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int insert(int arr[], int range, int pos, int ele){
	int i;
	for(i = range - 1; i >= pos - 1; i-- ){
		arr[i + 1 ] = arr[i];			
	}
	arr[pos - 1] = ele;
	display(arr, range + 1);
}

int delete(int arr[], int range, int pos){
	int i;
	for(i = pos; i < range; i++ ){
		arr[i - 1] = arr[i];
	}
	display(arr, range - 1);
}

int main(){
	int arr[10], range, pos, ele, i, opt;
	printf("enter the range of the array :: ");
	scanf("%d", &range);
	for(i = 0; i < range; i++){
		printf("enter %d th element :: ", i);
		scanf("%d", &arr[i]);
	}
	do{
		printf("1.Insert\n2.Delete\n3.Display\n");
		printf("choose your option :: ");
		scanf("%d", &opt);
		if(opt == 1){
			printf("enter the element to be inserted :: ");
			scanf("%d", &ele);
			printf("Enter position of the element to be inserted :: ");
			scanf("%d", &pos);
			insert(arr, range, pos, ele);
		}else if(opt == 2){
			printf("enter the position of the element to be deleted :: ");
			scanf("%d", &pos);
			delete(arr, range, pos);
		}else{
			display(arr, range);
		}
		printf("do you wish to continue (1/0) :: ");
		scanf("%d", &opt);
	}while(opt == 1);
}
