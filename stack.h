#include<stdlib.h>
struct sinfo{
	int * stackp;
	int top;
	int size;
};

struct sinfo *create_stack(int size){
	struct sinfo *s = (struct sinfo*)malloc(sizeof(struct sinfo));
	s->top = -1;
	s->size = size;
	s->stackp = (int*)calloc(sizeof(int),size);
	return s;
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

