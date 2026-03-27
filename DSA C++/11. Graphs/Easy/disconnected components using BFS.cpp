#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;                     
    vector<list<int>> adj;     

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid edge: (" << u << ", " << v << ")\n";
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    void bfsHelper(int start, vector<bool>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void bfs() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cout << "Component: ";
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(10);  // 0–9 vertices

    g.addEdge(0, 2);
    g.addEdge(2, 5);
    g.addEdge(1, 5);
    g.addEdge(6, 4);
    g.addEdge(4, 9);
    g.addEdge(4, 3);
    g.addEdge(3, 8);
    g.addEdge(3, 7);

    cout << "BFS Traversal (Disconnected Components):\n";
    g.bfs();

    return 0;
}
