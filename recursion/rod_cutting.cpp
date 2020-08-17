#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int rod_cutting(vector<int>,int);
int get_max(int,int);

int main(){
	vector<int> price = {0,1,5,8,9,10};
	int len = price.size()-2;
	int result = rod_cutting(price,len);
	cout << result << endl;
	return 0;
}

int get_max(int x,int y){
	return (x > y)?x:y;
}

int rod_cutting(vector<int> price,int len){
	if(len <= 0)return 0;
	int max = INT_MAX;
	for(int i = 1;i <= len; i++){
		cout << i <<" : " << price[i] << endl;
		max = (price[i] + rod_cutting(price,len - i));
	}
	return max;
}
