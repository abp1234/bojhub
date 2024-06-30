#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<char>arr(1);
	vector<char>lst(1);
	string temp2;
	for (int i = 0; i < 2; i++) {
		cin >> temp2;
		int j = 0;
		while (i==0 && j!=temp2.size()) {
			arr.push_back(temp2[j]);
			j++;
		}
		while (i==1 && j != temp2.size()) {
			lst.push_back(temp2[j]);
			j++;
		}
	}
	
	vector<vector<int>>check(lst.size(), vector<int>(arr.size()));
	for (int i = 1; i < lst.size(); i++) {
		for (int j = 1; j < arr.size(); j++) {
			if (lst[i] == arr[j]) {
				check[i][j] = check[i - 1][j-1] + 1;
			}
			else {
				check[i][j] = max(check[i][j - 1],check[i-1][j]);
			}
		}
	}
	vector<char>result;
	int j = arr.size() - 1;
	int i = lst.size() - 1;
	while ( j >=1 && i>=1) {
		if (check[i-1][j] == check[i][j]) {
			i--;
		}
		else if (check[i][j - 1] == check[i][j]) {
			j--;
		}
		else  {
			if (check[i - 1][j - 1] != check[i][j])
				result.push_back(arr[j]);
			i--;
			j--;
		}
	}





	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[result.size()-1-i] ;
	}

	return 0;
}