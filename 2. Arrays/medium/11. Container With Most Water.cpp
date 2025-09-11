// 🔹 Approaches
// 1. Brute Force (Check All Pairs)
// Check all pairs of lines (i, j) and calculate area: area = min(height[i], height[j]) * (j - i).
// Track maximum area.
// Time Complexity: O(n²)
// Space Complexity: O(1)
#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

// 2. Two Pointer Approach (Optimal) ✅Idea:
// Use two pointers, one at the start i and one at the end j.
// Calculate area: area = min(height[i], height[j]) * (j - i)
// Move the pointer pointing to the smaller height, because moving the larger height won’t increase area.
// Repeat until pointers meet.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
      int maxArea(vector<int>& height) {
          int i = 0, j = height.size() - 1;
          int maxArea = 0;
  
          while(i < j) {
              int area = min(height[i], height[j]) * (j - i);
              maxArea = max(maxArea, area);
  
              // Move the pointer pointing to smaller height
              if(height[i] < height[j]) i++;
              else j--;
          }
  
          return maxArea;
      }
  };
int main() {
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max Area: " << s.maxArea(height) << endl;
    return 0;
}
