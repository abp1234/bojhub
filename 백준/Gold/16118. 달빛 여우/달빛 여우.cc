#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int a, b, d;
    cin >> N >> M;
    vector<vector<pair<int,int>>> tree(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> d;
        a--; b--;  
        tree[a].emplace_back(b, d * 2);
        tree[b].emplace_back(a, d * 2);
    }


    vector<int> wolf(N, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    wolf[0] = 0;
    pq.emplace(0, 0);

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        for (auto [next, w] : tree[cur]) {
            if (wolf[next] > cost + w) {
                wolf[next] = cost + w;
                pq.emplace(wolf[next], next);  
            }
        }
    }

    
    vector<vector<int>> fox(N, vector<int>(2, INF));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq2;
    fox[0][0] = 0;
    pq2.emplace(0, 0, 0);

    while(!pq2.empty()) {
        auto [cost, cur, state] = pq2.top();
        pq2.pop();
        if (cost > fox[cur][state]) continue;

        for (auto [next, w] : tree[cur]) {
            int ncost;
            int nstate = 1 - state;
            if (state == 0)
                ncost = cost + w / 2;
            else
                ncost = cost + w * 2;
            if (fox[next][nstate] > ncost) {
                fox[next][nstate] = ncost;
                pq2.emplace(ncost, next, nstate);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i < N; i++) {  
        if (wolf[i] < min(fox[i][0], fox[i][1])) cnt++;

    }

    cout << cnt << "\n";

    return 0;
}
