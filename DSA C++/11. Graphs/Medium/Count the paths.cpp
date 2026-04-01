// Given a Directed Acyclic Graph (DAG) with V nodes labeled from 0 to V-1, and a list of directed edges, count the total number of distinct paths from a given start node to a destination node. Each edge is represented as edges[i] = [u, v], indicating a directed edge from u to v.

// Examples :

// Input: edges[][] = [[0,1], [0,3], [2,0], [2,1], [1,3]], V = 4, src = 2, dest = 3
// Output: 3
// Explanation: There are three ways to reach at 3 from 2. These are: 2 -> 1 -> 3, 2 -> 0 -> 3 and 2 -> 0 -> 1 -> 3.
// Print-all-paths-1

// Input: edges[][] = [[0,1], [1,2], [1,3], [2,3]], V = 4, src = 0, dest = 3
// Output: 2
// Explanation: There is two way to reach at 3 from 0 that is : 0 -> 1 -> 2 -> 3 and 0 -> 1 -> 3.
// Print-all-paths-2

// Constraints:
// 2  ≤  V  ≤  103
// 1  ≤   E = edges.size()  ≤  (V * (V - 1)) / 2
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    // DFS + Memoization function to count all paths from u to dest
    int dfs(int u, int dest, vector<vector<int>> &adj, vector<int> &dp) {
        if (u == dest) return 1;        // reached destination
        if (dp[u] != -1) return dp[u]; // already computed

        int count = 0;
        for (int v : adj[u]) {
            count += dfs(v, dest, adj, dp);
        }

        return dp[u] = count; // store in dp and return
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // 1. Build adjacency list from edges
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v); // directed graph
        }

        // 2. Initialize DP array with -1
        vector<int> dp(V, -1);

        // 3. Start DFS from source
        return dfs(src, dest, adj, dp);
    }
};

// Example usage
int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,3}};
    int src = 0, dest = 3;

    cout << "Number of paths: " << sol.countPaths(edges, V, src, dest) << endl;
    // Output: 2 (paths: 0->1->3 and 0->2->3)

    return 0;
}
