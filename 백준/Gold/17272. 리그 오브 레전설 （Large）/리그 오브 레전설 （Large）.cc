#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

struct Mat {
	vector<vector<long long>> v;
	int sz;
	Mat(int n) :sz(n), v(n, vector<long long>(n, 0)) {}
};

Mat mul(Mat& a, Mat& b) {
	Mat r(a.sz);
	for (int i = 0; i < a.sz; ++i) {
		for (int j = 0; j < b.sz; ++j) {
			for (int k = 0; k < a.sz; ++k) {
				r.v[i][j] += a.v[i][k] * b.v[k][j] % MOD;
				r.v[i][j] %= MOD;
			}
		}
	}
	return r;
}

Mat cal(Mat& a, long long n) {
	Mat id(a.sz);
	for (int i = 0; i < a.sz; ++i)id.v[i][i] = 1;
	if (n == 0)return id;
	if (n == 1)return a;

	Mat c = cal(a, n / 2);
	Mat c2 = mul(c, c);
	return n % 2 ? mul(c2, a) : c2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, m;
	cin >> n >> m;

	Mat mat(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			mat.v[i][j] = (i == j && i == 0) || (i == m - 1 && j == 0) || (j - i == 1);
		}
	}

	Mat res = cal(mat, n);
	cout << res.v[0][0] << '\n';
	return 0;
}