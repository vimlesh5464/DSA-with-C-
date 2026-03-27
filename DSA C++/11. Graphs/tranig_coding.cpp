#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph {
public:
    int n; 
    vector<vector<int>> adj;

    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   // Undirected graph
    }

    vector<int> bfs(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        vector<int> order;

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(int neigh : adj[node]) {
                if(!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return order;
    }
};

int main() {

    int n, m;
    cin >> n >> m;        // ← coding test me input ALWAYS yahi aata hai

    Graph g(n);

    // m lines of edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cin >> start;         // starting node for BFS

    vector<int> result = g.bfs(start);

    for(int x : result) cout << x << " ";
}
