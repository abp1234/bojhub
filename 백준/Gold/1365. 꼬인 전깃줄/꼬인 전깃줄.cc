#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<int> ln(n);
	for (int i = 0; i < n; ++i) {
		cin >> ln[i];
	}

	vector<int> rs;

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			rs.push_back(ln[0]);
		}
		else if (rs.back() < ln[i]) {
			rs.push_back(ln[i]);
		}
		else {
			auto pos = lower_bound(rs.begin(), rs.end(), ln[i]);
			*pos = ln[i];
		}
	}
	cout << n - rs.size();
	return 0;

}