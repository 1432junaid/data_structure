#include <iostream>
#define print(x) for(int i=0; i < x; i++)

using namespace std;

void selection_sort(int*,int,int,int );

int main(){
	int a[] = {3,9,4,12,1,6,8,};
	int len = sizeof(a)/sizeof(a[0]);
	int start = 0;
	int end = len-1;

	print(len) cout << a[i] <<"  ";
	cout << endl;

	selection_sort(a,len,start,end);

	print(len) cout << a[i] <<"  ";
	cout << endl;
	return 0;
}

void selection_sort(int a[],int len,int start,int end){
	if(start == end)return ;

	for(int i = start+1; i < len; i++){
		if(a[i]  <= a[start] ){
			int temp = a[start];
			a[start] = a[i];
			a[i] = temp;
		}
	}

	selection_sort(a,len,start+1,end);
}
