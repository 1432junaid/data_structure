/*static int top = -1;
static int size;
static int *stack = NULL;
int *create_stack(int);
int push(int);
int pop();


int *create_stack(int size){
        return (int*)calloc(sizeof(int),size);
}

int push(int data){
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
*/


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

