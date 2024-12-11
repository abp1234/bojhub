#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int solve(int n) {
    if (n % 3 != 0) return 0;
    vector<int> dp(n + 1, 0);
    dp[1] = 2;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; ++i) {
        if (i % 3 == 1) {
            dp[i] = (dp[i - 1] * 2LL + dp[i - 3]) % MOD;
        }
        else {
            dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
        }
    }
    return (dp[n] + MOD) % MOD;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
