
#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node * next;
};

struct node * create_list();                            //prototype declaration
void traverse_list(struct node*);                       //prototype decleration
int count(struct node*);
void loop(struct node*);
int chk_loop(struct node*);

int main(){
        struct node *head= NULL;
        int option,n,c,data,p,position,chk;


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
			case 3:
                                p = count(head);
                                printf("\nnumber of nodes=%d\n",p);
                        break;
			case 4:
				loop(head);
			break;
			case 5:
				chk = chk_loop(head);
				if(chk == 1){
					printf("loop found\n");
				}else{
					printf("loop not found\n");
				}
			break;
			case 10:
				return 0;
		}
	}
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

void loop(struct node *h){
//	if(h == NULL)return 0;
	struct node *p,*q;
		q=h;
		p=h;
		p=p->next;
//	for(int i=0;i<10;i++){
		while(q->next !=NULL){
			q=q->next;
			traverse_list(q);
		}
		q->next = p;
//		traverse_list(h);
//	}
}

int chk_loop(struct node *head){
	struct node *p,*q;
	if(head == NULL)return 0;
	if(head->next == NULL)return 0;
	p=head;
	q=head;
	while((p->next !=NULL && q->next->next != NULL) && q->next != NULL && q!=NULL){
		p=p->next;
	//	if(p->next != NULL){
	//		q = p->next;
	//	}else{
	//			return 0;
	//	}
		q = q->next->next;
		if(p == q)return 1;
	}
	return 0;
}
