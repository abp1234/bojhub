#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
#include <cfloat>
#include <iomanip>
using namespace std;

struct P
{
	int x, y;
};
P s(vector<P*>& m) {
	P r = { 0,0 };
	for (auto& i : m) {
		r.x += i->x;
		r.y += i->y;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<P*> d(N);
		for (int i = 0; i < N; ++i) {
			d[i] = new P;
			cin >> d[i]->x >> d[i]->y;
		}
		P ts = s(d);
		double r = DBL_MAX;

		vector<int> idx(N, 1);
		fill(idx.begin(), idx.begin() + N / 2, 0);
		do {
			vector<P*> mn;
			for (int i = 0; i < N; ++i) {
				if (!idx[i])mn.push_back(d[i]);
			}
			P cs = s(mn);
			r = min(r, sqrt(pow(2 * cs.x - ts.x, 2) + pow(2 * cs.y - ts.y, 2)));
		} while (next_permutation(idx.begin(), idx.end()));
		cout << fixed << setprecision(6) << r << '\n';
		for (int i = 0; i < N; ++i) {
			delete d[i];
		}
	}
	return 0;

}