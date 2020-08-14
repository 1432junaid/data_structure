#include <iostream>

using namespace std;

unsigned long long  ways(int);
int main(){
	int x;
	cin>>x;
	cout <<"no of ways = " <<ways(x) << endl;
	return 0;
}

unsigned long long int ways(int n){
	if(n == 0)return 0;

//      int* mem = (int*)calloc(n+1,sizeof(int));
	static int flag = 1;
	static unsigned long long* mem;
	if(flag == 1){
		mem = (unsigned long long*)calloc(n+1,sizeof(unsigned long long));
		mem[1] = 1;
		mem[2] = 2;
		flag++;
	}

	if(mem[n] == 0){
		mem[n] = ways(n-1)+ways(n-2);
	}
	return mem[n];
}
