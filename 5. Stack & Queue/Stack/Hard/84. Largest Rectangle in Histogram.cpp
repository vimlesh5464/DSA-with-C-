#include<iostream>
#include<vector>
#include<stack>
using namespace std;

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
