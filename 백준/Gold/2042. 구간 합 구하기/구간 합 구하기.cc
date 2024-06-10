#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N, M, K, temp;
	cin >> N >> M >> K;
	vector<long long>arr(N);
	vector<long long>sum_arr(N);
	cin >> arr[0];
	sum_arr[0] = arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		sum_arr[i] = sum_arr[i-1] + arr[i];
	}
	vector<pair<long long, long long>>calc;
	long long plt0, plt1, temp0, temp1;
	for (int i = 0; i < M + K; i++) {
		cin >> temp;
		if (temp == 1) {
			cin >> plt0 >> plt1;
			calc.push_back(make_pair(plt0-1, -arr[plt0-1] +plt1));
			arr[plt0 - 1] = plt1;
		}
		else {
			temp0 = 0, temp1 = 0;
			cin >> plt0 >> plt1;
			for (int j = 0; j < calc.size(); j++) {
				if (calc[j].first <=plt0-2) {
					temp0 += calc[j].second;
				}
				if (calc[j].first <= plt1-1) {
					temp1 += calc[j].second;
				}
			}
			if (plt0 - 1 == 0) {
				cout << sum_arr[plt1 - 1] + temp1 << '\n';
			}
			else {
				cout << sum_arr[plt1 - 1] + temp1 - sum_arr[plt0 - 2] - temp0 << '\n';
			}
			
		}
	}

	return 0;
}