#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int UP = 1, DOWN = 2, RIGHT = 3, LEFT = 4;

int R, C, M;
vector<vector<tuple<int, int, int>>> board;

int fish(int j) {
	for (int i = 0; i < R; i++) {
		if (get<2>(board[i][j]) != 0) {
			int size = get<2>(board[i][j]);
			board[i][j] = make_tuple(0, 0, 0);
			return size;
		}
	}
	return 0;
}

tuple<int, int, int> get_next_loc(int i, int j, int speed, int dir) {
	if (dir == UP || dir == DOWN) {
		int cycle = R * 2 - 2;
		if (dir == UP) {
			speed += 2 * (R - 1) - i;
		}
		else {
			speed += i;
		}
		speed %= cycle;
		if (speed >= R) {
			return make_tuple(2 * R - 2 - speed, j, UP);
		}
		return make_tuple(speed, j, DOWN);
	}
	else {
		int cycle = C * 2 - 2;
		if (dir == LEFT) {
			speed += 2 * (C - 1) - j;
		}
		else {
			speed += j;
		}
		speed %= cycle;
		if (speed >= C) {
			return make_tuple(i, 2 * C - 2 - speed, LEFT);
		}
		return make_tuple(i, speed, RIGHT);
	}
}

void move() {
	vector<vector<tuple<int, int, int>>> new_board(R, vector<tuple<int, int, int>>(C, make_tuple(0, 0, 0)));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (get<2>(board[i][j]) != 0) {
				int ni, nj, nd;
				tie(ni, nj, nd) = get_next_loc(i, j, get<0>(board[i][j]), get<1>(board[i][j]));
				if (get<2>(new_board[ni][nj]) != 0) {

					new_board[ni][nj] = max(new_board[ni][nj], make_tuple(get<0>(board[i][j]), nd, get<2>(board[i][j])),
						[](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
							return get<2>(a) < get<2>(b);
						});
				}
				else {
					new_board[ni][nj] = make_tuple(get<0>(board[i][j]), nd, get<2>(board[i][j]));
				}
			}
		}
	}
	board = new_board;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;
	board.resize(R, vector<tuple<int, int, int>>(C, make_tuple(0, 0, 0)));

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--, c--;
		board[r][c] = make_tuple(s, d, z);
	}

	int ans = 0;

	for (int j = 0; j < C; j++) {
		ans += fish(j);
		move();
	}

	cout << ans << '\n';
	return 0;
}