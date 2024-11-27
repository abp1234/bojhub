#include <iostream>
#include <vector>

using namespace std;

void cl(int x, vector<int>& a, int p) {
	while (x > 0) {
		a[x % 10] += p;
		x /= 10;
	}
}

int main() {
	long long s = 1, e, p = 1;
	cin >> e;

	vector<int> r(10, 0);

	while (s <= e) {
		while (e % 10 != 9 && s <= e) {
			cl(e, r, p);
			e--;
		}

		while (s % 10 != 0 && s <= e) {
			cl(s, r, p);
			s++;
		}

		if (s > e)break;

		s /= 10;
		e /= 10;

		for (int i = 0; i < 10; i++) {
			r[i] += (e - s + 1) * p;
		}

		p *= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << r[i] << " ";
	}
	cout << '\n';

	return 0;
}