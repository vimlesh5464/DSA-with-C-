# 802. Find Eventual Safe States.py - Python skeleton converted from C++

# Original C++ code:
# // There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
# 
# // A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
# 
# // Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
# 
#  
# 
# // Example 1:
# // Illustration of graph
# 
# // Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
# // Output: [2,4,5,6]
# // Explanation: The given graph is shown above.
# // Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
# // Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
# 
# // Example 2:
# 
# // Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
# // Output: [4]
# // Explanation:
# // Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
# 
#  
# 
# // Constraints:
# 
# //     n == graph.length
# //     1 <= n <= 104
# //     0 <= graph[i].length <= n
# //     0 <= graph[i][j] <= n - 1
# //     graph[i] is sorted in a strictly increasing order.
# //     The graph may contain self-loops.
# //     The number of edges in the graph will be in the range [1, 4 * 104].
# 
# #include <iostream>
# #include <vector>
# #include <queue>
# using namespace std;
# class Solution {
# public:
#     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
#         int V = graph.size();  // Number of nodes
# 
#         // Reverse graph adjacency list
#         vector<vector<int>> adjRev(V);
#         vector<int> indegree(V, 0);
# 
#         // Build reversed graph and indegree
#         for (int i = 0; i < V; i++) {
#             for (auto it : graph[i]) {
#                 adjRev[it].push_back(i);  // reverse edge
#                 indegree[i]++;            // increase indegree
#             }
#         }
# 
#         // Kahn’s Algorithm (Topological Sort BFS)
#         queue<int> q;
#         vector<int> safeNodes;
#         for (int i = 0; i < V; i++) {
#             if (indegree[i] == 0) {  // terminal nodes become sources in reversed graph
#                 q.push(i);
#             }
#         }
# 
#         while (!q.empty()) {
#             int node = q.front();
#             q.pop();
#             safeNodes.push_back(node);
# 
#             for (auto it : adjRev[node]) {
#                 indegree[it]--;
#                 if (indegree[it] == 0) {
#                     q.push(it);
#                 }
#             }
#         }
# 
#         sort(safeNodes.begin(), safeNodes.end());
#         return safeNodes;
#     }
# };
# 
# // Example usage
# int main() {
#     Solution sol;
# 
#     // Example graph: 0->1, 0->2, 1->2, 2->3, 3->4, 4->2
#     vector<vector<int>> graph = {
#         {1, 2},  // 0
#         {2},     // 1
#         {3},     // 2
#         {4},     // 3
#         {2}      // 4 (cycle 2 -> 3 -> 4 -> 2)
#     };
# 
#     vector<int> safeNodes = sol.eventualSafeNodes(graph);
# 
#     cout << "Safe nodes: ";
#     for (int node : safeNodes) {
#         cout << node << " ";
#     }
#     cout << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
