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
	while(1){
		printf("1.Enter expression\n");
		printf("2.Check expression\n");
		printf("3.Exit\n");
		printf("Enter data \t=");
		scanf("%d",&option);
		switch(option){
			case 1:
				scanf("%d",&data);
				push(data);
				if()
			break;
	return 0;
}
int push(char a){
        if(s->top==s->size)return 0;
        s->stackp[++(s->top)]=data;
        return 1;
};
create(int size);
	return (char)calloc(sizeof(char),size);
}
int push(struct sinfo *s,int data){
        if(s->top==s->size)return 0;
        s->stackp[++(s->top)]=data;
        return 1;
};


