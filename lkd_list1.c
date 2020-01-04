#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * create_list();
void traverse_list(struct node*);

int main(int argc,char*arg[]){
	struct node *head= NULL;
	int option;
	while(1){
		printf("\n\t1.Create\n\t2.Traverse\n\t10.exit\n\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				head =create_list();
			break;

			case 2:
				traverse_list(head);
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

struct node * create_list(){
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

void traverse_list(struct node *p){
		while(p!=NULL){
			printf("\n%d\t",p->data);
			p = p->next;
		}
		printf("\n");
}





