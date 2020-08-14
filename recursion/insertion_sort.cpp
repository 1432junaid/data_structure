#include <iostream>
#define print(x) for(int i =0; i < x; i++)

using namespace std;

void insertion_sort(int *,int,int,int);

int main(){
	int a[] = {5,8,6,4};
	int len = sizeof(a)/sizeof(a[0]);

	print(len) cout << a[i] << " ";
	cout << endl;

	insertion_sort(a,len,0,len-1);

	print(len) cout << a[i] << " ";
	cout <<endl;
	return 0;

}

void insertion_sort(int a[],int len,int start,int end){
	if(start == end)return;

	int key = a[len-1];
	int i = len - 2;

	while(i >=0 && key < a[i]){
		a[i+1] = a[i];
		i--;
	}
	a[i+1] = key;

	insertion_sort(a,len,start+1,end);
}
