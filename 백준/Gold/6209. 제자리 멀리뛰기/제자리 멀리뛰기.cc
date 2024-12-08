#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, n, m;
vector<int> stone;

bool isPossible(int mid) {
	int count = 0;
	int now = 0;
	int min_distance = d;

	for (int x : stone) {
		if (x - now >= mid) {
			min_distance = min(min_distance, x - now);
			now = x;
		}
		else {
			count++;
		}
	}
	min_distance = min(min_distance, d - now);

	return count <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> d >> n >> m;
	stone.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> stone[i];
	}

	sort(stone.begin(), stone.end());

	int start = 0, end = d;
	int dist = 0;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (isPossible(mid)) {
			dist = max(dist, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << dist << '\n';

	return 0;
}