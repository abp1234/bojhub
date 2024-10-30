#include <iostream>     
#include <vector>      
#include <stack>       
#include <utility>      
#include <algorithm>  
using namespace std;

vector<vector<int>> L; 
int vis[200001], cyc[200001], par[200001]; 

pair<int, int> fc(int start) {
    stack<pair<int, int>> s;
    s.push({ start, -1 });
    while (!s.empty()) {
        pair<int, int> current = s.top(); s.pop();
        int x = current.first, y = current.second;
        if (!vis[x]) {
            vis[x] = 1;
            par[x] = y;
            for (auto i : L[x]) {
                if (i != y) {
                    if (!vis[i]) {
                        s.push({ i, x });
                    }
                    else {
                        return { i, x };
                    }
                }
            }
        }
    }
    return { 0, 0 };
}


void df(int start, int y) {
    stack<pair<int, int>> s;
    s.push({ start, y });
    while (!s.empty()) {
        pair<int, int> current = s.top(); s.pop();
        int x = current.first, parent_x = current.second;
        for (auto i : L[x]) {
            if (!cyc[i] && !vis[i]) {
                vis[i] = 1;
                par[i] = y;
                s.push({ i, y });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    L.resize(n + 1);


    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= 1 && a <= n && b >= 1 && b <= n) {
            L[a].push_back(b);
            L[b].push_back(a);
        }
    }


    fill(vis, vis + n + 1, 0);
    pair<int, int> ab = fc(1);

    if (ab.first != 0) {
        int a = ab.first, b = ab.second;
        while (a != b && b != 0) {
            cyc[b] = 1;
            b = par[b];
        }
        if (b != 0) {
            cyc[b] = 1;
        }
    }


    fill(vis, vis + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (cyc[i]) {
            vis[i] = 1;
            par[i] = i;
            df(i, i);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a >= 1 && a <= n && b >= 1 && b <= n) {
            if (par[a] == par[b]) {
                cout << "1\n";
            }
            else {
                cout << "2\n";
            }
        }
        else {
            cout << "2\n";
        }
    }
    return 0;
}
