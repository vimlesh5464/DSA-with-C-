// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:

// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.

// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18

 

// Constraints:

//     1 <= points.length <= 1000
//     -106 <= xi, yi <= 106
//     All pairs (xi, yi) are distinct.

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

