#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#define INT_MAX 0x7fffffff

using namespace std;

int binSearch(vector<int>& arr, int value) {
	int ans = arr.size();
	int L = 0, R = int(arr.size()) - 1, mid = 0;

	while (L <= R) {
		mid = (L + R) / 2;
		if (arr[mid] >= value) {
			ans = mid;
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int N, M, c1, c2;
		cin >> N >> M;
		cin >> c1 >> c2;
		int dx = abs(c1 - c2);

		vector<int> cows(N);
		for (int i = 0; i < N; i++) {
			cin >> cows[i];
		}
		sort(cows.begin(), cows.end());
		int minDist = INT_MAX;
		int count = 0;

		for (int i = 0; i < M; i++) {
			int hPos;
			cin >> hPos;

			int X = binSearch(cows, hPos);

			if (X < cows.size()) {
				int dist = cows[X] - hPos;
				if (minDist == dist) {
					count++;
				}
				else if (minDist > dist) {
					minDist = dist;
					count = 1;
				}
			}
			if (X - 1 >= 0) {
				int dist = hPos - cows[X - 1];
				if (minDist == dist) {
					count++;
				}
				else if (minDist > dist) {
					minDist = dist;
					count = 1;
				}
			}
		}
		cout << "#" << test_case << " " << (dx + minDist) << " " << count << "\n";
	}
}