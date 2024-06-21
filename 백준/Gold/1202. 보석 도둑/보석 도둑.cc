#include <iostream>
#include <vector>
#include <queue>
#include<tuple>
#include <algorithm>
#include <set>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	int M, V, C;
	priority_queue<tuple<int, int>>q;
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		q.push(make_tuple(V,M));
	}
	multiset<int>arr;
	for (int j = 0; j < K; j++) {
		cin >> C;
		arr.insert(C);
	}
	long long result = 0;

	while (!arr.empty() && !q.empty()) {
		tie(V, M) = q.top();
		q.pop();
		auto idx = arr.lower_bound(M);
		if (idx !=arr.end()) {
			arr.erase(idx);
			result += V;
		}
	}
	cout << result;
	return 0;
}