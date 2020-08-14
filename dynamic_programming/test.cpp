#include <iostream>
#include <vector>

using namespace std;

struct info{
	int flag;
	int left;
	int right;
	int value;
};

void printer(info);

int main(){
	vector<info> vec(10);
	cout <<" flag " <<" left" << " right" << "   value " << endl;
	for(int i= 0; i < vec.size();i++){
		cout << vec[i].flag  <<"  ";
		cout << vec[i].left  <<"  ";
		cout << vec[i].right <<"  ";
		cout << vec[i].value <<"  " << endl;

	}
	cout << endl;
//	printer(data);
	return 0;

}

void printer(info data){
	cout << "flag : "<<data.flag  << endl;
	cout << "left : "<<data.left  << endl;
	cout << "right: "<<data.right << endl;
	cout << "value: "<<data.value << endl;
}

