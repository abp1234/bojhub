#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iomanip>

using namespace std;




struct St {
	double x;
	double y;
};

static const int MX = 16;
static const int MSK = 1 << MX;
static const double IF = 12345678.0;

static double ar[MX][MX];
static double dp[MX][MSK];
static St pt[MX];

int n;

double f(int nw, int bt) {
	if (bt == (1 << n) - 1) {
		if (ar[nw][0] > 0.0)return ar[nw][0];
		return IF;
	}
	if (dp[nw][bt] >= 0.0)return dp[nw][bt];

	dp[nw][bt] = IF;

	for (int i = 0; i < n; i++) {
		if (((bt >> i) & 1) == 0 && ar[nw][i] > 0.0) {
			double tmp = f(i, bt | (1 << i)) + ar[nw][i];
			dp[nw][bt] = min(dp[nw][bt], tmp);
		}
	}
	return dp[nw][bt];
}

inline double dist(const St& a1, const St& a2) {
	double dx = a1.x - a2.x;
	double dy = a1.y - a2.y;

	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> pt[i].x >> pt[i].y;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				ar[i][j] = 0.0;
			}
			else {
				ar[i][j] = dist(pt[i], pt[j]);
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	double ans = f(0, 1);

	cout << fixed << setprecision(7) << ans << "\n";
	return 0;

}