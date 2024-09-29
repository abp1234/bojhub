#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Data {
	int key, value;
};

int LowerBound(vector<int>* lst, int num) {
	int low = 0;
	int high = lst->size() - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (num <= (*lst)[mid]) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return high;
}

int main() {
	map<int, int> dic;
	vector<int> lst, result, backtrace;
	vector<int> lis = { -1 };
	int n;
	cin >> n;

	Data* arr = new Data[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].value >> arr[i].key;
		dic[arr[i].key] = arr[i].value;
	}

	for (auto it = dic.begin(); it != dic.end(); ++it) {
		lst.push_back(it->second);
	}

	for (int i = 0; i < lst.size(); i++) {
		if (lst[i] > lis.back()) {
			lis.push_back(lst[i]);
		}
		else {
			lis[LowerBound(&lis, lst[i])] = lst[i];
		}
		result.push_back(find(lis.begin(), lis.end(), lst[i]) - lis.begin() + 1);
	}

	int lisLength = lis.size();
	for (int i = lst.size() - 1; i >= 0; i--) {
		if (result[i] == lisLength) {
			backtrace.push_back(lst[i]);
			lisLength--;
		}
	}

	cout << n - (lis.size() - 1) << '\n';

	sort(lst.begin(), lst.end());
	for (int i = 0; i < backtrace.size(); i++) {
		lst.erase(remove(lst.begin(), lst.end(), backtrace[i]), lst.end());
	}

	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << '\n';
	}

	delete[] arr;
	return 0;
}