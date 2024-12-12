#include <bits/stdc++.h>
using namespace std;

#define inf 1e9

void johnson(vector<vector<int>> &edges, int n) {
    vector<vector<pair<int, int>>> adj_list(n);
    vector<int> h(n + 1, 0);
    vector<vector<int>> dist(n, vector<int>(n, inf));


    // Add a new node `n` connected to all other nodes with 0 weight
    vector<vector<int>> temp_edges = edges;
    for (int i = 0; i < n; ++i) {
        temp_edges.push_back({n, i, 0});
    }

    // Bellman-Ford to find h values
    for (int i = 0; i < n; ++i) {
        h[i] = inf;
    }
    h[n] = 0;

    for (int i = 0; i < n; ++i) {
        for (auto it : temp_edges) {
            int u = it[0], v = it[1], w = it[2];
            if (h[u] != inf && h[u] + w < h[v]) {
                h[v] = h[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (auto it : temp_edges) {
        int u = it[0], v = it[1], w = it[2];
        if (h[u] != inf && h[u] + w < h[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Reweight edges
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        edge[2] = w + h[u] - h[v];
    }

    for (auto edge : edges) {
        adj_list[edge[0]].push_back({edge[1], edge[2]});
    }

    // Dijkstra for each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        pq.push({0, i});
        vector<int> local_dist(n, inf);
        local_dist[i] = 0;

        while (!pq.empty()) {
            auto [node_dis, node] = pq.top();
            pq.pop();
            if (node_dis > local_dist[node]) continue;

            for (auto [neighbour, weight] : adj_list[node]) {
                int new_dis = node_dis + weight;
                if (new_dis < local_dist[neighbour]) {
                    pq.push({new_dis, neighbour});
                    local_dist[neighbour] = new_dis;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            if (local_dist[j] < inf) {
                dist[i][j] = local_dist[j] + h[j] - h[i];
            }
        }
    }

    // Output the distance matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == inf) {
                cout << "inf ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    int u, v, w;
    vector<vector<int>> edges;
    for (int i = 0; i < e; ++i) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    cout << endl;
    johnson(edges, n);

    return 0;
}
