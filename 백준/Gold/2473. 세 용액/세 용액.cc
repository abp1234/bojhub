#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <tuple>
using namespace std;

const long long INF = numeric_limits<long long>::max();

int search(vector<long long>& arr, long long temp,int started,int ended) {
	int start = started;
	int end = ended;
	while (start<end) {
		int mid = (start + end) / 2;
		if (temp < arr[mid])
			end = mid ;
		else
			start = mid + 1;
	}
	return start;
	//if (start == ended) return start;
	//if (start == started) return start;
	//return (abs(arr[end] - temp) < abs(arr[end - 1] - temp)) ? end : end-1 ;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<long long>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.begin() + N);
	if (N == 3) {
		for (auto i : arr)
			cout << i << " ";
		return 0;
	}
	int start = 0;
	int end = N - 1;
	long long min_cost = INF;
	tuple<long long, long long, long long> result;
	for (int a = 0; a < N - 2; a++) {
		for (int b = a + 1; b <N-1 ; b++) {
			start = b;
			end = N-1 ;
			long long temp = arr[start] + arr[a];
			int idxed = search(arr, -temp, start+1, end);
			for (int c = idxed-3; c < idxed + 5; c++) {
				if (c > b && c < N) {
					int idx = c;
					if (idx >= 0 && idx<N && min_cost > abs(arr[start] + arr[a] + arr[idx])) {
						min_cost = abs(arr[start] + arr[a] + arr[idx]);
						result = { arr[a], arr[start],  arr[idx] };
					}
				}
				
			}
		}
	}
	long long a, b, c;
	tie(a, b, c) = result;
	cout << a << " " << b << " " << c << "\n";


	return 0;
}

