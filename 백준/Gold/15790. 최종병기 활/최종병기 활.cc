#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Slot
{
	vector<int> s; int n, m, k;
};

bool chk(const vector<int>& s, int len, int n, int m, int k) {
	for (int i = 0; i < m; ++i) {
		int sv = s[i];
		int cnt = 1;
		int cur = (i + 1 == m) ? 0 : i + 1;
		int left = n;
		while (true) {
			if (cnt == k) {
				if (left >= len) {
					return true;
				}
				break;
			}
			if (cur == i) {
				break;
			}
			int v = (sv < s[cur]) ? (s[cur] - sv) : (n + s[cur] - sv);
			if (v >= len) {
				sv = s[cur];
				cnt++;
				left -= v;
			}
			cur = (cur + 1 == m) ? 0 : cur + 1;
		}
	}
	return false;
}

int bin(const vector<int>& s, int n, int m, int k) {
	int min = 1, max = 100000;
	while (min <= max) {
		int mid = (min + max) / 2;
		if (chk(s, mid, n, m, k)) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Slot sl;
	cin >> sl.n >> sl.m >> sl.k;

	sl.s.resize(sl.m);
	for (int i = 0; i < sl.m; ++i) {
		cin >> sl.s[i];
	}
	
	int ans = bin(sl.s, sl.n, sl.m, sl.k);
	cout << ans << '\n';
	return 0;
}