#include<stdio.h>
#include<stdlib.h>

static int top = -1;
static int size;
static int *stack = NULL;
static int *stack1 = NULL;
int *create_stack(int);
int push(char);
int pop();


int main(int argc,char *argv[]){
	int option;
	char data;
	while(1){
		printf("\n\t1.create \n\t2.push \n\t3.pop \n\t4.exit\n\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter size of stack\n");
				scanf("%d",&size);
				stack = create_stack(size);
			break;
			case 2:
				printf("Enter data\n");
				scanf("%c",&data);
				data = push(data);
				if(data == 0)printf("\n\n\toverflow\n\n");
				if(data == 1)printf("\n\n\tpushed\n");
				if(data == -1)printf("\n\n\tstack does not exist \n");
			break;
			case 3:
				data = pop();
				if(data == -1){
					printf("Stack undrflow");
				}else{
					printf("poped data =%c\n",data);
//					if(data)
				}
				if(data == -2)printf("does not exist\n");
			break;
			case 4:
				return 0;
		}
	}
	return 0;
}


int *create_stack(int size){
	return (int*)calloc(sizeof(int),size);
}

int push(char data){
	if(size == 0)return -1;
	if(top == size-1)return 0;
	stack[++top]=data;
	return 1;
}

int pop(){
	if(size == 0)return -2;
	if(size == -1)return -1;
	return stack[top--];
}
