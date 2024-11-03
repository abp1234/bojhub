#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int idx;
	Info(int i):idx(i){}
};

int fn(int N) {
	vector<Info> p(N + 1, Info(0));
	int lg = 0, ct = 1;

	for (int i = 1; i <= N; ++i) {
		int num;
		cin >> num;
		p[num].idx = i;
	}

	for (int i = 1; i < N; ++i) {
		if (p[i].idx < p[i + 1].idx) {
			ct++;
		}
		else {
			lg = max(lg, ct);
			ct = 1;
		}
	}

	lg = max(lg, ct);

	return N - lg;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	cout << (N != 1 ? fn(N) : 0) << '\n';
	return 0;
}