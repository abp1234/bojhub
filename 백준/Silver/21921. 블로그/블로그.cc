#include <iostream>
#include<vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,X;
	cin >> N >> X;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int max_sm = 0;
	int max_cnt = 0;
	int sm = 0;
	int current_cnt = 0;
	for (int i = 0; i < N; i++) {
		sm += arr[i];
		current_cnt++;
		if (current_cnt >= X) {
			if (current_cnt > X) {
				sm -= arr[i - X];
				current_cnt--;
			}
			if (max_sm <= sm) {
				if (max_sm == sm) {
					max_cnt++;
				}
				else {
					max_sm = sm;
					max_cnt = 1;
				}
			}
		}
	}
	if (max_sm == 0) {
		cout << "SAD";
		return 0;
	}
	cout << max_sm << '\n' << max_cnt;

	return 0;
}