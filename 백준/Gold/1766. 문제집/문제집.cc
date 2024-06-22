#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,M;
	cin >> N >> M;
	int A, B;
	vector<vector<int>> arr(N);
	vector<int>check(N);
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		arr[A - 1].push_back(B-1);
		check[B - 1] += 1;
	}
	priority_queue<int>q;
	for (int i = 0; i < N; i++) {
		if (check[i] == 0) {
			q.push(-i);
		}
	}
	while (!q.empty()) {
		int idx=q.top();
		q.pop();
		cout << -idx+1 << " ";
		for (int i = 0; i < arr[-idx].size(); i++) {
			check[arr[-idx][i]] -= 1;
			if (check[arr[-idx][i]] == 0) {
				q.push(-arr[-idx][i]);
			}
		}
	}

	return 0;
}