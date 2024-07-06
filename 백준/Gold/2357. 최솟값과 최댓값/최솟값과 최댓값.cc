#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

//const int MAX_TABLE = 10;
//const int n = 5;
const int INF = numeric_limits<int>::max();
int n, m;
vector<int>arr;
vector<tuple<int,int>>segtree;
void init() {
	for (int i = 0; i < n; i++) {
		segtree[n + i]= make_tuple(arr[i],arr[i]);
	}
	for (int i = n - 1; i >= 1; i--) {
		get<0>(segtree[i]) = max(get<0>(segtree[i << 1]), get<0>(segtree[i << 1 | 1]));
		get<1>(segtree[i]) = min(get<1>(segtree[i << 1]), get<1>(segtree[i << 1 | 1]));
	}
}
void update(int idx, int x) {
	segtree[idx + n] = make_tuple(x,x);
	int i = ((idx + n) >> 1);
	for (; i >= 1; i >>= 1) {
		get<0>(segtree[i]) = max(get<0>(segtree[i << 1]), get<0>(segtree[i << 1 | 1]));
		get<1>(segtree[i]) = min(get<1>(segtree[i << 1]), get<1>(segtree[i << 1 | 1]));
	}
}
pair<int,int> find_x(int l, int r) {
	l += n;
	r += n;
	int result_max = -INF;
	int result_min = INF;
	while (l != r) {
		if (l & 1) {
			result_max = max(result_max, get<0>(segtree[l]));
			result_min = min(result_min, get<1>(segtree[l]));
			l++;
		}	
		if (r & 1) {
			r--;
			result_max = max(result_max,get<0>(segtree[r]));
			result_min = min(result_min,get<1>(segtree[r]));
		}
		l >>= 1;
		r >>= 1;
	}
	return make_pair(result_max,result_min);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	segtree.resize(2*n+1);
	init();
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		pair<int,int> result=find_x(a - 1, b );
		cout << result.second<<' '<<result.first <<'\n';
	}
	return 0;
}