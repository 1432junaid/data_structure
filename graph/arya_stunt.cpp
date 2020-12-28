#include <iostream>
#include <vector>

using namespace std;

vector<int> selected_node;

int main(){
	int no_node,no_connection;			//nodes,connection
	cin>>no_node>>no_connection;
	vector<int> no_solder(no_node+1,0);		//array of men's

	for(int i = 1; i<no_node+1; i++){
		cin >> no_solder[i];
	}

	// vector<pair<int,int>>  graph[no_nodes+1];
	vector<int> graph[no_node+1];
	while(no_connection){				//inserting conntion
		int a,b;
		cin>> a>> b;
		graph[a].push_back(b);
		no_connection--;
	}
}
