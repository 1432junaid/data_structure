#include<stdio.h>
#include<stdlib.h>
int size;
int *create_queue();
int *queue=NULL;
int en_queue(int);
int fornt=0;
int rear=-1;
int main(){
	int option,data;
	while(1){
		printf("\n\t1.create \n\t2.en-queue \n\t3.de-queue \n\t10.exit \n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter the size of queue\n");
				scanf("%d",&size);
				queue = create_queue(size);
			break;
			case 2:
				printf("Enter data\n");
				printf("%d",&data);
				data = en_queue(data);
				if(data == 0)printf("\nfull\n");
				if(data == -1)printf("\nqueue dosen't exist\n");
				if(data == 1)printf("data added\n");
			break;
			case 10:
				return 0;
		}
	}
	return 0;
}

int *create_queue(int size){
	return (int*)calloc(sizeof(int),size);
}

int en_queue(int data){
	if(rear == size-1)return 0;
//	if(rear == -1)return -1;
	queue[++rear]=data;
	return 1;
}

//int de_queue(){

