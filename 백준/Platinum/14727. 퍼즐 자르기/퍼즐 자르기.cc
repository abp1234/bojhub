#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

static const int MX = 1000000;
static int ar[MX + 1];
static struct nd {
	int i;
} st[4*MX];

int n;

int in(int s, int e, int u) {
	if (s == e) {
		st[u].i = s;
		return s;
	}

	int m = (s + e) >> 1;
	int li = in(s, m, u << 1);
	int ri = in(m + 1, e, (u << 1) + 1);

	if (ar[li] <= ar[ri]) {
		st[u].i = li;
		return li;
	}
	else {
		st[u].i = ri;
		return ri;
	}
}


int mi(int s, int e, int u, int L, int R) {
	if (e < L || R < s)return -1;
	if (L <= s && e <= R)return st[u].i;

	int m = (s + e) >> 1;
	int li = mi(s, m, u << 1, L, R);
	int ri = mi(m + 1, e, (u << 1) + 1, L, R);

	if (li == -1)return ri;
	if (ri == -1)return li;

	return (ar[li] <= ar[ri]) ? li : ri;
}

long long gm(int L, int R) {
	int idx = mi(1, n, 1, L, R);
	long long sp = (long long)(R - L + 1) * (long long)ar[idx];

	if (L < idx) {
		long long lv = gm(L, idx - 1);
		if (lv > sp)sp = lv;
	}

	if (idx < R) {
		long long rv = gm(idx + 1, R);
		if (rv > sp)sp = rv;
	}
	return sp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> ar[i];

	in(1, n, 1);

	cout << gm(1, n) << "\n";
	return 0;
}