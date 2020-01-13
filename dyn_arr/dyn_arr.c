#include<stdio.h>
#include<stdlib.h>
#include"dyn_arr.h"

int main(){
	int size,option,data,index,g;
	int *a;

	while(1){
		printf("Enter your choice\n\n");
		printf("1.create array\n");
		printf("2.add\n");
		printf("3.get\n");
		printf("5.exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter size of arrray\n");
				scanf("%d",&size);
				a = create_array(size);
			break;
			case 2:
				printf("Enter data\n\n");
				scanf("%d",&data);
				add(data,&a);
				//if(data == 1)printf("data is entered\n\n");
			break;
			case 3:
				printf("Enter the index of element \n");
				scanf("%d",&index);
				g = get(a,index);
				if(g == -1){
					printf("data not get\n");
				}else{
					printf("data is %d\n ",g);
				}
			break;
			case 5:
				printf("Exit \n\n");
				return 0;
		}
	}
	return 0;
}
