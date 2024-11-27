#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct N {
	int d, c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<N> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].d >> a[i].c;
	}

	sort(a.begin(), a.end(), [](const N& x, const N& y) {
		return x.d < y.d;
		});


	priority_queue<int, vector<int>, greater<int>>q;

	for (const auto& i : a) {
		q.push(i.c);
		if (i.d < (int)q.size()) {
			q.pop();
		}
	}

	int s = 0;
	while (!q.empty()) {
		s += q.top();
		q.pop();
	}

	cout << s << '\n';
	return 0;
}