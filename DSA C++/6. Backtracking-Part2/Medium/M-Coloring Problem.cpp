// You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

// Note: The graph is indexed with 0-based indexing.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
// Output: true
// Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

// Vertex 0: Color 1
// Vertex 1: Color 2
// Vertex 2: Color 2
// Vertex 3: Color 3

// Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
// Output: false
// Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.

// Constraints:
// 1 ≤ V ≤ 10
// 1 ≤ E = edges.size() ≤ (V*(V-1))/2
// 0 ≤ edges[i][j] ≤ V-1
// 1 ≤ m ≤ V
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
