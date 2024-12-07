#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n, m;
vector<int> arr;
vector<int> ansList;
int ans;

bool check(int mid) {
	vector<int> temp;
	int groupCount = 0;
	int needGroup = m;
	int i = 0;

	while (i < n) {
		int sum = 0;
		int cnt = 0;

		while (i < n) {
			sum += arr[i];
			cnt++;
			if (sum > mid) {
				cnt--;
				sum -= arr[i];
				break;
			}
			if (needGroup - groupCount == n - i) {
				i++;
				break;
			}
			i++;
		}
		temp.push_back(cnt);
		groupCount++;
	}
	if (m >= groupCount) {
		ansList = temp;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int s = *max_element(arr.begin(), arr.end());
	int e = accumulate(arr.begin(), arr.end(),0);

	while (s <= e) {
		int mid = (s + e) / 2;

		if (check(mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	cout << ans << '\n';
	for (int val : ansList) {
		cout << val << " "; 
	}
	cout << '\n';
	return 0;
}