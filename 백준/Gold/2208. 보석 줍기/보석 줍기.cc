#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct D {
	int* a;
	int* ps;
	int s;
	int v;
};

void f(int n, int m) {
	D d;
	d.a = new int[n];
	d.ps = new int[n + 1];
	d.ps[0] = 0;
	d.v = 0;

	for (int i = 0; i < n; i++) {
		cin >> d.a[i];
		d.v += d.a[i];
		d.ps[i + 1] = d.v;
	}
	int an = 0, tmp = 0;
	for (int i = m - 1; i < n; i++) {
		tmp = min(tmp, d.ps[i - (m - 1)]);
		an = max(an, d.ps[i + 1] - tmp);
	}

	cout << an << '\n';
	delete[] d.a;
	delete[] d.ps;
}

int main() {
	int n, m;
	cin >> n >> m;
	f(n, m);
	return 0;
}