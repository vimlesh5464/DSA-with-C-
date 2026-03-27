#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();  // Number of nodes

        // Reverse graph adjacency list
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);

        // Build reversed graph and indegree
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);  // reverse edge
                indegree[i]++;            // increase indegree
            }
        }

        // Kahn’s Algorithm (Topological Sort BFS)
        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {  // terminal nodes become sources in reversed graph
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

// Example usage
int main() {
    Solution sol;

    // Example graph: 0->1, 0->2, 1->2, 2->3, 3->4, 4->2
    vector<vector<int>> graph = {
        {1, 2},  // 0
        {2},     // 1
        {3},     // 2
        {4},     // 3
        {2}      // 4 (cycle 2 -> 3 -> 4 -> 2)
    };

    vector<int> safeNodes = sol.eventualSafeNodes(graph);

    cout << "Safe nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
