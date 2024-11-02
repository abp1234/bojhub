#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct C {
	int* a;
	int n;
};

int maxP(C* c) {
	int st = 0;
	int ans = 0;

	while (st < c->n) {
		int ed = st;

		while (ed + 1 < c->n && c->a[ed + 1] == c->a[st] && ed + 1 - st < 2) {
			ed++;
		}

		int* i = c->a + st - 1, * j = c->a + ed + 1;
		int sz = ed - st + 1;
		int v = c->a[st];

		while (i >= c->a && j < c->a + c->n) {
			if (*i == *j && *i < v) {
				v = *i;
				i--;
				j++;
				sz += 2;
					
			}
			else {
				break;
			}
		}
		ans = max(ans, sz);
		st = j - c->a;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int& x : arr) {
		cin >> x;
	}
	C c{ arr.data(),n };
	cout << maxP(&c) << '\n';
	return 0;
}