#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *create_list();
void traverse(struct node*);
void insert(struct node**,int ,int);
int count(struct node*);
int insert(struct node**,int ,int);
int main(){
	struct node *head=NULL;
	int option, count1=0, c;
	while(1){
		printf("\n\t1.create\n ");
		printf("\t2.traverse\n");
		printf("\t3.count\n");
		printf("\t4.insert\n");
		printf("\t10.exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				head = create_list();
			break;
			case 2:
				traverse(head);
			break;
			case 3:
				c = count(head);
				printf("number of nodes are\t=%d",c);
			break;
			case 10:
				return 0;
		}
	}
	return 0;
}

struct node *create_list(){					//create linked list
	int size;
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *p;
	printf("Enter the size of node to be create\n");
	scanf("%d",&size);
	while(size){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->next = NULL;
		printf("Enter data\n");
		scanf("%d",&temp->data);
		if(head == NULL){
			head = temp;
		}else{
			p = head;
			while(p->next != NULL) p = p->next;
			p->next=temp;
		}
		size--;
	}
	return head;
}

void traverse(struct node *p){					//traverse linked list
	while(p != NULL){
		printf("\t%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

int count(struct node *start){					//count number of nodes
	int count1=0;
	while(start != NULL){
		start = start->next;
		count1++;
	}
	return count1;
}
