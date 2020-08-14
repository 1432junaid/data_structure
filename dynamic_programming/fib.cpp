#include <iostream>

using namespace std;

unsigned int fib(unsigned int n){
	if(n==0)return -1;
	if(n==1 || n==2)return 1;
	return fib(n-2) + fib(n-1);
}

unsigned int fib_mem(unsigned int n){
//	unsigned int* mem = (unsigned int*)calloc(n+1,sizeof(unsigned int));
//	static int flag =1;
	static int mem[3]= {0};
//	static unsigned int* mem;
//	if(flag == 1){
//		mem = (unsigned int*)calloc(n+1,sizeof(unsigned int));
//		flag++;
//	}
	if(n==0)return 0;
	if(n==1 || n== 2)return 1;
//	mem[1] = 1;
//	mem[2] = 1;
//	if(mem[n] != 0) return mem[n];
	if(mem[n-1] == 0){
//		cout <<endl;
		mem[n-1] = fib_mem(n-1);
//		cout << endl;
	}
	if(mem[n-2] == 0){
//		cout << endl;
		mem[n-2] = fib_mem(n-2);
//		cout << endl;
	}
//	cout<<endl;
//	for(int i =0; i<= n+1; i++)cout <<i<<":"<< mem[i] <<"  " <<endl;
//	cout << endl;
	return mem[n-1]+mem[n-2];
}

int main(){
	unsigned int x;
	unsigned long int result;
	cout << "Enter element"<< endl;
	cin >> x;

	result = fib_mem(x);
	//result = fib(x);
	cout << "result :" << result << endl;;
	return 0;
}
