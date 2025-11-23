#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& adj, int col) {
        // Check adjacent vertices
        for (auto it : adj[node]) {
            if (color[it] == col) return false;
        }
        return true;
    }

    bool solve(int node, vector<vector<int>>& adj, int m, int V, vector<int>& color) {
        // All vertices are colored
        if (node == V) return true;

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, adj, col)) {
                color[node] = col;
                if (solve(node + 1, adj, m, V, color)) return true;
                color[node] = 0; // backtrack
            }
        }
        return false;
    }

public:
    bool graphColoring(int V, vector<vector<int>>& edges, int m) {
        // Create adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> color(V, 0);
        return solve(0, adj, m, V, color);
    }
};

int main() {
    Solution s;

    int V = 4, m = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};
    cout << (s.graphColoring(V, edges, m) ? "true" : "false") << endl;

    V = 3, m = 2;
    edges = {{0, 1}, {1, 2}, {0, 2}};
    cout << (s.graphColoring(V, edges, m) ? "true" : "false") << endl;

    return 0;
}
