#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>>&edges, int n) {
    const int inf = 1e9;
    vector<vector<int>> dist(n,vector<int>(n,inf));
    for(auto edge:edges) {
        dist[edge[0]][edge[1]] = edge[2];
    }
    for(int i=0; i<n; ++i) {
        dist[i][i] = 0;
    }
    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j)  {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0; i<n; ++i) {
        if(dist[i][i]<0) {
            cout << "Negative cycle detected!" << endl;
            return;
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n = 3;
    vector<vector<int>> edges = {
        {0, 1, 1}, 
        {1, 2, -1}, 
        {2, 0, -1}
    };
    floyd_warshall(edges, n);
    return 0;
}
