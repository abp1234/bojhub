#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

string toStr(long x) {
	ostringstream oss;
	oss << x;
	return oss.str();
}

struct Fd {
	int i;
	long a, b;
	Fd(int ix, long aa, long bb) : i(ix),a(aa),b(bb){}
};

bool cmpB(const Fd& x, const Fd& y) {
	return x.b < y.b;
}

int main() {
	int n;
	cin >> n;

	vector<Fd> fb;
	vector<Fd> fa;
	long bs = 0;
	priority_queue<long, vector<long>, greater<>>ab;
	vector<bool> vis(n, false);
	string sb;

	for (int i = 0; i < n; i++) {
		long a, b;
		cin >> a >> b;
		Fd f(i, a, b);
		fb.push_back(f);
		fa.push_back(f);
	}

	sort(fa.begin(), fa.end(), [](const Fd& x, const Fd& y) {
		return x.a < y.a;
		});

	sort(fb.begin(), fb.end(), cmpB);

	int ca = 0;
	for (int i = 0; i < n; i++) {
		bs += fb[i].b;
		vis[fb[i].i] = true;
		ab.push(fb[i].a - fb[i].b);

		long v1 = bs + ab.top();

		if (i == n - 1) {
			sb += toStr(v1);
			break;
		}

		while (vis[fa[ca].i]) {
			ca++;
		}

		long v2 = bs - fb[i].b + fa[ca].a;
		sb += toStr(min(v1, v2)) + "\n";
	}

	cout << sb;
	return 0;

}