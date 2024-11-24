#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

struct P
{
	vector<int>n, m;
	int N, M, X;
};

int ri() {
	int x;
	cin >> x;
	return x;
}

bool ip(const vector<int>& n, const vector<int>& m, int c, int X, int M) {
	long long s = 0;
	for (int i = 0; i < c; ++i) {
		s += max(0, n[i] - m[M - c + i]);
		if (s > X)return false;
	}
	return true;
}

int mc(const P& p, int s, int e) {
	int res = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (ip(p.n, p.m, mid, p.X, p.M)) {
			res = mid;  
			s = mid + 1; 
		}
		else {
			e = mid - 1; 
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	P p;
	p.N = ri();
	p.M = ri();
	p.X = ri();

	p.n.resize(p.N);
	for (int& x : p.n)x = ri();
	sort(p.n.begin(), p.n.end());

	p.m.resize(p.M);
	for (int& x : p.m)x = ri();
	sort(p.m.begin(), p.m.end());

	cout << mc(p, 0, min(p.N, p.M)) << '\n';
}