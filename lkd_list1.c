#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * create_list();				//prototype declaration
int insert(struct node**,int, int);			//prototype declarration
void traverse_list(struct node*);			//prototype decleration



int main(int argc,char*arg[]){
	struct node *head= NULL;
	int option,data,position;


	while(1){
		printf("\n\t1.Create\n\t2.Traverse\n \t3.insert node in exisiting linked list\n \t4.count\n \t5.delete\n \t6.searching\n \t10.exit\n\n");
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
				printf("number of nodes are\n");
				int c = count(&head);
				printf("\nnumber of nodes=%d\n",c);
			break;
			case 5:
				int j = delete(&head,position);
				if(j==1){
					printf("can be delete");
				}else{
					printf("can not delete");
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

int delete(struct node **hpointer,int position){			//delete function
	if(*hpointer == NULL && position == 1){
		return 0;
	}
	int count=0;p=*hpointer;
	while(p != NULL && count != position-1){
		count++;
		p = p->next;
	}
	if(*hpointer != NULL && position > count ){
		return 0;
	}
	if(*hpointer !== NULL && position == -1){
		p = *hpointer;
		q = *hpointer;
		while(q->next != NULL){
			p=q;
			q=q->next;
		}
		free(q);
	}
	if(*hpointer !=NULL && position == 1){
		head = head->next;
		free(p);
	}
}
