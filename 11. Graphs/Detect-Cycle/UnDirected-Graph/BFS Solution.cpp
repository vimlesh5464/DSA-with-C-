#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class Solution {
  public:
    // BFS to detect cycle
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int,int>> q; // {node, parent}
        q.push({start, -1});
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push({nbr, node});
                }
                else if (nbr != parent) {
                    // visited neighbor that's not parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        // Check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    cout << (sol.isCycle(V, edges) ? "true" : "false") << endl;
    return 0;
}
