#include <iostream>

using namespace std;

int find_power(int base , int power){
	if(base >=0 && power == 0)return 1;
	if(base < 0 && power == 0)return -1;
	return base *  find_power(base,power-1);
}

int main(){
	int base,expo;		//base and exponent
	cout << "Enter base and power" << endl; 
	cin >> base >>expo;
	cout << find_power(base,expo);
	cout << endl;
	return 0;
}
