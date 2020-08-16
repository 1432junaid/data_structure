#include <iostream>
#include <climits>
using namespace std;

int rod_cutting(int len, int price[]){
	if(len == 0 ) return 0;
	int max = INT_MIN;
	for(int i = 1; i <= len; i++){
		int temp = price[i] + rod_cutting(len - i, price);
		if(temp > max) max = temp;
	}
	return max;
}

int get_max(int a,int b){
	return (a>b)?a:b;
}

int cut_rod_memo(int len, int price[]){
	if(n <= 0 ) return 0;
	static int count = 0;
	static int * max_values;
	if(count == 0){
		max_values = (int*)calloc(n,sizeof(int));
		count ++;
	}
	max_values[] = INT_MIN
	for(int i =1; i<=n; i++){
		max_values[n] = get_max(max_values[n],price[i] + cut_rod_memo(value,n-i));
	}
	return max_values[n];
}

int main(){
	int price[] = {0,1,5,8,9,10,17,20,24,30};
	int len ;
	cout << "Enter lenght of rod : ";
	cin >> len;

	cout << cut_rod_memo(len,price) << endl;
//	cout << rod_cutting(len,price) << endl;
	return 0;
}


