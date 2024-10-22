#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N, M;
vector<vector<int>> bd;

struct P
{
	int x, y;
};

void cln() {
	int lst = 0;
	for (int i = 0; i < N; i++) {
		int ed = lst;
		for (int j = lst; j < M; j++) {
			if (bd[i][j]) {
				ed = j;
			}
		}
		for (int j = lst; j <= ed; j++) {
			bd[i][j] = 0;
		}
		lst = ed;
	}
}

int sm() {
	int s = 0;
	for (auto& r : bd) {
		s += accumulate(r.begin(), r.end(), 0);
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	bd.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> bd[i][j];
		}
	}

	int res = 0;

	while (sm() != 0) {
		cln();
		res++;
	}

	cout << res << '\n';
	return 0;
}