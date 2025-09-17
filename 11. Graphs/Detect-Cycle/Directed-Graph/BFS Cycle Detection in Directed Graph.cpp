#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed graph
    }

    bool bfsCycle(int src, vector<int>& state) {
        queue<int> q;
        q.push(src);
        state[src] = 1; // currently in path

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (state[nbr] == 0) {
                    state[nbr] = 1; // mark as in path
                    q.push(nbr);
                } 
                else if (state[nbr] == 1) {
                    // back edge found → cycle
                    return true;
                }
            }
            state[node] = 2; // fully processed
        }
        return false;
    }

    bool containsCycle() {
        vector<int> state(V, 0); // 0 = unvisited, 1 = in path, 2 = done

        for (int i = 0; i < V; i++) {
            if (state[i] == 0) {
                if (bfsCycle(i, state))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // cycle here

    if (g.containsCycle())
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}
