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

int main(){
	int price[] = {1,2,5,8,9,10,17,20,24,30};
	int len ;
	cout << "Enter lenght of rod : ";
	cin >> len;

	cout << rod_cutting(len,price) << endl;
	return 0;
}
