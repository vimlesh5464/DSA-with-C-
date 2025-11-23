#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
      int countHillValley(vector<int>& nums) {
          int count = 0;
          int n = nums.size();
  
          for (int i = 1; i < n - 1; ++i) {
              // Skip duplicates by checking left and right of current i
              if (nums[i] == nums[i - 1]) continue;
  
              int left = i - 1;
              int right = i + 1;
  
              // Skip all equal elements to the right
              while (right < n && nums[right] == nums[i]) {
                  right++;
              }
  
              // Check if both left and right are valid
              if (right < n) {
                  if (nums[i] > nums[left] && nums[i] > nums[right]) {
                      count++; // Hill
                  } else if (nums[i] < nums[left] && nums[i] < nums[right]) {
                      count++; // Valley
                  }
              }
          }
  
          return count;
      }
  };
  