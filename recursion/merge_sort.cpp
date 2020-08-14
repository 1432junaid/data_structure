#include <iostream>
#define print(x) for(int i=0; i<x;i++)std::cout <<arr[i] << "  "		//prints the 1D array

using namespace std;

int partition(int *,int, int , int);

void merge_sort(int arr[],int left,int right){

	if(left >= right)return;

	int pivot = arr[(left+right)/2];			//select one element from the array to let the pivot element

	int index = partition(arr,left,right,pivot);		//this will get the index of the partitioning position
	merge_sort(arr,left,index-1);
	merge_sort(arr,index,right);
}

int partition(int arr[],int left,int right,int pivot){

	while(left <= right){
		while(arr[left]  < pivot)  left++;
		while(arr[right] > pivot) right--;
		if(left <= right){
		        int temp   = arr[left];
			arr[left]  = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
	return left;
}


int main(){
	int arr[] = {15,3,9,8,5,2,7,1,6};
	int len = sizeof(arr)/sizeof(arr[0]);

	print(len);
	cout << endl;

	merge_sort(arr,0,len-1);		//merge_sort(array,start,end)

	print(len);
	cout << endl;

	return 0;
}
