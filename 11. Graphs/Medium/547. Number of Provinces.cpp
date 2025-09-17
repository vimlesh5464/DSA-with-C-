#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    // DFS to explore all connected nodes (province)
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;  // mark node as visited
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;             // new province found
                dfs(i, isConnected, visited); // mark all connected nodes
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example: 3 cities, 2 provinces
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int provinces = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl; 
    // Output: 2

    return 0;
}
