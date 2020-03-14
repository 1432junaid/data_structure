#include<stdio.h>
#include<stdlib.h>
#define type int
struct node{
	void *data;
	struct node *next;
}*head = NULL;

struct node* create_list(int size){
	for(int i=0;i<size;i++){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		char t[10];
		temp->next = NULL;
		printf("Enter data \t:");
		type *x =(type*)malloc(sizeof(type));
		if(type == int )t = "%d";
		else if(type == char)t ="%c";
		else if(typr == float || type == double)t="%f";
		scanf(t,x);
		temp->data =x;
		if(head == NULL){
			head = temp;
		}else{
			struct node*p =head;
			while(p->next != NULL){
				p=p->next;
			}
			p->next = temp;
		}
	}
	return head;
}

void traverse(head){
	while(head != NULL){
		printf("%d",*((type)(head->head)));
		head = head->next;
	}
}

int main(){
	int size;
	printf("Enter size of node\n");
	scanf("%d",size);
	struct node *head;
	head = create_list(size);
	traverse(head);
	return 0;
}
