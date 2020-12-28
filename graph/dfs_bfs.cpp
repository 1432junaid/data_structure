#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

void dfs(int);
void bfs(int);

vector<pair<int,int>> graph[6];
queue<int> q;
bool visited[6];
int dist[6];

int main(){
	graph[1].push_back({2,5});	//node,weight
	graph[1].push_back({4,9});
	graph[1].push_back({5,1});

	graph[2].push_back({1,5});
	graph[2].push_back({3,2});

	graph[3].push_back({2,2});
	graph[3].push_back({4,7});

	graph[4].push_back({3,7});
	graph[4].push_back({1,9});
	graph[4].push_back({5,2});

	graph[5].push_back({4,2});
	graph[5].push_back({1,1});
	cout << "1 : dfs"<<endl<< "2 : bfs"<< endl;
	int choose;
	cout << "Enter choice"<< endl;
	cin >> choose;
	if(choose ==1)dfs(1);
	else 	bfs(1);
	return 0;
}

void dfs(int node){
	if(visited[node]) return;
	visited[node] = true;
	cout << node << "  visited " << endl;
	for(auto itr : graph[node]) dfs(itr.first);
}

void bfs(int node){
	visited[node] = true;
	dist[node] = 0;
	q.push(node);
	while(!q.empty()){
		int s = q.front();
                q.pop();
                cout << s << "  visited " << endl;
                for(auto itr : graph[s]){
                        if(visited[itr.first])continue;
                        visited[itr.first] = true;
                        dist[itr.first] = dist[s]+1;
                        q.push(itr.first);
                }
        }
}


