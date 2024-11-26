#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
	}

	sort(ar.begin(), ar.end());

	int t = 1;

	for (int x : ar) {
		if (t < x)break;
		t += x;
	}

	cout << t << '\n';
	return 0;

}