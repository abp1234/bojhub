#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, temp;
	cin >> N >> S;
	vector<int>arr(N+1);
	int point_one = 1;
	int point_two = 0;
	for (int i = 1; i < N+1; i++) {
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
		if (point_two==0&&arr[i] >= S) {
			point_two = i;
		}
	}
	if (arr[N] >= S) {
		int flag = point_two-point_one+1;
		while (point_two != N+1) {
			if (arr[point_two] - arr[point_one-1] >= S) {
				flag=min(flag, point_two - point_one+1);
				point_one += 1;
			}
			else {
				point_two += 1;
			}
		}
		cout << flag;
	}
	else {
		cout << 0;
	}

	return 0;
}