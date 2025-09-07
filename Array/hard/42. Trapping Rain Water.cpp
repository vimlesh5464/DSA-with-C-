#include <iostream>
#include<vector>
using namespace std;
// Approach 1: Using LeftMax and RightMax Arrays Idea:
// For each element, the water trapped above it is determined by the minimum of the max height to its left and right, minus its own height.
// Precompute arrays:
// leftMax[i] = max height to the left of i (including i)
// rightMax[i] = max height to the right of i (including i)
// Calculate trapped water at each index:
// Time	O(n) → three linear passes over the array
// Space	O(n) → two extra arrays (leftMax and rightMax)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        int waterTrapped = 0;

        // Step 1: Fill leftMax array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Step 2: Fill rightMax array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Step 3: Calculate trapped water
        for (int i = 0; i < n; i++) {
            int currWater = min(leftMax[i], rightMax[i]) - height[i];
            if (currWater > 0) waterTrapped += currWater;
        }

        return waterTrapped;
    }
};

// Approach 2: Two Pointers (Optimal)
// Instead of using extra arrays, use two pointers (left and right) and keep track of leftMax and rightMax on the fly.
// Reduces space complexity to O(1).
// Time: O(n)
// Space: O(1) ✅
class Solution {
  public:
      int trap(vector<int>& height) {
          int left = 0, right = height.size() - 1;
          int leftMax = 0, rightMax = 0;
          int waterTrapped = 0;
  
          while (left <= right) {
              if (height[left] <= height[right]) {
                  if (height[left] >= leftMax) leftMax = height[left];
                  else waterTrapped += leftMax - height[left];
                  left++;
              } else {
                  if (height[right] >= rightMax) rightMax = height[right];
                  else waterTrapped += rightMax - height[right];
                  right--;
              }
          }
  
          return waterTrapped;
      }
  };
  
int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Water trapped: " << s.trap(height) << endl; // Output: 6
    return 0;
}
