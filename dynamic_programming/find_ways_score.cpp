#include <iostream>

using namespace std;

unsigned long long  ways(int);
int score(int);
int main(){
	int x;
	cin>>x;
	cout << "ways : " << score(x) << endl;
//	cout <<"no of ways = " <<ways(x) << endl;
	return 0;
}

unsigned long long int ways(int n){
	if(n == 0)return 0;

//      int* mem = (int*)calloc(n+1,sizeof(int));
	static int flag = 1;
	static unsigned long long* mem;
	if(flag == 1){
		mem = (unsigned long long*)calloc(n+1,sizeof(unsigned long long));
		mem[3] = 3;
		mem[5] = 5;
		mem[10] = 10;
		flag++;
	}

	if(mem[n] == 0){
		mem[n] = ways(n-3)+ways(n-5)+ways(n-10);
	}
	return mem[n];
}

int score(int n){

	if(n == 3)return 1;
	if(n == 5)return 1;
	if(n == 10)return 2;

	return score(n-3)+score(n-5)+score(n-10);
}
