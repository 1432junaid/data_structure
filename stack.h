static int top = -1;
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


