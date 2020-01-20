#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

struct sinfo{
        int * stackp;
        int top;
        int size;
};

int main(){
	int data,option;
	struct sinfo *s1,s2;
	while(1){
		printf("1.Enter expression\n");
		printf("2.Check expression\n");
		printf("3.Exit\n");
		printf("Enter data \t=");
		scanf("%d",&option);
		switch(option){
			case 1:
				scanf("%d",&data);
				create_stack(30);
				push(s1,data);
			break;
			case 3:
				printf("bye bye!!\n");
				return 0;
		}
	}
	return 0;
}

int push(struct sinfo *s,int data){
        if(s->top==s->size)return 0;
        s->stackp[++(s->top)]=data;
        return 1;
}



struct sinfo *create_stack(int size){
        struct sinfo *s = (struct sinfo*)malloc(sizeof(struct sinfo));
        s->top = -1;
        s->size = size;
        s->stackp = (int*)calloc(sizeof(int),size);
        return s;
}


