#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head=NULL;
int enqueue(int);


int main(){
	int option,data;
	while(1){
		printf("Enter your choise \n");
		printf("\t1.enqueue\n");
		printf("\t2.dequeue\n");
		printf("\t5.exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter data\n");
				scanf("%d",&data);
				e = enqueue(data);
			break;
			case 2:
				dequeue();
			break;
			case 5:
				priintf("\n\nbye bye\n");
				return 0;
		}
	}
	return 0;
}

int enqueue(int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)return 0;
	
