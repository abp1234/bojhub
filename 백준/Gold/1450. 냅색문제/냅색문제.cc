#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;

vector<vector<ll>> compute_binom(int n) {
    vector<vector<ll>> binom(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0)
                binom[i][j] = 1;
            else
                binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    return binom;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll C;
    cin >> N>>C;
    vector<int> wg(N);
    for (int i = 0; i < N; i++) {
        cin>>wg[i];
    }

    sort(wg.begin(), wg.end());

    ll SumCntMin = wg[0], SumCntMax = wg[N-1];
    int checkPointMin = (wg[0] > C ? 1 : N + 1);
    int checkPointMax = (wg[N-1] > C ? 1 : N + 1);

    if (N>1) {
        for (int i = 1; i < N; i++) {
            if (checkPointMin == N + 1) {
                SumCntMin += wg[i];
                if (SumCntMin > C)
                    checkPointMin = i + 1;
            }
            if (checkPointMax == N + 1) {
                SumCntMax += wg[N - 1 - i];
                if (SumCntMax > C)
                    checkPointMax = i + 1;
            }
        }
    }

    vector<vector<ll>> binom = compute_binom(N);

    ll ans = 0;

    int n1 = N /2;
    int n2 = N - n1;
    vector<int> group1(wg.begin(), wg.begin() + n1);
    vector<int> group2(wg.begin() + n1, wg.end());

    vector<vector<ll>> sums1(n1+1);
    int total1 = 1<<n1;
    for (int mask = 0; mask <total1; mask++) {
        int cnt = __builtin_popcount(mask);
        ll s =0;
        for (int i = 0; i < n1; i++) {
            if (mask & (1<<i))
                s += group1[i];
        }
        sums1[cnt].push_back(s);
    }

    vector<vector<ll>> sums2(n2+1);
    int total2 = 1<<n2;
    for (int mask = 0; mask <total2; mask++) {
        int cnt = __builtin_popcount(mask);
        ll s =0;
        for (int i = 0; i < n2; i++) {
            if (mask & (1<<i))
                s += group2[i];
        }
        sums2[cnt].push_back(s);
    }

    for (int j =0;j<=n2;j++) {
        sort(sums2[j].begin(), sums2[j].end());
    }

    for (int k = 0; k<=N;k++) {
        if (k<checkPointMax) {
            ans+=binom[N][k];
        }else if (k>=checkPointMin) {
            continue;
        }else {
            ll cnt_val=0;
            int start = max(0, k-n2);
            int end = min(k,n1);
            for (int j = start; j <= end; j++) {
                int need = k - j;
                for (ll s1 : sums1[j]) {
                    ll remain = C -s1;
                    int cnt = upper_bound(sums2[need].begin(), sums2[need].end(), remain)-sums2[need].begin();
                    cnt_val += cnt;
                }
            }
            ans += cnt_val;
        }
    }
    cout << ans << "\n";
    return 0;
}
