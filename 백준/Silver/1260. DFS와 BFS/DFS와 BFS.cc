#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;
int dfs(int num,vector<vector<int>>& arr, vector<int>& visited) {
	cout << num + 1 << " ";
	visited[num] = 1;
	for (auto i : arr[num]) {
		if (visited[i] == 1)continue;
		
		dfs(i,arr,visited);
	}
	return 0;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, V, temp0, temp1;
	cin >> N >> M >> V;
	vector<vector<int>>arr(N);
	for (int i = 0; i < M; i++) {
		cin >> temp0 >> temp1;
		arr[temp0 - 1].push_back(temp1-1);
		arr[temp1 - 1].push_back(temp0-1);
	}
	for (int i = 0; i < N; i++) {
		sort(arr[i].begin(),arr[i].end());
	}
	vector<int>visited(N,0);
	dfs(V - 1,arr,visited);
	cout << '\n';
	cout << V << " ";
	visited.assign(N,0);
	queue<int>q;
	q.push(V - 1);
	visited[V - 1] = 1;
	int num=0;
	while (!q.empty()) {
		num=q.front();
		q.pop();
		for (auto i : arr[num]) {
			if (visited[i] == 0) {
				visited[i] = 1;
				cout << i + 1 << " ";
				q.push(i);
			}
		}
	}

	return 0;
}