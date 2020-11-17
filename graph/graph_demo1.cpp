#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int);
vector<int> graph[6]; 	// y because graph used both where
bool visited[6];
int main(){
//	vector<int> graph[5];
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[1].push_back(5);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[2].push_back(4);
	graph[3].push_back(2);
	graph[3].push_back(4);
	graph[4].push_back(1);
	graph[4].push_back(2);
	graph[4].push_back(3);
	graph[5].push_back(1);
	dfs(2);
}

void dfs(int node){
	if(visited[node]) return;
	visited[node] = true;
	cout << node << " visited " << endl;
	for(auto u : graph[node]){
		dfs(u);
	}
}
