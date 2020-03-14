#include<stdio.h>
#include"stackchar.h"
int main(int argc, char *argv[])
{
	struct sinfo *s1=createStack(9);
        struct sinfo *s2=createStack(9);
	char a[]="+-+abc*de";
	int i=-1;
	while(a[++i] !='\0')
	{
		printf("%c",a[i]);
		push(s1,&a[i]);	
	}
	printf("\n");
	printst(s1);
	while(s1->top != -1)
	{
	char a=(char)pop(s1);
	printf("%c\n",a);
	if(a!= '+' && a!='-' && a!= '*')
	{
	//	printf("Here !\n");
		push(s2,&a);
	}
	/*else
	{
		while(s2->top != -1)
        	{
                printf("\t\t%c",s2->stackp[s2->top]);
                s2->top--;
        	}
		//pop(s2);
		//pop(s1);
		//s2->top--;
	}*/ 
	}
	printf("\n");
	while(s2->top != -1)
        {
                printf("%c\n",s2->stackp[s2->top]);
                s2->top--;
        } 
	
	return 0;
	
}
