#include<stdio.h>
#include<stdlib.h>

int *queue=NULL;
int rear = -1;
int front = 0;
int *create_queue(int);
int enqueue(int *,int);
int dequeue(int *);
int size;
int main(){
	int option,data,c,d;
	while(1){
		printf("\n\t1.create\n");
		printf("\t2.enqueue\n");
		printf("\t3.dequeue\n");
		printf("\t5.exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter the size of queue\n");
				scanf("%d",&size);
				queue = create_queue(size);
			break;
			case 2:
				printf("enter data\n");
				scanf("%d",&data);
				c = enqueue(queue,data);
				if(c== -1)printf("queue does not exist\n");
				if(c == 0){printf("\n\t!queue is full\n\n");}else{printf("\ndata is added\n\n");}
			break;
			case 3:
				d = dequeue(queue);
				if(d == -1){
					printf("queue does not exist");
				}else{
					printf("%d is deleted\n\n",d);
				}
			break;
			case 5:
				printf("\n\nbye bye\n");
				return 0;

		}
	}

}

int *create_queue(int size){
		return (int*)calloc(sizeof(int),size);
}

int enqueue(int *p,int data){
	if(p==NULL)return -1;		//queue does not exist
	if(rear >= size-1)return 0;	//queue is full
	if(p!=NULL){
		queue[++rear] = data;
	}
	return 1;			//queue is created
}

int dequeue(int *p){
	int *temp;
	if(p==NULL)return -1;		//queue does not exist
	if(p!=NULL){			//1 element is dequeue
		temp=p;
		p=NULL;
		p=temp[front++];
	}
	return (*p);
}

