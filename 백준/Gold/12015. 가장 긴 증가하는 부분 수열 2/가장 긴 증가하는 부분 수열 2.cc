#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;
const int INF = numeric_limits<int>::max();
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = N-1; i >-1; i--) {
		cin >> A[i];
	}
	int num;

	vector<int>check(N);
	check[0]=A[0];
	int length = 1;
	for (int i = 1; i < N; i++) {
		auto it = lower_bound(check.begin(), check.begin()+length, A[i], [](const int& a, const int& b) {
			return a > b;
			});
		int index = distance(check.begin(), it);
		//num = 0;
		num = index;
		if (index<length) {
			if (*it < A[i]) {
				*it = A[i];
			}
		}
		else {
			check[num]=A[i];
			length++;
		}
	}
	cout << length;

	return 0;
}