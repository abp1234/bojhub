#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

struct Crd {
	int r, c;
};

int cal(int r, int c) {
	int bor = max(abs(r), abs(c));
	int def = pow(bor * 2 - 1, 2) + 1;

	if (r == bor)return def + bor * 7 + c - 1;
	if (c == -bor)return def + bor * 5 + r - 1;
	if (r == -bor)return def + bor * 3 - c - 1;

	return def + bor - r - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	vector<vector<int>> arr(r2 - r1 + 1, vector<int>(c2 - c1 + 1));
	int mx = 0;

	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			arr[i - r1][j - c1] = cal(i, j);
			mx = max(mx, arr[i - r1][j - c1]);
		}
	}

	int wd = to_string(mx).length();
	for (int i = 0; i <= r2 - r1; ++i) {
		for (int j = 0; j <= c2 - c1; ++j) {
			cout << setw(wd) << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}