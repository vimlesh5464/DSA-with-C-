#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
    // Topological sort helper
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &s) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, s);
            }
        }
        s.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // adjacency list with weights
        vector<pair<int,int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Step 1: Topological Sort
        stack<int> s;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, s);
            }
        }

        // Step 2: Initialize distances
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;   // source is node 0

        // Step 3: Relax edges in topo order
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            if (dist[u] != INT_MAX) {
                for (auto it : adj[u]) {
                    int v = it.first;
                    int w = it.second;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        // Step 4: Convert unreachable -> -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};

int main() {
    int V = 6, E = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    Solution obj;
    vector<int> ans = obj.shortestPath(V, E, edges);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << ans[i] << "\n";
    }

    return 0;
}
