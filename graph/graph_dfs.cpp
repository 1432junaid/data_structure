#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[6]		//excluding 0
bool visited[6]			//for track who is visited

void dfs(int);			//passing node

int main(){
	graph[1].push_back(4);
	graph[1].push_back(2);
	graph[2].push_back(5);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(5);
	graph[3].push_back(2);
	graph[4].push_back(1);
	graph[5].push_back(2);
	graph[5].push_back(3);

	dfs(1);
	return 0;
}

void dfs(int node){
	if(visited[node]) return;
	visited[node] = true;
	for(auto a: graph[node]){
		dfs(a);
	}
}





