#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;            // number of vertices
    list<int> *l;     // adjacency list (array of lists)

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];   // create adjacency list
    }

    void addEdge(int u, int v, bool undirected = true) {
        l[u].push_back(v);
        if (undirected) {
            l[v].push_back(u);
        }
    }

    void bfs(int start) {
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int nbr : l[u]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
    }

    ~Graph() {
        delete[] l; // free memory
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS starting from node 0: ";
    g.bfs(0);

    return 0;
}
