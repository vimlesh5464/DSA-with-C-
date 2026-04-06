# 1971. Find if Path Exists in Graph.py - Python skeleton converted from C++

# Original C++ code:
# // There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
# 
# // You want to determine if there is a valid path that exists from vertex source to vertex destination.
# 
# // Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
# 
#  
# 
# // Example 1:
# 
# // Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
# // Output: true
# // Explanation: There are two paths from vertex 0 to vertex 2:
# // - 0 → 1 → 2
# // - 0 → 2
# 
# // Example 2:
# 
# // Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
# // Output: false
# // Explanation: There is no path from vertex 0 to vertex 5.
# 
#  
# 
# // Constraints:
# 
# //     1 <= n <= 2 * 105
# //     0 <= edges.length <= 2 * 105
# //     edges[i].length == 2
# //     0 <= ui, vi <= n - 1
# //     ui != vi
# //     0 <= source, destination <= n - 1
# //     There are no duplicate edges.
# //     There are no self edges.
# 
# #include <iostream>
# // #include <list>
# #include<vector>
# #include<queue>
# using namespace std;
# class Solution {
# public:
#     bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& vis) {
#         if (node == destination) return true;
#         vis[node] = true;
# 
#         for (int neigh : adj[node]) {
#             if (!vis[neigh]) {
#                 if (dfs(neigh, destination, adj, vis)) {
#                     return true;
#                 }
#             }
#         }
#         return false;
#     }
# 
#     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
#         vector<vector<int>> adj(n);
# 
#         // Build graph
#         // for (auto &e : edges) {
#         //     adj[e[0]].push_back(e[1]);
#         //     adj[e[1]].push_back(e[0]);
#         // }
#         for (vector<int> &e : edges) {
#           adj[e[0]].push_back(e[1]);
#           adj[e[1]].push_back(e[0]);
#       }
#       
# 
#         vector<bool> vis(n, false);
#         return dfs(source, destination, adj, vis);
#     }
# };
# 
# int main() {
#     int n, m;
#     cin >> n >> m;
# 
#     vector<vector<int>> edges(m, vector<int>(2));
#     for (int i = 0; i < m; i++) {
#         cin >> edges[i][0] >> edges[i][1];
#     }
# 
#     int source, destination;
#     cin >> source >> destination;
# 
#     Solution obj;
#     if (obj.validPath(n, edges, source, destination)) {
#         cout << "YES\n";
#     } else {
#         cout << "NO\n";
#     }
# 
#     return 0;
# }
# 
# 
# 
# class Solution {
# public:
#     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
#         vector<vector<int>> adj(n);
# 
#         // Build adjacency list
#         for (auto &e : edges) {
#             adj[e[0]].push_back(e[1]);
#             adj[e[1]].push_back(e[0]);  // undirected graph
#         }
# 
#         vector<bool> vis(n, false);
#         queue<int> q;
# 
#         // BFS starts
#         q.push(source);
#         vis[source] = true;
# 
#         while (!q.empty()) {
#             int node = q.front();
#             q.pop();
# 
#             if (node == destination) return true;
# 
#             for (int neigh : adj[node]) {
#                 if (!vis[neigh]) {
#                     vis[neigh] = true;
#                     q.push(neigh);
#                 }
#             }
#         }
# 
#         return false; // destination not reached
#     }
# };
# 
# int main() {
#     int n, m;
#     cin >> n >> m;
# 
#     vector<vector<int>> edges(m, vector<int>(2));
#     for (int i = 0; i < m; i++) {
#         cin >> edges[i][0] >> edges[i][1];
#     }
# 
#     int source, destination;
#     cin >> source >> destination;
# 
#     Solution obj;
#     if (obj.validPath(n, edges, source, destination)) {
#         cout << "YES\n";
#     } else {
#         cout << "NO\n";
#     }
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
