#include <iostream>
#include<vector>
#include <queue> 
#include <utility> 
using namespace std;


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        
        // Min-heap: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<bool> mst(V, false);  // Track nodes included in MST
        pq.push({0, 0});  // Start from node 0 with cost 0

        int minCost = 0;
        int edgesUsed = 0;

        while (!pq.empty() && edgesUsed < V) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (mst[u]) continue;  // Skip if already in MST
            mst[u] = true;
            minCost += cost;
            edgesUsed++;

            // Push edges from u to all other not-yet-included nodes
            for (int v = 0; v < V; ++v) {
                if (!mst[v]) {
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({wt, v});
                }
            }
        }
        
        return minCost; 
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    cout << "Minimum Cost to Connect Points: " << sol.minCostConnectPoints(points) << endl;
    return 0;
}

