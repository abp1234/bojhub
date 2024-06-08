#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	long long temp;
	cin >> N;
	priority_queue<tuple<long long, long long>> arr;
	vector<long long>check(N + 4);
	for (int i = 0;i < N;i++) {
		cin >> temp;
		arr.push(make_tuple(temp, i+1));
	}
	long long heigh, index;
	long long max_size = 0LL;
	while (!arr.empty()) {
		tie(heigh, index) = arr.top();
		arr.pop();
		check[index] = check[index - 1] + 1;
		if (check[index - 1] != 0) {
			check[index- check[index-1]] = check[index];
		}
		if (check[index + 1] != 0) {
			temp = check[index] + check[index + 1];
			check[index + check[index + 1]] =temp ;
			check[index+1- check[index]] = temp;
			max_size = max(temp * heigh, max_size);
		}
		
		max_size = max(check[index] * heigh, max_size);
		if (heigh * N <= max_size) break;
	}
	cout << max_size;
	return 0;
}