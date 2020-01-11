#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;
int enqueue(int);
int dequeue();

int main(){
	int option,data,e,d;
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
				if(e==-1)printf("\n\nqueue dose not exist\n\n");
				if(e==0){
					printf("\n\nenqueued\n\n");
				}else{
					printf("\n\nqueue is empty\n\n");
				}
			break;
			case 2:
				d = dequeue();
				if(d == -1){
					printf("\n\nno data\n\n");
				}else{
					printf("\n%d data is dequeued\n\n",d);
				}
			break;
			case 5:
				printf("\n\nbye bye\n");
				return 0;
		}
	}
	return 0;
}

int enqueue(int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)return -1;
	temp->data = data;
	temp->next = NULL;
	if(rear == NULL && front == NULL){
		rear = temp;
		front = temp;
		return 0;
	}
	rear->next = temp;
	rear=rear->next;
	return 1;
}

int dequeue(){
	if(front == NULL && rear == NULL)return -1;
	struct node * temp;
	temp = front;
	front = front->next;
	if(front==NULL)rear=NULL;
	int data = temp->data;
	free(temp);
	return data;
}
