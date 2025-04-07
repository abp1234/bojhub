

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;



int find_parent(vector<int> &parents, int i) {
    if (parents[i]==i)
        return i;
    return parents[i]=find_parent(parents,parents[i]);
}
void union_sets(vector<int>& parents, int a, int b) {
    int a_parent = find_parent(parents,a);
    int b_parent = find_parent(parents,b);

    if (a_parent != b_parent)
        parents[b_parent]=a_parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        int m,n;
        cin>> m>>n;
        if(m==0 && n==0)
            break;

        int x,y,z;
        vector<tuple<int,int,int>> roads;
        long long totalCost=0;

        for(int i=0;i<n;i++) {
            cin>>x>>y>>z;
            roads.push_back(make_tuple(z,x,y));
            totalCost+=z;
        }
        vector<int>parents;
        for (int i=0;i<n;i++) {
            parents.push_back(i);
        }
        sort(roads.begin(),roads.end());

        long long mstCost=0;
        int cost, a, b;
        for(int i=0;i<n;i++) {
            tie(cost, a, b)=roads[i];
            if (find_parent(parents,a)!=find_parent(parents,b)) {
                mstCost+=cost;
                union_sets(parents,a,b);
            }
        }

        cout<<totalCost-mstCost<<"\n";
    }

    return 0;
}
