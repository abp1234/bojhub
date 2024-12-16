#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct St {
	int* d1;
	int* d2;
};

void init(St& st, int n) {
	st.d1 = new int[n];
	st.d2 = new int[n];
	memset(st.d1, 0, n * sizeof(int));
	memset(st.d2, 0, n * sizeof(int));
}

void cleanup(St& st) {
	delete[] st.d1;
	delete[] st.d2;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<int> ar(n);
	for (int& x : ar) cin >> x;

	St st;
	init(st, n);

	int ans = 0;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (ar[j] > ar[i]) {
				st.d2[i] = max(st.d2[i], st.d2[j]);
			}
			else {
				st.d1[i] = max(st.d1[i], st.d1[j]);
			}
		}
		st.d1[i] += 1;
		st.d2[i] += 1;
		ans = max(ans, st.d1[i] + st.d2[i] - 1);
	}
	cout << ans << '\n';

	cleanup(st);
	return 0;
}