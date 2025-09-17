#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;                     // number of vertices
    vector<list<int>> adj;     // adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   // for undirected graph
    }

    void dfsHelper(int u, vector<bool>& vis) {
        vis[u] = true;
        cout << u << " ";      // process node

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsHelper(i, vis);
            }
        }
    }
};

int main() {
    Graph g(10);

    g.addEdge(0, 2);
    g.addEdge(2, 5);
    g.addEdge(1, 5);
    g.addEdge(6, 4);
    g.addEdge(4, 9);
    g.addEdge(4, 3);
    g.addEdge(3, 8);
    g.addEdge(3, 7);

    cout << "DFS Traversal: ";
    g.dfs();

    return 0;
}
