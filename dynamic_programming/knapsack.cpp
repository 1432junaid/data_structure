#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int knapsack(vector<int>,vector<int>,int);
void printer(vector<vector<int>>);
int main(){
	vector<int> P = {0,1,2,5,6};
	vector<int> W = {0,2,3,4,5};
	int capacity ;
	cout << "Enter capacity of bag = ";
	cin >> capacity;
//	printer(matrix);
	knapsack(P,W,capacity);
	return 0;
}

int knapsack(vector<int> price, vector<int> weight, int capacity){
	int len = price.size();
	vector<vector<int>> matrix(len ,vector<int>(capacity+1 ,0));
	for(int i =1; i <= len; i++){
		for(int w = 1; w <= capacity; w++){
			if(weight[i] <= w){
				matrix[i][w] = max(price[i] + matrix[i-1][w-weight[i]] , matrix[i-1][w]);
			}else{
				matrix[i][w] = matrix[i-1][w];
			}
		}
	}
//	printer(matrix);
	return matrix[len][len];
}

void printer(vector< vector<int>> matrix){
	for(int i =0; i< matrix.size(); i++){
		for(int j =0; j< matrix[i].size(); j++){
			cout << matrix[i][j] << "  ";
		}cout << endl;
	}
	cout << endl;
}

int max(int x, int y){
	return (x>y)?x:y;
}
