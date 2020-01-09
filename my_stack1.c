#include<stdio.h>
#include<stdlib.h>

/*static int size;
//int top =-1;
static int *stack=NULL;

int *create_stack(int size){
	return (int*)malloc(sizeof(int));
}*/

struct node{
	int data;
	struct node *next;
}*top = NULL;
int push(int);
int pop();

int main(){
	int option,data;
	while(1){
//		printf("\n\t1.create\n");
		printf("\t1.push\n");
		printf("\t2.pop\n");
		printf("\t10.exit\n");
		printf("Enter your choice\n\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				/*printf("Enter the size of stack\n");
				scanf("%d",&size);
				stack = create_stack(size);*/
				printf("enter data\n");
				scanf("%d",&data);
				data = push(data);
				if(data==0)printf("Stack overflow\n");

			break;
			case 2:
				/*for(int i=1;i=<size;i++)
					printf("Enter data\n");
					scanf("%d",&data);
					data = push(data);
					if(data == -1)printf("stack is underflow\n");
					if(data == 0)printf("stack is overflow\n");
					if(data == 1)printf("\npushed\n");
				}*/
				data =pop();
				if(data == -1)printf("stack underflow\n");
				else printf("Poped data =%d\n",data);

			break;
			case 10:
				printf("bye bye!\a\n");
				return 0;
		}
	}
	return 0;
}

int push(int data){
/*	if(size == 0)return -1;
	if(top == size-1)return 0;
	stack[++top]=data;*/
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)return 0;
	temp->next=top;
	temp->data=data;
	top=temp;
	return 1;
}

int pop(){
	struct node *temp;
	int data;
	if(top == NULL)return -1;
	temp=top;
	data=temp->data;
	top=top->next;
	free(temp);
	return data;
}

