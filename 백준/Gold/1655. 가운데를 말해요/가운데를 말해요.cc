#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	priority_queue<int> lH;
	priority_queue<int, vector<int>, greater<int>> rH;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		if (lH.size() == rH.size()) {
			lH.push(x);
		}
		else {
			rH.push(x);
		}

		if (!rH.empty() && rH.top() < lH.top()) {
			int lV = lH.top(); lH.pop();
			int rV = rH.top(); rH.pop();

			lH.push(rV);
			rH.push(lV);
		}

		cout << lH.top() << '\n';
	}
	return 0;
}