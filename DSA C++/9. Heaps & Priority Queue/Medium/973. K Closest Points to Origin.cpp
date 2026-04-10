// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

// Example 1:

// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.

 

// Constraints:

//     1 <= k <= points.length <= 104
//     -104 <= xi, yi <= 104



#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> dist;

        // Step 1: Calculate distance
        for (auto &p : points) {
            int d = p[0]*p[0] + p[1]*p[1];
            dist.push_back({d, p});
        }

        // Step 2: Sort
        sort(dist.begin(), dist.end());

        // Step 3: Take first k
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(dist[i].second);
        }

        return result;
    }
};
class Solution {
  public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  
          sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
              int d1 = a[0]*a[0] + a[1]*a[1];
              int d2 = b[0]*b[0] + b[1]*b[1];
              return d1 < d2;
          });
  
          // return first k elements
          return vector<vector<int>>(points.begin(), points.begin() + k);
      }
  };

  class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            
            // Max Heap: (distance, point)
            priority_queue<pair<int, vector<int>>> maxHeap;
    
            for (auto &p : points) {
                int d = p[0]*p[0] + p[1]*p[1];
    
                maxHeap.push({d, p});
    
                // Maintain size k
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
    
            // Extract result
            vector<vector<int>> result;
            while (!maxHeap.empty()) {
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
    
            return result;
        }
    };