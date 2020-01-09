#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};

struct node *create_list();

int main(){
	struct node *head=NULL;
	int option;
	while(1){
		printf("\n\t1.create\n ");
		scanf("%d",&option);
		switch(option){
			case 1:
				head = create_list();

struct node *create_list(){
	int size;
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *p;
	while(size){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->next = NULL;
		printf("Enter data\n");
		scanf("%d",&temp->data);
		if(head == NULL){
			head = temp;
		}else{
			p = head;
			temp = p->next;
	}
