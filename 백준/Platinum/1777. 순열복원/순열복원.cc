#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct Seg {
	int* t;
	int sz;

	Seg(int n) {
		sz = n;
		t = new int[2 * (int)pow(2,ceil(log2(n))+1)];
		init(0, n - 1, 1);
	}

	~Seg() {
		delete[] t;
	}

	int init(int s, int e, int n) {
		if (s == e)return t[n] = 1;
		int m = (s + e) / 2;
		return t[n] = init(s, m, n * 2) + init(m + 1, e, n * 2 + 1);
	}

	int get_idx(int s, int e, int n, int v) {
		if (s == e)return s;
		int m = (s + e) / 2;
		if (v >= t[n * 2 ])
			return get_idx(m + 1, e, n * 2 + 1, v-t[n*2]);
		else
			return get_idx(s, m, n * 2, v );
	}

	void upd(int s, int e, int n, int idx) {
		if (idx<s || idx>e)return;
		t[n]--;
		if (s == e)return;
		int m = (s + e) / 2;
		upd(s, m, n * 2, idx);
		upd(m + 1, e, n * 2 + 1, idx);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> inv(n + 1), org(n);
	for (int i = 1; i <= n; i++)cin >> inv[i];

	Seg seg(n);
	for (int i = n; i > 0; i--) {
		int idx = seg.get_idx(0, n - 1, 1, inv[i]);
		org[idx] = i;
		seg.upd(0, n - 1, 1, idx);
	}
	for (int i = n-1; i >-1; i--)cout << org[i] << " ";
	cout << '\n';
	return 0;
}