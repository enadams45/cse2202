#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define inf 1e7

void dijkstra(vector<vector<pair<int,int>>> &adj_list, int source, vector<int> &distance) {
    set<pair<int,int>> s;
    s.insert({0, source});
    while(!s.empty()) {
        auto set_Element = *(s.begin());
        s.erase(set_Element);
        for(auto neighbour : adj_list[set_Element.second]) {
            if(distance[neighbour.first] > distance[set_Element.second] + neighbour.second) {
                s.erase({distance[neighbour.first], neighbour.first});
                distance[neighbour.first] = distance[set_Element.second] + neighbour.second;
                s.insert({distance[neighbour.first], neighbour.first});
            }
        }
    }
    for(int i=0; i<adj_list.size(); ++i) {
        cout << distance[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, e, u, v, w;
    cin >> n >> e;
    vector<int>distance(n, inf);
    vector<vector<pair<int,int>>> adj_list(n);
    for(int i=0; i<e; ++i) {
        cin >> u >> v >> w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    cout << "Enter source : ";
    int source; cin >> source;
    distance[source] = 0;
    dijkstra(adj_list, source, distance);
    
    return 0;
}