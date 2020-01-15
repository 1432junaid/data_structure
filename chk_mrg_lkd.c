#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node * next;
};

struct node * create_list();                            //prototype declaration
void mrg(struct node*, struct node*,int);
int count(struct node*);
int chk_mrg(struct node*,struct node*);
void traverse_list(struct node*);


int main(int argc,char*arg[]){
        struct node *head1 = NULL, *head2 = NULL;
	int option,p,p1,chk;
	while(1){
		printf("\n\t1.Create\n");
		printf("\t2.merge list\n");
		printf("\t3.count\n");
		printf("\t4.check merge\n");
		printf("\t5.traverse\n");
		printf("\t6.exit\n\n");
               	scanf("%d",&option);
               	switch(option){
			case 1:                         //for create node
				head1 = create_list();
				printf("\ncreating second list\n");
				head2 = create_list();
                        break;
			case 2:
				mrg(head1,head2,3);
			break;
			case 3:                        //for count number of nodes
				p = count(head1);
                                printf("\nnumber of nodes in head1=%d\n",p);
				p1 = count(head2);
				printf("\nnumber of nodes in head2=%d\n",p1);
                        break;
			case 4:
				chk = chk_mrg(head1,head2);
				if(chk == 1){
					printf("list merged\n");
				}else{
					printf("list not merget \n");
				}
			break;
			case 5:
				printf("head 1\n");
				traverse_list(head1);
				printf("head 2\n");
				traverse_list(head2);
			break;
			case 6:
				printf("bye bye!\n");
				return 0;
		}
	}
	return 0;
}





struct node * create_list(){                                            //create function
        int number;
        struct node *head=NULL,*temp =NULL,*p;
        printf("\nEnter number of nodes to be created\t=");
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



void mrg(struct node *h1,struct node *h2,int count){                                          //count function
	for(int i = 1; i<count;i++){
		h1 = h1->next;
	}
	while(h2->next != NULL)h2 = h2->next;
	h2 ->next = h1;
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

/*
int chk_mrg(struct node *h1,struct node *h2){
	if(h1 == NULL && h2 == NULL)return 0;		//empty list
	struct node *p,*q;
		p=h1;
		q=h2;
	for(int i =0;p == NULL;i++){
		for(int j = 0; q == NULL; j++){
			if(h1 == h2)return 1;
			h2 = h2->next;
		}
		h1 = h1->next;
	}
}
*/
int chk_mrg(struct node *h1,struct node *h2){
	struct node *p,*q;
		p=h1;
		q=h2;
	while(p != NULL){
		q=h2;
		while(q!=NULL){
			if(p == q) return 1;
			q=q->next;
		}
		p=p->next;
	}
	return 0;
}

void traverse_list(struct node *p){                                     //traverse function
                while(p!=NULL){
                        printf("\t%d\t",p->data);
                        p = p->next;
                }
                printf("\n");
}

