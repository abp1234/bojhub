#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<long long>arr;

int search(long long choice,long long num) {
	arr.push_back(num);
	for (int i = choice-1 ;i >-1;i--) {
		search(i,i+num*10);
	}
	return 0;
}

int main(void) {
	int N;
	cin >> N;
	search(10,0);
	if (arr.size() > N+1) {
		sort(arr.begin(), arr.end());

		cout << arr[N+1];
	}
	else {
		cout << -1;
	}
	return 0;
}