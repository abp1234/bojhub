#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <unordered_map>

using namespace std;

const int INF = numeric_limits<int>::max();
struct E {
	int n, d, c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, n, r;
	cin >> k >> n >> r;

	unordered_map<int, vector<E>>ed;
	for (int i = 0; i < r; ++i) {
		int s, d, l, t;
		cin >> s >> d >> l >> t;
		ed[s - 1].push_back({ d - 1,l,t });
	}

	vector<vector<int>> dp(n, vector<int>(k + 1, INF));
	dp[0][k] = 0;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>pq;
	pq.push(make_tuple( 0,k,0 ));

	int ans = INF;

	while (!pq.empty()) {
		int dist, cost, node;
        tie(dist, cost, node) = pq.top();
        pq.pop();

        if (node == n - 1) {
            ans = min(ans, dist);
            break;
        }

        for (const auto& e : ed[node]) {
            if (cost - e.c >= 0 && dp[e.n][cost - e.c] > dist + e.d) {
                dp[e.n][cost - e.c] = dist + e.d;
                pq.push(make_tuple(dist + e.d, cost - e.c, e.n));
            }
        }
    }

	cout << (ans < INF ? ans : -1) << '\n';
	return 0;
}