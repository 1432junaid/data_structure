#include <iostream>
#define MAX 100
using namespace std;

int factorials[MAX] = {0};

int  factorial(int n){
	factorials[0] = 1;
	factorials[1] = 1;
	if(factorials[n] == 0){
		factorials[n] = n * factorial(n-1);
	}
}

int main(){
	int range,y;
	cout << "Enter the range of factorial\n";
	cin >> range;
	factorial(range);

	cout << "you want to search the factorial of ";
	cin >> y;
	if(y > range){
		cout << "out of range !!\n";
	}else cout << factorials[y] << endl;

	for(int i =1; i< range; i++)cout << factorials[i] << endl;
	cout << endl;
	return 0;
}
