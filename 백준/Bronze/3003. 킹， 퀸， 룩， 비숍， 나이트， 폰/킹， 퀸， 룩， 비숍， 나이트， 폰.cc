#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int temp;
	vector<int>arr;
	for (int i = 0; i < 6; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	int check[] = { 1,1,2,2,2,8 };
	for (int i = 0; i < 6; i++) {
		cout << -arr[i] + check[i]<<" ";
	}


	return 0;
}