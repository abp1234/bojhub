#include<iostream>
#include<vector>
using namespace std;
vector<int>check;
int find(int x) {
	if (check[x] == -1) {
		return x;
	}
	check[x] = find(check[x]);
	return check[x];
}
int union_0(int a,int b) {
	int a_boss = find(a);
	int b_boss = find(b);
	if (a_boss == b_boss) {
		return 0;
	}
	check[b_boss] = a_boss;
	return 1;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	check.assign(n,-1);

	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		if (union_0(a, b) == 0) {
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
