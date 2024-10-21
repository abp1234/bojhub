#include <iostream>
#include <vector>
#include <string>
using namespace std;
const long long INF = 1e18; 

struct C {
    long long comb[201][201];
};


void calcComb(C* c, int lim) {
    c->comb[0][0] = 1;
    for (int i = 1; i <= lim; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                c->comb[i][j] = 1;
            }
            else {
           
                c->comb[i][j] = min(c->comb[i - 1][j - 1] + c->comb[i - 1][j], INF);
            }
        }
    }
}

int main() {
    int n, m;
    long long k; 
    cin >> n >> m >> k;

    C* c = new C();
    calcComb(c, n + m); 

   
    if (c->comb[n + m][n] < k) {
        cout << -1 << '\n';
        delete c;
        return 0;
    }

    string ans = "";
    int la = n;
    long long lk = k;


    for (int i = m - 1; i >= 0; --i) {
        for (int j = la; j >= 0; --j) {
        
            if (c->comb[la - j + i][la - j] < lk) {
                lk -= c->comb[la - j + i][la - j];
            }
            else {
                ans += string(j, 'a');
                la -= j;
                break;
            }
        }
        ans += 'z';
    }


    ans += string(la, 'a');
    cout << ans << '\n';

    delete c; 
    return 0;
}