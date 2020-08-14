#include <iostream>
#include <climits>
#include <vector>

using namespace std;


vector< vector<int>> cost = {   {0, 10,75,94},
                                {-1, 0,35,50},
                                {-1,-1, 0,80},
                                {-1,-1,-1, 0} };

vector<vector<int>> memo (cost.size() , vector<int>(cost[0].size(),0) );

void printer(vector<vector <int>>);
int min_cost(int, int);

int main(){
	int source , destination ;
	cout << "Enter source and destination:" << endl;
	cin >> source >> destination;
	if(destination < source )cout << "can't move revese" << endl;
	printer(cost);
	cout << "Minimum cost :" << endl;
	cout << min_cost(source , destination) << endl;
	printer(memo);
//	cout << INT_MAX << endl;
	return 0;

}

int min_cost(int s, int d){
	if(s == d || s == d-1) return cost[s][d];
	int min;
	if(memo[s][d] == 0){
		min = cost[s][d];
		memo[s][d] = min;
		for(int i = s+1; i<d; i++){
			int temp = min_cost(s, i) + min_cost(i, d);
			if(temp < min)min = temp;
		}
	}
	return min;
}

void printer(vector<vector<int>> matrix){
	for(int i =0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[0].size(); j++){
			cout << matrix[i][j] << " ";
		}cout << endl;
	}
	cout << endl;
}
