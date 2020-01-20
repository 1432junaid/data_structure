#include<stdio.h>
#include<stdlib.h>

struct sinfo{
        int * stackp;
        int top;
        int size;
};


static int top = -1;
static int size;
static int *stack = NULL;
int *create_stack(int);
int push(int);
int pop();
//struct sinfo *stack = NULL;

struct sinfo *create_stack(int size){
        struct sinfo *s = (struct sinfo*)malloc(sizeof(struct sinfo));
        s->top = -1;
        s->size = size;
        s->stackp = (int*)calloc(sizeof(int),size);
        return s;
}

int main(){
	int option,size;
	while(1){
		printf("\n\t1.create stack\n");
		printf("\t2.push\n");
		printf("\t3.pop\n");
		printf("\t4.Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter size of stack");
				scanf("%d",&size);
				create_stack(size);
			break;
			case 4:
				printf("Exit");
				return 0;
		}
	}
	return 0;
}
int push(struct sinfo *s,int data){
        if(s->top==s->size)return 0;
        s->stackp[++(s->top)]=data;
        return 1;
};

int pop(struct sinfo *s){
        if(s->top==-1)return -1;
        return s->stackp[s->top--];
}



