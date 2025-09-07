#include <iostream>
#include<vector>
#include<queue>

using namespace std;
const long long INF = 1e18;


struct Edge {int u, v; long long cost;};
int N, S, E, M;
vector<Edge> edges;
vector<long long> earn;
vector<vector<int>> adj;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N>> S>> E>> M;

    adj.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        long long cost;
        cin >> u >> v >> cost;
        edges.push_back({u, v, cost});
        adj[u].push_back(v);
    }
    earn.resize(N);
    for (int i = 0; i < N; i++) cin>>earn[i];
    vector<long long> dist(N, -INF);

    dist[S]=earn[S];

    for (int i=0;i<N-1;i++) {
        for (auto &e:edges){
            if (dist[e.u]==-INF)continue;
            long long cand = dist[e.u] - e.cost+earn[e.v];
            if (dist[e.v]<cand)dist[e.v]=cand;
        }
    }
    if (dist[E]==-INF) {
        cout<<"gg\n";
        return 0;
    }
    vector<int> cycle_nodes;
    for (auto e: edges) {
        if (dist[e.u]==-INF)continue;
        long long cand = dist[e.u] - e.cost+earn[e.v];
        if (cand>dist[e.v]) {
            cycle_nodes.push_back(e.v);
        }
    }

    if (!cycle_nodes.empty()) {
        vector<bool> visited(N,false);
        queue<int> q;

        for (int node: cycle_nodes) {
            if (!visited[node]) {
                q.push(node);
                visited[node] = true;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u==E) {
                cout<<"Gee\n";
                return 0;
            }
            for (int v :adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }


    cout<< dist[E]<<"\n";

    return 0;

}


