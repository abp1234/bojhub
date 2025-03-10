#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;


long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) 
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int k, n;
        cin >> k >> n;
        long long sum = 0;
        for(int i = 0; i < n+1; i++){
            long long a;
            cin >> a;
            sum = (sum + a) % MOD;
        }
        if(sum < 0)
            sum += MOD;
        cout << modExp(sum, k, MOD) << "\n";
    }
    return 0;
}
