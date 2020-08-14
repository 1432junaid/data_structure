#include <iostream>
#define print(x) for(int i=0;i < x; i++)

using namespace std;

void quick_sort(int *,int,int);
int  partition(int *,int,int,int);
void swap(int *,int,int);

int main(){

	int a[] = {15,3,2,1,9,5,7,8,6};
	int len = sizeof(a)/sizeof(a[0]);

	print(len) cout << a[i] << "  ";
	cout << endl;

	quick_sort(a,0,len-1);

	print(len) cout << a[i] << "  ";
	cout << endl;
	return 0;
}

void quick_sort(int a[],int left,int right){
	if(left >= right) return;

	int pivot = a[(left+right)/2];
	int index = partition(a,left,right,pivot);
	quick_sort(a,left,index-1);
	quick_sort(a,index,right);
}

int partition(int a[],int left,int right,int pivot){
	while(left <= right){
		while(a[left] < pivot){
			left++;
		}

		while(a[right] > pivot){
			right--;
		}

		if(left <= right){
			swap(a,left,right);
			left++;
			right--;
		}
	}
	return left;
}

void swap(int arr[],int left,int right){
	int temp = left;
	arr[left] = arr[right];
	arr[right] = temp;
}
