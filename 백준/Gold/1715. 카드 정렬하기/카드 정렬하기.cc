#include <iostream>
#include <queue>

using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, temp;
	cin >> N;
	priority_queue<int>q;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		q.push(-temp);
	}
	int result = 0;
	int temp_1, temp_2;
	while (q.size()>1) {
		temp_1 = q.top();
		q.pop();
		temp_2 = q.top();
		q.pop();
		result += -(temp_1 + temp_2);
		q.push(temp_1 + temp_2);
	}
	cout << result;
	return 0;
}