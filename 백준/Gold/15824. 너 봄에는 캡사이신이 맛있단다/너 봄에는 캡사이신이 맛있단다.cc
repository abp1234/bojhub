#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N;
	long long result = 0;
	cin >> N;
	vector<long long>arr(N);
	vector<long long>sum_0(N+1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<long long>calc(N,1);
	
	for (int i = 1; i < N; i++) {
		calc[i] = (calc[i-1]*2) % 1000000007;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) {
		sum_0[i+1] += arr[i] % 1000000007;
		sum_0[i+1] += sum_0[i] % 1000000007;
	}
	for (int i = 1; i < N; i++) {
		long long a, b;
		a = sum_0[N] - sum_0[i];
		b = sum_0[N-i];
		if (a < 0)
			a = 1000000007 + a;
		if (b < 0)
			b = 1000000007 + b;
		long long k = a - b;
		if(k<0)
			k = 1000000007 + k;
		result = (result+k * (calc[i - 1])) % 1000000007;
	}

	cout << result;
	return 0;
}