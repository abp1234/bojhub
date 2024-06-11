#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max_num = 2;
int N;
int diry[] = { 0,0,-1,1 };
int dirx[] = { 1,-1,0,0 };
void make_number(int l, int j,int i, vector<vector<int>>& current_num, vector<vector<int>>& check) {
	if (current_num[l][j] == 0) return;
	int n = 1;
	while (1) {
		int dy = diry[i] * n + l;
		int dx = dirx[i] * n + j;
		if (dy < 0 || dx < 0 || dy >= N || dx >= N) {
			int dy = diry[i] * (n - 1) + l;
			int dx = dirx[i] * (n - 1) + j;
			if (l != dy || j != dx) {
				current_num[dy][dx] = current_num[l][j];
				current_num[l][j] = 0;
			}
			break;
		}
		if (current_num[dy][dx] != 0) {
			if (current_num[dy][dx] == current_num[l][j] && check[dy][dx] == 0) {
				check[dy][dx] = 1;
				current_num[dy][dx] *= 2;
				current_num[l][j] = 0;
				max_num = max(max_num, current_num[dy][dx]);
			}
			else {
				int dy = diry[i] * (n - 1) + l;
				int dx = dirx[i] * (n - 1) + j;
				if (l != dy || j != dx) {
					current_num[dy][dx] = current_num[l][j];
					current_num[l][j] = 0;
				}
			}
			break;
		}
		n++;
	}
}
int dfs(int cnt,vector<vector<int>>& current_num) {
	if (cnt == 5) {

		return max_num;
	}
	
	vector<vector<int>>backup = current_num;
	for (int i = 0; i < 4; i++) {
		current_num = backup;
		vector<vector<int>>check(N, vector<int>(N,0));
		if (i == 0 || i==1) {
				for (int l = 0; l < N; l++) {
					for (int j = (i==0?N-2:1);(i==0?j>=0: j < N); (i==0?j--:j++)) {
						make_number(l, j,i, current_num, check);
					}
			}
		}
		else {
				for (int l = (i == 3 ? N - 2 : 1); (i == 3 ? l >= 0 : l < N); (i == 3 ? l-- : l++)) {
					for (int j = 0; j < N; j++) {
						make_number(l, j, i, current_num, check);
					}
				}
		}
			
		dfs(cnt + 1, current_num);
	}
	return max_num;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	vector<vector<int>>arr(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			max_num=max(max_num, arr[i][j]);
		}
	}
	
	cout << dfs(0, arr); 
	return 0;
}


