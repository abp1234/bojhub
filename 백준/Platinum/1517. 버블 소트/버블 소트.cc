#include <iostream>
#include <vector>
#include <memory>

using namespace std;

long long ans = 0;

void ms(vector<long long>& arr, int s, int e) {
	if (s >= e) return;

	int m = (s + e) / 2;

	ms(arr, s, m);
	ms(arr, m + 1, e);

	vector<long long> tmp;
	int l = s, r = m + 1;
	while (l <= m && r <= e) {
		if (arr[l] <= arr[r]) {
			tmp.push_back(arr[l++]);
		}
		else {
			tmp.push_back(arr[r++]);
			ans += (m - l + 1);
		}
	}
	while (l <= m)tmp.push_back(arr[l++]);
	while (r <= e)tmp.push_back(arr[r++]);

	for (int i = 0; i < tmp.size(); ++i) {
		arr[s + i] = tmp[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<long long>arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	ms(arr, 0, n - 1);
	cout << ans << "\n";

	return 0;
}