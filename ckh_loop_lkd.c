#include<stdio.h>
#include<conio.h>

struct node{
        int data;
        struct node * next;
};

struct node * create_list();                            //prototype declaration
//int insert(struct node**,int, int);                     //prototype declarration
void traverse_list(struct node*);                       //prototype decleration
int count(struct node*);
int loop(struct node*,struct node*,int);
int chk_loop(struct node)

int main(int argc,char*arg[]){
        struct node *head= NULL;
        int option,n,c,data,p,position;


        while(1){
                printf("\n\t1.Create\n");
		printf("\t2.Traverse\n ");
		printf("\t3.count\n ");
		printf("\t4.do looop\n");
		printf("\t5.check loop ?\n");
		printf("\t10.exit\n\n");
                scanf("%d",&option);
                switch(option){
                        case 1:                         //for create node
                                head =create_list();
                        break;
			case 2:
				traverse_list(head);	//for traverse
			break;
			case 10:
				return 0;
		}



struct node * create_list(){                                            //create function
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


void traverse_list(struct node *p){                                     //traverse function
                while(p!=NULL){
                        printf("\t%d\t",p->data);
                        p = p->next;
                }
                printf("\n");
}


int count(struct node *start){                                          //count function
        struct node *p;
        int count = 0;
        p =start;
        while(p!=NULL){
                p=p->next;
                count++;
        }
        return count;
}

