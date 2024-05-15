#include <iostream>
#include <queue>
#include<tuple>
#include <vector>
#include<limits>
using namespace std;
const long long INF = numeric_limits<long long>::max();

int main(void) {
	int N, K, result;
	int cost, now;
	cin >> N >> K;
	priority_queue<tuple<long long,long long>>q;
	vector<long long>check(3*max(N,K) + 1, INF);
	q.push(make_tuple(0, N));
	while (!q.empty()){
		tie(cost,now) = q.top();
		q.pop();
		if (now >= 3 * max(N, K) + 1 || now < 0) continue;
		if (check[now] <= -cost)continue;
		check[now] = -cost;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				q.push(make_tuple(cost - 1, now+1));
			}
			else if (i == 1) {
				q.push(make_tuple(cost - 1, now - 1));
			}
			else {
				q.push(make_tuple(cost , now*2));
			}
		}
	}
	cout << check[K];
	return 0;
}