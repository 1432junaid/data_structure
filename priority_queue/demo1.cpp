#include <iostream>
#include <queue>

using namespace std;

int main(){
	priority_queue<int > pq;
	pq.push(10);
	pq.push(50);
	pq.push(30);
//	pq.push_front(40);
//	pq.push_back(11);
	while(!pq.empty()){
		int x = pq.top();
//		cout << x << endl;
		cout << pq.back()l;
		pq.pop();
	}

	return 0;
}
