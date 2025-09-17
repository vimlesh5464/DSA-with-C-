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
