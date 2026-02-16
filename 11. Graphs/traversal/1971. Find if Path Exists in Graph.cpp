#include <iostream>
// #include <list>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& vis) {
        if (node == destination) return true;
        vis[node] = true;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, destination, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        // Build graph
        // for (auto &e : edges) {
        //     adj[e[0]].push_back(e[1]);
        //     adj[e[1]].push_back(e[0]);
        // }
        for (vector<int> &e : edges) {
          adj[e[0]].push_back(e[1]);
          adj[e[1]].push_back(e[0]);
      }
      

        vector<bool> vis(n, false);
        return dfs(source, destination, adj, vis);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;
    cin >> source >> destination;

    Solution obj;
    if (obj.validPath(n, edges, source, destination)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}



class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);  // undirected graph
        }

        vector<bool> vis(n, false);
        queue<int> q;

        // BFS starts
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) return true;

            for (int neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }

        return false; // destination not reached
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;
    cin >> source >> destination;

    Solution obj;
    if (obj.validPath(n, edges, source, destination)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
