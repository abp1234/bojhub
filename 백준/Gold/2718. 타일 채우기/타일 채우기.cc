#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int MAX_N = 16;  

int N;  
int DP[100][MAX_N];  
unordered_map<int, unordered_set<int>> g;

void dfs(int n, int cur) {
    if (n == N - 1) { 
        if (g[cur].count(0)) {
            DP[n][cur] = 1;
        }
        return;
    }
    for (int nxt : g[cur]) {  
        if (!DP[n + 1][nxt]) {
            dfs(n + 1, nxt); 
        }
        DP[n][cur] += DP[n + 1][nxt]; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; 

    while (T--) {
        cin >> N;  

        fill(&DP[0][0], &DP[0][0] + sizeof(DP) / sizeof(int), 0);

        g.clear();
        g[0] = { 0, 3, 9, 12, 15 };
        g[3] = { 0, 12 };
        g[6] = { 9 };
        g[9] = { 0, 6 };
        g[12] = { 0, 3 };
        g[15] = { 0 };

        dfs(0, 0);

        cout << DP[0][0] << '\n';
    }

    return 0;
}
