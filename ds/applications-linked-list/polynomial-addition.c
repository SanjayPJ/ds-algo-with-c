#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int coeff;
	int exp;
	struct NODE *next;
};

void create_node(int x, int y, struct NODE **poly);
void display_node(struct NODE *node);
void poly_add(struct NODE *poly1, struct NODE *poly2, struct NODE **poly3);

int main(void){

	struct NODE *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

	//first polynomial
	create_node(5, 2, &poly1);
	create_node(4, 1, &poly1);
	create_node(2, 0, &poly1);

	//second polynomial
	create_node(5, 1, &poly2);
	create_node(5, 0, &poly2);

	printf("First polynomial is :: ");
	display_node(poly1);

	printf("Second polynomial is :: ");
	display_node(poly2);

	printf("Sum of polynomial is :: ");
	poly_add(poly1, poly2, &poly3);
	display_node(poly3);

	return 0;
}

void create_node(int x, int y, struct NODE **poly){

	struct NODE *curr_node = *poly;

	if(curr_node == NULL){
		*poly = (struct NODE*)malloc(sizeof(struct NODE));
		curr_node = *poly;
		curr_node->coeff = x;
		curr_node->exp = y;
		curr_node->next = (struct NODE*)malloc(sizeof(struct NODE));
		curr_node = curr_node->next;
		curr_node->next = NULL;
	}else{
		while(curr_node->next != NULL){
			curr_node = curr_node->next;
		}
		curr_node->coeff = x;
		curr_node->exp = y;
		curr_node->next = (struct NODE*)malloc(sizeof(struct NODE));
		curr_node = curr_node->next;
		curr_node->next = NULL;
	}
}

void display_node(struct NODE *node){

	if(node == NULL){
		printf("Polynomial is empty\n");
	}else{
		while(node->next != NULL){
			printf("%dx^%d", node->coeff, node->exp);
			node = node->next;
			if(node->next != NULL){
				printf(" + ");
			}
		}
		printf("\n");
	}
}

void poly_add(struct NODE *poly1, struct NODE *poly2, struct NODE **poly3){

	struct NODE *curr_node;

	if(poly1 || poly2){
		if(*poly3 == NULL){
			*poly3 = (struct NODE*)malloc(sizeof(struct NODE));
			curr_node = *poly3;
		}
		while(poly1->next && poly2->next){
			if(poly1->exp > poly2->exp){
				curr_node->exp = poly1->exp;
				curr_node->coeff = poly1->coeff;
				poly1 = poly1->next;
			}else if(poly1->exp < poly2->exp){
				curr_node->exp = poly2->exp;
				curr_node->coeff = poly2->coeff;
				poly2 = poly2->next;
			}else{
				curr_node->exp = poly1->exp;
				curr_node->coeff = poly1->coeff + poly2->coeff;
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
			curr_node->next = (struct NODE*)malloc(sizeof(struct NODE));
			curr_node = curr_node->next;
			curr_node->next = NULL;
		}
		while(poly1->next || poly2->next){
			if(poly1->next){
				curr_node->exp = poly1->exp;
				curr_node->coeff = poly1->coeff;
				poly1 = poly1->next;
			}else if(poly2->next){
				curr_node->exp = poly2->exp;
				curr_node->coeff = poly2->coeff;
				poly2 = poly2->next;
			}
			curr_node->next = (struct NODE*)malloc(sizeof(struct NODE));
			curr_node = curr_node->next;
			curr_node->next = NULL;
		}
	}
}