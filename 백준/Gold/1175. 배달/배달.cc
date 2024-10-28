#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Pt
{
	int x, y, d, c;
};

int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<string> mp;
deque<Pt> st;

int fp() {
	deque<Pt> q(st);
	vector<vector<vector<vector<int>>>> vis(4, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1, 1))));
	int fc = 0;
	deque<Pt> sp;
	while (!q.empty()) {
		Pt p = q.front(); q.pop_front();
		for (int b = 0; b < 4; b++) {
			if (b == p.d)continue;
			int nx = p.x + dx[b], ny = p.y + dy[b];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != '#' && vis[b][nx][ny][0]) {
				if (mp[nx][ny] == 'C') {
					if (sp.empty()) {
						fc++;
						if (fc == 2)return p.c + 1;
					}
					else if (sp.front().x != nx || sp.front().y != ny)continue;
					sp.push_back({ nx,ny,b,p.c + 1 });
				}
				else {
					if (!sp.empty())continue;
					vis[b][nx][ny][0]--;
					q.push_back({ nx,ny,b,p.c + 1 });
				}
			}
		}
		if (q.empty() && !sp.empty()) {
			vis = vector<vector<vector<vector<int>>>>(4, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1, 1))));
			mp[sp.front().x][sp.front().y] = '.';
			while (!sp.empty()) {
				q.push_back(sp.back());
				sp.pop_back();
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string ln;
		cin >> ln;
		if (st.empty() && ln.find('S') != string::npos) {
			st.push_back({ i,(int)ln.find('S'),-1,0 });
		}
		mp.push_back(ln);
	}
	cout << fp() << '\n';
	return 0;
}