#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info{				//difineing data structure to store for memorization
	int left;			//left index of divided piont
	int right;			//right index that is dividing point Ex: 0,1 [l=0,r=1]
	int result;			//that store max lenght
	int flag;			//true when sum of left == sum of right
};

vector<info> memo(8);			//for memorization

void fun(vector<int>);			//
int sum(vector<int>, int,int);


int main(){
//	vector<int> arr = {9,4,3,0,7,2,3};
//	vector<int> arr = {1,4,2,1,2,4};
	vector<int> arr = {4,1,2,3,1,0,5,4};
//	vector<int> arr = {4,1,2,3,0,0,6,4};		//check the output coz incorrect answer
	cout << arr.size() << endl;
	fun(arr);

	for(int i =0; i< memo.size(); i++){
		cout << memo[i].left 	<< "  ";
		cout << memo[i].right 	<< "  ";
		cout << memo[i].result  << "  ";
		cout << memo[i].flag    << "  " << endl;
	}
	cout << endl;

	vector<int> ans(8);

	int max = 0;

	for(int i = 0; i < arr.size(); i++){
		if(memo[i].result >= max)max = memo[i].result;		//getting the max value
	}

	cout << "answer : " << max << endl;

	return 0;
}

void fun(vector<int>arr){
	for(int i=1;i<arr.size();i++){
		sum(arr,i-1,i);
	}
}

int sum(vector<int>a,int left,int right){
	int bPoint = right/2;		//bPoint is break-point

	if(left < 0 || right >= a.size() )return 0;

	int sum1 = 0;
	int sum2 = 0;
	int l = left;
	int r = left+1;
	while(l >= 0){
		sum1 += a[l];
		sum2 += a[r];

		if(sum1 == sum2){
			memo[right].flag  = 1;
			memo[right].left  = l;
			memo[right].right = r;
			memo[right].result = (r - l) + 1;
			sum(a,left-1,right+1);
		}
		l--;
		r++;
	}
}


