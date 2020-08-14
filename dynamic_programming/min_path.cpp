#include <iostream>
#include <vector>
#define M 3
#define N 4

using namespace std;

int min(int a, int b){
	return (a<b)?a:b ;
}

int minCost(int cost [M][N]);

int main(){
	int cost[M][N];
	cout << "Enter elements ";
	for(int i =0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> cost[i][j];
		}
	}
	int result = minCost(cost);
	cout << "Minimum cost is " << result << endl;
	return 0;
}

int minCost(int cost[M][N]){
	static int mcost[M][N];
	for(int  i = 1; i < N; i++){
		mcost[0][i] = cost[0][i] + cost[0][i-1];
	}
	for(int i =1; i < M; i++){
		mcost[i][0] = cost[i][0] + cost[i-1][0];
	}

	for(int i =1; i < M; i++){
		for(int j= 1; j< N; j++){
			if(mcost[i][j] == 0){
				mcost[i][j] = cost[i][j]+ min(mcost[i-1][j],mcost[i][j-1]);
			}
		}
	}
	return mcost[M-1][N-1];
}
