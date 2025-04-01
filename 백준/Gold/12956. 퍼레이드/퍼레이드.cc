#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, time, idx;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;


    vector<vector<Edge>> tour(N);
    vector<vector<int>> road(M, vector<int>(3, 0));

    for (int i = 0; i < M; i++){
        int from, to, time;
        cin >> from >> to >> time;

        road[i][0] = from;
        road[i][1] = to;
        road[i][2] = time;
        tour[from].push_back({to, time, i});
        tour[to].push_back({from, time, i});
    }


    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<vector<long long>> ways(N, vector<long long>(N, 0));


    for (int s = 0; s < N; s++){

        vector<int> vis(N, INF);
        vector<long long> fromCnt(N, 0);
        vis[s] = 0;
        fromCnt[s] = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, s});

        while(!pq.empty()){
            auto [cur, u] = pq.top();
            pq.pop();
            if(cur > vis[u]) continue;
            for(auto edge : tour[u]){
                int v = edge.to, t = edge.time;
                if(vis[v] > vis[u] + t){
                    vis[v] = vis[u] + t;
                    fromCnt[v] = fromCnt[u];
                    pq.push({vis[v], v});
                }
                else if(vis[v] == vis[u] + t){
                    fromCnt[v] += fromCnt[u];
                }
            }
        }
        dist[s] = vis;
        ways[s] = fromCnt;
    }

    vector<int> returnAns(M, 0);


    for (int s = 0; s < N; s++){
        for (int t = s + 1; t < N; t++){
            int targetCost = dist[s][t];
            long long totWays = ways[s][t];

            for (int r = 0; r < M; r++){
                int from = road[r][0], to = road[r][1], time = road[r][2];
                bool aff = false;

                if(targetCost == dist[s][from] + time + dist[to][t] &&
                   totWays == ways[s][from] * ways[to][t])
                    aff = true;

                if(targetCost == dist[s][to] + time + dist[from][t] &&
                   totWays == ways[s][to] * ways[from][t])
                    aff = true;
                if(aff)
                    returnAns[r]++;
            }
        }
    }


    for (int i = 0; i < M; i++){
        cout << returnAns[i] << " ";
    }
    cout << "\n";

    return 0;
}