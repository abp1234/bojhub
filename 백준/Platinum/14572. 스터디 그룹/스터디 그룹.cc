#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct St {
	int a;
	int s;
	vector<int> al;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, d;
	cin >> n >> k >> d;

	vector<int>al(k + 1, 0);
	vector<St>st(n);
	for (int i = 0; i < n; ++i) {
		cin >> st[i].a >> st[i].s;
		st[i].al.resize(st[i].a);
		for (int j = 0; j < st[i].a; ++j) {
			cin >> st[i].al[j];
		}
	}

	sort(st.begin(), st.end(), [](const St& x, const St& y) {
		return x.s < y.s;
		});
	int i = 0, j = 0, sk = 0, sa = 0, mx = -1;

	while (true) {
		if (st[i].s - st[j].s > d) {
			for (int algo : st[j].al) {
				al[algo]-- ;
				if (al[algo] == 0)sk--;
			}
			++j;
		}

		if (st[i].s - st[j].s <= d) {
			sa = 0;
			for (int algo : st[i].al) {
				al[algo]++;
				if (al[algo] == i - j + 1)sa++;
				if (al[algo] == 1)sk++;
			}

			mx = max(mx, (sk - sa) * (i - j + 1));
			++i;
		}
		if (i == n)break;
	}

	cout << mx << '\n';
	return 0;


}