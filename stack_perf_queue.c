#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

static int *s1=NULL;
static int *s2=NULL;
int main(){
	int option,data,p;
	while(1){
		printf("Enter option\n\n");
		printf("1.create\n");
		printf("2.push\n");
		printf("3.pop\n");
		printf("4.Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("enter the size of stack\n");
				scanf("%d",&size);
				stack = create_stack(size);
			break;
			case 2:
				printf("Enter data\n");
                                scanf("%d",&data);
                                p = push(data);
                                if(p == 0)printf("\n\n\toverflow\n\n");
                                if(p == 1)printf("\n\n\tpushed\n");
                                if(p == -1)printf("\n\n\tstack does not exist \n");
			break;
			case 3:
				s1=stack;
				while(pop()>1){
					s2 = pop();
				}

			break;
			case 4:
				printf("bye bye\n");
				return 0;
		}
	}
	return 0;
}
