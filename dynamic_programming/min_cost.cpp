#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int>>cost = { 	{0,10,75,94},
				{-1,0,35,50},
				{-1,-1,0,80},
				{-1,-1,-1,0} };
vector<int> memo;

int min_cost(int,int);
int minCost(int ,int);

int main(){
	int source,destination;
	cout << "Enter source and destionation :";
	cin  >> source >> destination;

	if(destination < source){
		cout << "\ncant move is reverse direction\n";
		return 0;
	}

	cout << "Min cost =" << min_cost(source,destination) << endl;
//	sort(memo.begin(),memo.end());
	for(int i =0; i< memo.size(); i++){
		cout << memo[i] << "  ";
	}

//	cout  <<endl << "min cost = "<< memo[0];
//	cout << endl;

//	cout << minCost(source,destination) << endl;
	return 0;

}

int min_cost(int src,int dst){
	if(src == dst || src == dst-1)return cost[src][dst];

	int min = cost[src][dst];
	memo.push_back(min);
	for(int i = src+1; i < dst; i++){
		if(memo[i] == 0){
		int temp =  min_cost(src,src+i) + min_cost(src+i, dst);
		memo.push_back(temp);
		}
	}

}

int minCost(int s,int d){
	if(s == d || s == d-1)return cost[s][d];
	int min =  cost[s][d];
	for(int i = s+1; i <d; i++){
		int temp =  minCost(s,s+1) + minCost(s+1,d);
		if(temp < min) min = temp;
	}
	return min;
}

