#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int);
queue<int> q;			// Queue
bool visited[7];		//visited check
int dist[7];		//
vector<int> graph[7];	 	//Graph

int main(){
	graph[1].push_back(2);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[2].push_back(5);
	graph[3].push_back(2);
	graph[3].push_back(6);
	graph[4].push_back(1);
	graph[5].push_back(2);
	graph[5].push_back(6);
	graph[6].push_back(5);
	graph[6].push_back(3);
	bfs(1);
	cout << endl;
	return 0;

}

void bfs(int node){
	visited[node] = true;
	dist[node] = 0;
	q.push(node);
	while(!q.empty()){
		int s= q.front();
		q.pop();
		cout << s << "  ";
		for(auto a:graph[s]){
			if(visited[a])continue;
			visited[a] = true;
			dist[a] = dist[s]+1;
			q.push(a);
		}
	}
}


