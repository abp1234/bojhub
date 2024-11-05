#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct St {
	int x, y;
	St(int a, int b = -1):x(a),y(b){}
};

class Fm {
public:
	int pr = 0;
	Fm(int C, int N) {
		vector<St> stk;

		for (int i = 0; i < C; i++) {
			int t;
			cin >> t;
			stk.emplace_back(t);
		}

		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			stk.emplace_back(a, b);
		}

		sort(stk.begin(), stk.end(), [](const St& a, const St& b) {
			return (a.x == b.x) ? (a.y > b.y) : (a.x < b.x);
			});
		priority_queue<int, vector<int>, greater<int>>pq;
		for (const auto& ls : stk) {
			if (ls.y != -1) {
				pq.push(ls.y);
			}
			else {
				while (!pq.empty() && pq.top() < ls.x) {
					pq.pop();
				}
				if (!pq.empty()) {
					pq.pop();
					pr++;
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C, N;
	cin >> C >> N;
	Fm fm(C, N);
	cout << fm.pr << '\n';
	return 0;
}