#include<iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long T, M, temp,temp1;
	cin >> T;
	while (T--) {
		int line = 0;
		cin >> M;
		cout << (M + 1) / 2 << '\n';
		int cnt_d = 0;
		int cnt_u = 0;
		priority_queue<long long>down;
		priority_queue<long long>up;
		
		for (int i = 0; i < M; i++) {

			cin >> temp;
			//if (i != 0 && i % 10 == 0)
				//cin >> temp1;
			if (cnt_d == 0 || cnt_u == 0) {
				if (cnt_d == 0) {
					cnt_d++;
					down.push(temp);
				}
				else if (cnt_u == 0) {
					cnt_u++;
					if (down.top() < temp) {
						up.push(-temp);
					}
					else {
						temp1 = down.top();
						down.pop();
						up.push(-temp1);
						down.push(temp);
					}
				}
			}
			else {
				if (-up.top() < temp) {
					up.push(-temp);
					cnt_u++;
					if (cnt_u - cnt_d > 0) {
						temp1 = up.top();
						up.pop();
						down.push(-temp1);
						cnt_u--;
						cnt_d++;
					}
				}
				else {
					down.push(temp);
					cnt_d++;
					if (cnt_d - cnt_u>1) {
						temp1 = down.top();
						down.pop();
						up.push(-temp1);
						cnt_u++;
						cnt_d--;
					}
				}
			}
			if ((cnt_d + cnt_u) % 2 == 1) {
				cout << down.top() << ' ';
				line++;
				if (line % 10 == 0)
					cout << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}