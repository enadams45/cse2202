#include <bits/stdc++.h>
using namespace std;

void bellman(vector<vector<int>>& edges, int n, int source) {
    vector<int> dist(n,1e7);
    dist[source] = 0;
    for(int i=0; i<n-1; ++i) {
        for(auto &edge : edges) {
            int u = edge[0], v=edge[1], weight = edge[2];
            int new_dis = dist[u]+weight;
            if(new_dis < dist[v]) {
                dist[v] = new_dis;
            }
        }
    }
    for(auto &edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if(dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
    for(int i=0; i<n; ++i) {
        cout << "Vertex " << i << " : distance " << dist[i] << endl;
    }
}

int main() {
    int n, e, u, v;
    vector<vector<int>> edges(e,vector<int>(3,0));
    cin >> n >> e;
    for(int i=0; i<e; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    bellman(edges, n, 0);

    return 0;
}