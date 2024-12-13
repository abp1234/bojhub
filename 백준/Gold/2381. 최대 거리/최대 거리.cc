#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Pt {
	int x, y;
};

inline int dist(const Pt* a, const Pt* b) {
	return abs(a->x - b->x) + abs(a->y - b->y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<Pt*> pts(n);
	for (int i = 0; i < n; ++i) {
		pts[i] = new Pt();
		cin >> pts[i]->x >> pts[i]->y;
	}

	auto cmp1 = [](const Pt* a, const Pt* b) {
		return (a->x + a->y) < (b->x + b->y);
		};
	sort(pts.begin(), pts.end(), cmp1);
	int d1 = dist(pts.front(), pts.back());

	auto cmp2 = [](const Pt* a, const Pt* b) {
		return (a->x - a->y) < (b->x - b->y);
		};
	sort(pts.begin(), pts.end(), cmp2);
	int d2 = dist(pts.front(), pts.back());

	cout << max(d1, d2) << '\n';

	for (auto& p : pts)delete p;

	return 0;
}