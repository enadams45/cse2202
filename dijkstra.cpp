#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;

void dijkstra(vector<vector<pair<int,int>>>&adj_list, int source) {
    int n = adj_list.size();
    vector<int>dist(n,inf);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,source});
    dist[source] = 0; //{distance,source}

    while(!pq.empty()) {
        auto [nodeDist, node] = pq.top();
        pq.pop();
        for(auto [nei, neiWeight]:adj_list[node]) {
            int newDist = neiWeight+nodeDist;
            if(newDist < dist[nei]) {
                dist[nei] = newDist;
                pq.push({newDist,nei});
            }
        }

    }
    for(int i=0; i<n; ++i) {
        if (dist[i] == inf) {
            cout << "INF "; // Use INF for unreachable nodes
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

}

int main() {
    int n, e, u, v, w;
    cin >> n >> e;
    vector<vector<pair<int,int>>> adj_list(n);
    for(int i=0; i<e; ++i) {
        cin >> u >> v >> w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }

    dijkstra(adj_list, 0);


    return 0;
}