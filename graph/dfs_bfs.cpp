#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(int);
vector<pair<int,int>> graph[6];

int main(){
	graph[1].insert({5,1});	//connected node,weight
	graph[1].insert({4,9});
	graph[1].insert({2,5});
	graph[2].insert({1,5});
	graph[2].insert({3,2});
	graph[3].insert({5,1});
}
