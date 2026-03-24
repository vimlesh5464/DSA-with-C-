// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:

// Input: heights = [2,4]
// Output: 4

 

// Constraints:

//     1 <= heights.length <= 105
//     0 <= heights[i] <= 104

#include <iostream>
#include<vector>
#include<stack>
using namespace std;
// Brute-force Approach Idea:
// For each bar heights[i], expand left and right until a smaller bar is found.
// Calculate the width and area using heights[i] as the rectangle height:
// Time	O(n²) → for each bar, scan left and right
// Space	O(1) → no extra space
class Solution {
  public:
      int largestRectangleArea(vector<int>& heights) {
          int n = heights.size();
          int maxArea = 0;
  
          for(int i = 0; i < n; i++){
              int height = heights[i];
  
              // Find left boundary
              int left = i;
              while(left >= 0 && heights[left] >= height) left--;
  
              // Find right boundary
              int right = i;
              while(right < n && heights[right] >= height) right++;
  
              // Calculate area
              int width = right - left - 1;
              int area = height * width;
              maxArea = max(maxArea, area);
          }
  
          return maxArea;
      }
  };

// Approach2: NSL + NSR (Stack-based)
// Idea:
// For each bar, find the Next Smaller element to Left (NSL) and Next Smaller element to Right (NSR).
// Width of rectangle with current bar as height:
// Time	O(n) → each element pushed/popped at most once in stack
// Space	O(n) → for NSL, NSR arrays and stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n); // Next Smaller Left
        vector<int> nsr(n); // Next Smaller Right
        stack<int> s;

        // Compute NSL
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            nsl[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for NSR
        while(!s.empty()) s.pop();

        // Compute NSR
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            nsr[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Compute max area
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = nsr[i] - nsl[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << s.largestRectangleArea(heights) << endl; // Output: 10
    return 0;
}
