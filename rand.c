#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 1000
/*
int main(){
	for(int i=0;i<=10;i++){
		printf("rand number %d\n",rand());
	}
	return 0;
}*/
int main(){
	int i=10;
	//x =max%(2- 8 * 3 + 9+ (45%2)+23*2048*104);
	int x=400000;
	while(i){
		printf("x = %d\n",x);
		x=x>>1;
		x=time(NULL);
		x=x<<2;
	i--;
	}
	return 0;
}
