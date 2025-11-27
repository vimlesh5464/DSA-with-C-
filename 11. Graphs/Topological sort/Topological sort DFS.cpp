#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(int src, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s) {
        vis[src] = true;
        for(int v : adj[src]) {
            if(!vis[v]) dfs(v, adj, vis, s);
        }
        s.push(src);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> vis(V, false);
        stack<int> s;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, adj, vis, s);
        }

        vector<int> topo;
        while(!s.empty()) {
            topo.push_back(s.top());
            s.pop();
        }

        return topo;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    Solution sol;
    vector<int> topo = sol.topoSort(V, edges);

    for(int node : topo) {
        cout << node << " ";
    }
}
