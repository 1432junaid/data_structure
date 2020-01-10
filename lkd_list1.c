#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * create_list();				//prototype declaration
int insert(struct node**,int, int);			//prototype declarration
void traverse_list(struct node*);			//prototype decleration
int count(struct node*);
int search(struct node*,int);
int delete_list(struct node**,int);


int main(int argc,char*arg[]){
	struct node *head= NULL;
	int option,n,c,data,p,position;


	while(1){
		printf("\n\t1.Create\n\t2.Traverse\n \t3.insert\n \t4.count\n \t5.delete\n \t6.search\n \t10.exit\n\n");
		scanf("%d",&option);
		switch(option){
			case 1:				//for create node
				head =create_list();
			break;
			case 2:				//for traverse node
				traverse_list(head);
			break;
			case 3:				//for insert
				printf("Enter data \n");
				scanf("%d",&data);
				printf("Enter position \n");
				scanf("%d",&position);
				int p = insert(&head,data,position);
				if(p==1){
					printf("position found\n");
				}else{
					printf("position not found\n");
				}
			break;
			case 4:				//for count number of nodes
				//printf("number of nodes are\n");
				p = count(head);
				printf("\nnumber of nodes=%d\n",p);
			break;
			case 5:
				printf("Enter position\n");
				scanf("%d",&c);
				c=delete_list(&head,c);
				if(c==1){
					printf("delete node\n");
				}else{
					printf("not delete data\n");
				}
			break;
			case 6:
				printf("Enter data to be searched\n");
				scanf("%d",&n);
				c=search(head,n);
				if(c==1){
					printf("data found\n");
				}else{
					printf("data  not found\n");
				}
			break;
			case 10:
				return 0;
			break;

			default:
				printf("\nwrong option\n");
		}
	}
return 0;
}


struct node * create_list(){						//create function
	int number;
	struct node *head=NULL,*temp =NULL,*p;
	printf("Enter number of nodes to be created\n");
	scanf("%d",&number);
	while(number){
		temp = (struct node*) malloc (sizeof(struct node));
		temp ->next = NULL;
		printf("Enter Data of node\n");
		scanf("%d",&temp->data);
		if(head==NULL){
			head = temp;
		}else{
			p=head;
			while(p->next != NULL) p = p->next;
			p->next = temp;
		}
		number--;
	}
	return head;
}


void traverse_list(struct node *p){					//traverse function
		while(p!=NULL){
			printf("\t%d\t",p->data);
			p = p->next;
		}
		printf("\n");
}


int count(struct node *start){						//count function
	struct node *p;
	int count = 0;
	p =start;
	while(p!=NULL){
		p=p->next;
		count++;
	}
	return count;
}

int search(struct node *start, int n){					//search function
	struct node *p;
	p=start;
	while(p!=NULL){
		if(p->data==n){
			return 1;
		}else{
		p=p->next;
		}
	}
	return 0;
}

int insert(struct node **hpointer,int data, int position){		//insert function
	if(*hpointer == NULL && position >1)return 0;
	struct node *temp,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data =data;
	if(*hpointer == NULL && position==1){
		*hpointer = temp;
		return 1;
	}
	if(*hpointer != NULL && position == -1){
		p=*hpointer;
		while(p->next!=NULL)p=p->next;
		p->next = temp;
		return 1;
	}
	if(*hpointer != NULL && position ==1){
		temp->next = *hpointer;
		*hpointer = temp;
		return 1;
	}
	int count=0;p=*hpointer;
	while(p != NULL && count != position-1){
		count++;
		p = p->next;
	}
	if(count == position-1){
		temp->next = p->next;
		p->next = temp;
		return 1;
	}
	return 0;
}

int delete_list(struct node **start,int position){			//delete function
	struct node *p,*q;
	p=*start;
	int count=0,count1=1;
	if(p == NULL && position>1)return 0;	//linklist is empty;
	while(p != NULL){
		p=p->next;
		count++;
	}
	if(count < position)return 0; 		//position not exist in linklist
	p=*start;
	if(p!=NULL && position ==1){		//first  node delete
		*start = p->next;
		free(p);
		return 1;
	}
	p=*start;
	q=*start;
	if(p != NULL && position ==-1){		//last node delete
		while(q->next!=NULL){
			p=q;
			q=q->next;
		}
		p->next = q->next;
		free(q);
	return 1;
	}
	while(p!=NULL && count1 != position-1){ //brtween node delete
		count1++;
		p=p->next;
	}
	if(count1 == position-1){
		q = p->next;
		p->next = q->next;
		free(q);
	return 1;
	}
}
/*
int search(struct node *start,int data){
	while(start!=NULL){
		if(start->data == data){
			return 1;
		}else{
			start = start->next;
		}
	}
	return 0;
}
*/
