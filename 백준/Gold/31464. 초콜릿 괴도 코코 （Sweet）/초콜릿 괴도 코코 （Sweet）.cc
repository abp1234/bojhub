#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct UnionFind {
    vector<int> parent;
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
   
    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        parent[pb] = pa;
        return true;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    vector<int>id(N*N, -1);
    int V =0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#') {
                id[i*N+j] = V++;
            }
        }
    }

    vector<pair<int, int>> Coords(V);
    vector<pair<int, int>> edges;

    int dx[4] ={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#') {
                int cur = id[i*N+j];
                Coords[cur] = {i,j};
                for (int d = 0; d < 4; d++) {
                    int ni =i + dx[d],nj=j+dy[d];
                    if (ni>=0&&ni<N&&nj>=0&&nj<N&&grid[ni][nj] == '#') {
                        int nb = id[ni*N+nj];
                        if (cur<nb) {
                            edges.push_back({cur,nb});
                        }
                    }
                }
            }
        }
    }

    vector<pair<int,int>> candidates;

    for (int v =0; v < V; v++) {
        UnionFind uf(V);
        int addedEdges = 0;
        bool cycleFound = false;

        for (auto &e : edges) {
            int u = e.first, w = e.second;
            if (u == v || w == v)continue;
            if (!uf.unite(u, w)) {
                cycleFound = true;
                break;
            }
            addedEdges++;
        }

        if (cycleFound || addedEdges != V-2) continue;

        int comp = -1;
        bool connected = true;
        for (int i = 0; i < V; i++) {
            if (i==v)continue;
            int root = uf.find(i);
            if (comp==-1)comp = root;
            else if (comp!= root){connected=false;break;}

        }
        if (!connected)continue;

        int r = Coords[v].first+1;
        int c = Coords[v].second+1;
        candidates.push_back({r,c});
    }

    sort(candidates.begin(), candidates.end());
    cout<<candidates.size()<<"\n";
    for (auto &e : candidates)
        cout<<e.first<<" "<<e.second<<"\n";
    return 0;


}