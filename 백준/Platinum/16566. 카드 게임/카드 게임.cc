#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct UF {
	vector<int> p;

	UF(int n) {
		p.resize(n);
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int f(int x) {
		if (x != p[x]) {
			p[x] = f(p[x]);
		}
		return p[x]; 
	}

	void u(int x, int y, int m) {
		if (y >= m)return;
		x = f(x);
		y = f(y);
		p[x] = y;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> c(m);
	vector<int> ch(k);

	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < k; i++) {
		cin >> ch[i];
	}

	sort(c.begin(), c.end());

	UF uf(m);

	for (int i = 0; i < k; i++) {
		int t = ch[i];

		int idx = upper_bound(c.begin(), c.end(), t) - c.begin();

		idx = uf.f(idx);

		cout << c[idx] << '\n';

		uf.u(idx, idx + 1, m);
	}

	return 0;
}