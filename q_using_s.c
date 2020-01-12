#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int enqueue(struct sinfo *s1,int data){
	int result = push(s1,data);
	if(result == 0)return 0;
	return 1;
}

int dequeue(struct sinfo *s1, struct sinfo *s2){
	if(s1->top == -1)return -1;
	while(s1->top != -1){
		push(s2,pop(s1));
	}
	int data = pop(s2);
	while(s2->top != -1){
		push(s1,pop(s2));
	}
	return data;
}

int main(){
	int option ,data,result1,result2;
	struct sinfo *s1,*s2;
	s1 = create_stack(20);
	s2 = create_stack(15);
	while(1){
		printf("Enter option\n");
//		printf("1.create\n");
		printf("1.enqueue\n");
		printf("2.dequeue\n");
		printf("3.exit\n");
		scanf("%d",&option);

		switch(option){
			case 1:
				printf("Enter data\n");
				scanf("%d",&data);
				result1 = enqueue(s1,data);
				if(result1 == 0){
					printf("Empty\n");
				}else{
					printf("data enqueued");
				}
			break;
			case 2:
				result2 = dequeue(s1,s2);
				if(result2 == -1){
					printf("Empty\n");
				}else{
					printf("\n%d is dequeued\n",result2);
				}
			break;
			case 3:
				return 0;
		}
	}
	return 0;
} 
