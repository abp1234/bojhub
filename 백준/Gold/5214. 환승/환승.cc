#include <iostream>
#include <vector>
#include<queue>
#include <unordered_set>
#include<tuple>
#include <limits>
#include <algorithm>
using namespace std;
const int INF = numeric_limits<int>::max();
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, M, temp0;
	cin >> N >> K >> M;
	vector<vector<int>>arr(N+M+1);
	for (int i = 1; i < M+1; i++) {

		for (int j = 0; j < K; j++) {
			cin >> temp0;
			
			arr[temp0 - 1].push_back(N+i);
			arr[N + i].push_back(temp0-1);
		}
		
	}
	int cost, now;
	vector<int>check(N+M+1,INF);
	check[0] = 1;
	priority_queue<tuple<int, int>>q_t;
	q_t.push(make_tuple(-1, 0));
	while (!q_t.empty()) {
		tie(cost,now) = q_t.top();
		q_t.pop();
		for (auto i : arr[now]) {
			if (check[i] > -cost+1) {
				if (i > N) {
					q_t.push(make_tuple( cost, i));
					check[i] = -cost;
				}
				else {
					q_t.push(make_tuple(-1 + cost, i));
					check[i] = -cost + 1;
				}
				
			}
		}
	}
	if (check[N - 1] == INF) {
		cout << -1;
		return 0;
	}
	cout << check[N - 1];
	return 0;
}