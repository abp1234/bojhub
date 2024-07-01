#include <iostream>
#include <vector>
#include<set>
#include<map>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int>arr(N);
	vector<int>score(N);
	map<int, int> element_map;
	int max_num = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		element_map[arr[i]] = i;
		max_num=max(max_num, arr[i]);
	}
	for (int i = 0; i < N; i++) {
		int n = 2;
		while (arr[i] * n <= max_num) {
			if (element_map.find(arr[i] * n) != element_map.end()) {
				score[element_map[arr[i] * n]] -= 1;
				score[i] += 1;
			} 
			n++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << score[i] << " ";
	}
	return 0;
}