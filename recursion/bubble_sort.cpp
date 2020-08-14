#include <iostream>
#define print(x) for(int i =0;i<x;i++)std ::cout << a[i] << "  "

using namespace std;

void bubble_sort(int *, int,int ,int);
void swap(int *, int ,int);

int main(){
	int a[] = {2,8,5,3,9,4,1};
	int len = sizeof(a)/sizeof(a[0]);
	print(len);
	cout << endl;

	bubble_sort(a,len,0,len-1);

	cout << "After sort\n";
	print(len);
	cout << endl;
}

void bubble_sort(int a[],int len,int start,int end){
	if(start == end) return;

	for(int i =0 ; i < len-1; i++){
		if(a[i] > a[i+1])swap(a,i,i+1);
	}
	print(len);
	cout << endl;
	bubble_sort(a,len,start,end-1);
}

void swap(int a[],int x,int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
