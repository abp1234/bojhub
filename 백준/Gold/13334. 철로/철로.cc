#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Loc {
	int s, e;
	bool operator<(const Loc& l)const {
		return e < l.e || (e == l.e && s < l.s);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, d;
	cin >> n;

	vector<Loc> loc(n);
	for (int i = 0; i < n; ++i) {
		int h, o;
		cin >> h >> o;
		loc[i] = { min(h,o),max(h,o) };
	}
	cin >> d;

	sort(loc.begin(), loc.end());

	priority_queue<int, vector<int>, greater<>>pq;
	int mx = 0;

	for (auto& l : loc) {
		pq.push(l.s);
		while (!pq.empty() && pq.top() < l.e - d) {
			pq.pop();
		}
		mx = max(mx, (int)pq.size());
	}

	cout << mx << '\n';
	return 0;
}