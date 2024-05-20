#include <iostream>
#include<vector>
using namespace std;

int sum(const vector<int>& arr) {
	int num = 0;
	for (int i = 0; i < arr.size(); i++) {
		num += arr[i];
	}

	return num;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int K, temp;
	cin >> K;
	vector<int>arr;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		if (temp == 0 && !arr.empty()) {
			arr.pop_back();
		}
		else {
			arr.push_back(temp);
		}
	}

	cout << sum(arr);
	return 0;
}