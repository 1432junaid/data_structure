#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack.h"
int add(int x, int y){
	return x+y;
}

int sub(int x, int y){
	return x-y;
}

int mux(int x, int y){
	return x*y;
}

int div1(int x, int y){
	return x/y;
}
int mod(int x, int y){
	return x%y;
}

int main(int argc,int argv[]){
	char string[50]; int x=0;
	printf("Enter expresion\n");
	scanf("%s",string);
	struct sinfo *top1 = NULL, *top2 = NULL;
	int lenght = strlen(string);
	for(int i =0 ;i<lenght ; i++ ){
		push(top1,string[i]);
	}
	while((x = pop(top1)) != -1){
		if(x != '+' || x != '-' || x!='*' || x!='/' || x!='%'){
			push(top2,x);
		}else{
			int a = pop(top2);
			int b = pop(top2);
			switch(x){
				case '+':
					push(top2,add(a,b));
				break;
				case '-':
					push(top2,sub(a,b));
				break;
				case '*':
					push(top2,mux(a,b));
				break;
				case '/':
					push(top2,div1(a,b));
				break;
				case '%':
					push(top2,mod(a,b));
				break;
			}
		}
	}
	int result = pop(top2);
	printf("result = %d",result);
	return 0;

}

