#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(int src, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(src);  // include current node in path

        if (src == graph.size() - 1) {
            res.push_back(path);  // reached target
        } else {
            for (int neigh : graph[src]) {
                dfs(neigh, graph, path, res);  // explore neighbors
            }
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, graph, path, res); // start DFS from node 0
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> graph1 = {{1,2},{3},{3},{}};
    vector<vector<int>> res1 = sol.allPathsSourceTarget(graph1);

    cout << "All paths from source to target (Example 1):\n";
    for (auto &p : res1) {
        for (int node : p) cout << node << " ";
        cout << endl;
    }

    // Example 2
    vector<vector<int>> graph2 = {{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> res2 = sol.allPathsSourceTarget(graph2);

    cout << "\nAll paths from source to target (Example 2):\n";
    for (auto &p : res2) {
        for (int node : p) cout << node << " ";
        cout << endl;
    }

    return 0;
}
