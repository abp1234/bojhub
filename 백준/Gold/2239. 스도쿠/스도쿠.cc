#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int SIZE = 9;

int sdoku[SIZE][SIZE];
vector<pair<int, int>> zero_p;

bool row_check(int r, int num) {
	for (int x = 0; x < SIZE; ++x) {
		if (num == sdoku[r][x]) {
			return false;
		}
	}
	return true;
}

bool col_check(int c, int num) {
	for (int x = 0; x < SIZE; ++x) {
		if (num == sdoku[x][c]) {
			return false;
		}
	}
	return true;
}

bool three_check(int r, int c, int num) {
	int nc = (c / 3) * 3;
	int nr = (r / 3) * 3;
	for (int x = 0; x < 3; ++x) {
		for (int y = 0; y < 3; ++y) {
			if (sdoku[nr + x][nc + y] == num) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int depth) {
	if (depth >= zero_p.size()) {
		for (int k = 0; k < SIZE; ++k) {
			for (int l = 0; l < SIZE; ++l) {
				cout << sdoku[k][l];
			}
			cout << '\n';
		}
		exit(0);
	}

	int nr = zero_p[depth].first;
	int nc = zero_p[depth].second;

	for (int j = 1; j <= SIZE; ++j) {
		if (row_check(nr, j) && col_check(nc, j) && three_check(nr, nc, j)) {
			sdoku[nr][nc] = j;
			dfs(depth + 1);
			sdoku[nr][nc] = 0;
		}
	}
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
for (int i = 0; i < SIZE; ++i) {
	for (int j = 0; j < SIZE; ++j) {
		char temp;
		cin >> temp;
		sdoku[i][j] = temp - '0';
		if (sdoku[i][j] == 0) {
			zero_p.emplace_back(i, j);
		}
	}
}
dfs(0);
return 0;
}
