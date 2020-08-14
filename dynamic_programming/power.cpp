#include <iostream>

using namespace std;

unsigned int pow(int base, int exp){
	if(exp == 0)return 1;
	if(base == 0)return 0;
}
int main(){
	unsigned int x,y,result;
	cout << "base = ";
	cin >> x;
	cout << "power = ";
	cin >> y;

	cout << pow(x,y);
}
