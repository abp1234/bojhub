#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct SegTree {
	vector<long long> t;
	int sz;
	
	SegTree(int n) {
		sz = 1 << ((int)ceil(log2(n))+1);
		t.resize(sz ,0);
	}

	void up(int n, int s, int e, int p, long long q) {
		if (s <= p && p <= e) {
			t[n] += q;
			if (s != e) {
				int m = (s + e) / 2;
				up(n * 2, s, m, p, q);
				up(n * 2 + 1, m + 1, e, p, q);
			}
		}
	}

	long long clc(int n, int s, int e, int p, int q) {
		if (q < s || e < p)return 0;
		if (p <= s && e <= q) return t[n];
		int m = (s + e) / 2;
		return clc(n * 2, s, m, p, q) + clc(n * 2 + 1, m + 1, e, p, q);
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL);
	int n, l;
	cin >> n >> l;

	SegTree st(n);

	for (int i = 0; i < l; i++) {
		int cmd, p;
		long long q;
		cin >> cmd >> p >> q;
		p--;
		if (cmd == 1) {
			st.up(1, 0, n - 1, p, q);
		}
		else {
			q--;
			cout << st.clc(1, 0, n - 1, p, q) << '\n';
		}
	}
	return 0;
}
