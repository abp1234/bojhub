#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, D;
	cin >> N >> K >> D;
	vector<vector<int>>calc(K,vector<int>(3));
	for (int i = 0; i < K; i++) {
		cin >> calc[i][0] >> calc[i][1] >> calc[i][2];
	}
	auto count_package = [&](int num) {
		long long sum_0 = 0;
		for (int i = 0; i < K; i++) {
			if (num >= calc[i][0]) {
				int end = min(num, calc[i][1]);
				sum_0 += (end - calc[i][0]) / calc[i][2] + 1;
			}
		}
		return sum_0;
		};
	int left = 1, right = N;
	int result = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (count_package(mid) >= D) {
			result = mid;
			right = mid - 1;
		}
		else  {
			left = mid + 1;
		}
	}
	cout << result;
	return 0;
}