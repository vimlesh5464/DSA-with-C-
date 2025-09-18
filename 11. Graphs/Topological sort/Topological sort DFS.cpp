#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Solution {
public:
    // DFS helper
    void dfs(int src, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s) {
        vis[src] = true;
        for(int v : adj[src]) {
            if(!vis[v]) {
                dfs(v, adj, vis, s);
            }
        }
        s.push(src);
    }

    // Function to return topological order
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); // u -> v
        }

        // Step 2: DFS to get topological order
        vector<bool> vis(V, false);
        stack<int> s;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, s);
            }
        }

        // Step 3: Pop stack into result vector
        vector<int> topo;
        while(!s.empty()) {
            topo.push_back(s.top());
            s.pop();
        }

        return topo;
    }
};

int main() {
    // Example usage
    int V = 6;
    vector<vector<int>> edges = {
        {5, 0}, {5, 2},
        {4, 0}, {4, 1},
        {2, 3}, {3, 1}
    };

    Solution sol;
    vector<int> topo = sol.topoSort(V, edges);

    cout << "Topological Sort: ";
    for(int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
