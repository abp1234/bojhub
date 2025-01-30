#include<iostream>

using namespace std;
typedef long long ll;

const ll P = 1000000007;

ll pw(ll b, ll e) {
	ll r = 1;
	while (e > 0) {
		if (e % 2 == 1)r = (r * b) % P;
		b = (b * b) % P;
		e /= 2;
	}
	return r;
}

ll cmb(ll n, ll r) {
	if (r == 0 || r == n) return 1;
	ll nm = 1, dn = 1;
	for (ll i = n - r + 1; i <= n; ++i)nm = (nm * i) % P;
	for (ll i = 1; i <= r; ++i)dn = (dn * i) % P;
	return (nm * pw(dn, P - 2)) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, r;
	cin >> n >> r;

	cout << cmb(n, r) << "\n";
	return 0;
}