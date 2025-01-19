#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;

	vector<char> l1(s1.begin(), s1.end());
	vector<char> l2(s2.begin(), s2.end());
	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end(), greater<>());

	int n = l1.size();
	deque<char> q1(l1.begin(), l1.begin() + (n - n / 2));
	deque<char> q2(l2.begin(), l2.begin() + (n / 2));

	vector<char> res(n);
	int idx = 0, revIdx = n - 1;
	int turn = 1;

	for (int i = 0; i < n; i++) {
		deque<char>& curQ = (turn == 1) ? q1 : q2;

		if (!q1.empty() && !q2.empty() && q1.front() >= q2.front()) {
			res[revIdx--] = curQ.back();
			curQ.pop_back();
		}
		else {
			res[idx++] = curQ.front();
			curQ.pop_front();
		}	turn = -turn;
	}
	for (char c : res) {
		cout << c;

	}
	cout << '\n';
	return 0;
}