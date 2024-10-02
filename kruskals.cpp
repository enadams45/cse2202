#include <bits/stdc++.h>
using namespace std;
class Disjoint {
    vector<int> rank;
    vector<int> parent;

    public:
        Disjoint(int N) {
            for(int i=0; i<N; ++i) {
                parent.push_back(i);
                rank.push_back(0);
            }
        }
        int findParent(int node) {
            if(parent[node] == node) {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            
            if(pu == pv) return;
            
            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else {
                parent[pv] = pu;
                ++rank[pu];
            }
        }
};

int main() {
    int n, e, u, v, w;
    cin >> n >> e;
    vector<tuple<int,int,int>> edges;
    for(int i=0; i<e; ++i) {
        cin >> u >> v >> w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    Disjoint ds(n);
    int mst = 0;

    for(auto [w,u,v]:edges) {
        if(ds.findParent(u) != ds.findParent(v)) {
            mst += w;
            ds.unionByRank(u,v);
        }
    }
    cout << mst << endl;
    

    return 0;
}