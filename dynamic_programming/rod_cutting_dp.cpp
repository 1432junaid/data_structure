#include <iostream>
#include <climits>
using namespace std;

int rod_cutting(int len, int price[]){				//using recursion
	if(len == 0 ) return 0;
	int max = INT_MIN;
	for(int i = 1; i <= len; i++){
		int temp = price[i] + rod_cutting(len - i, price);
		if(temp > max) max = temp;
	}
	return max;
}

int get_max(int a,int b){					//get maximum of 2 numbers
	return (a>b)?a:b;
}

int cut_rod_memo(int n, int price[]){				//using memorization
	if(n <= 0 ) return 0;
	static int count = 0;
	static int * max_values;
	if(count == 0){
		max_values = (int*)calloc(n,sizeof(int));
		count ++;
	}
	max_values[n] = INT_MIN;
	for(int i =1; i<=n; i++){
		max_values[n] = get_max(max_values[n],price[i] + cut_rod_memo(n-i,price));
	}
	return max_values[n];
}

int cut_rod_dp(int value[],int n){
	if(n <= 0) return 0;
	static int count = 0;
	static int* max_val;
	if(count == 0){
		max_val = (int*)calloc(n+1,sizeof(int));
		count++;
	}
	for(int i =1; i <=n; i++){
		max_val[i] =  INT_MIN;
		for(int j =0; j < i; j++){
			max_val[i] = get_max(max_val[i], value[j+1]+max_val[i-j-1]);
		}
	}
	return max_val[n];
}


int main(){
	int price[] = {0,1,5,8,9,10,17,20,24,30};
	int len ;
	cout << "Enter lenght of rod : ";
	cin >> len;

//	cout << cut_rod_memo(len,price) << endl;
//	cout << rod_cutting(len,price) << endl;
	cout << cut_rod_dp(price,len);
	return 0;
}


