

#include<stdlib.h>


static int len;
static int current_index;
int *create_array(int size){
	len = size;
	return (int*)calloc(sizeof(int),size);
}

int add(int data,int **a){
	if(current_index < len){
		*(*a+(current_index++)) = data;		//*a[current_index++] = data;
	}else{
		int *temp = (int*)calloc(sizeof(int),2*len);
		for(int i = 0; i < current_index; i++){
			temp[i] = *(*a + i);			//temp[i] = *a[i];
		}
		free(*a);
		temp[current_index++] = data;
		len =2*len;
		*a = temp;
	}
	return 1;
}

int get(int *a,int index){
	if(index <= (current_index -1)){
		return a[index];
	}
	return -1;
}

