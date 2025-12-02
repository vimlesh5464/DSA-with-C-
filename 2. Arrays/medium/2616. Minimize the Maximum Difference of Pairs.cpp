#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      bool isValid(vector<int>& nums, int p, int maxDiff) {
          int count = 0;
          for (int i = 1; i < nums.size(); ) {
              if (nums[i] - nums[i - 1] <= maxDiff) {
                  count++;
                  i += 2;  // use both indices
              } else {
                  i += 1;  // skip one
              }
          }
          return count >= p;
      }
  
      int minimizeMax(vector<int>& nums, int p) {
          sort(nums.begin(), nums.end());
  
          int low = 0;
          int high = nums[nums.size() - 1] - nums[0];
          int result = high;
  
          while (low <= high) {
              int mid = low + (high - low) / 2;
  
              if (isValid(nums, p, mid)) {
                  result = mid;
                  high = mid - 1;
              } else {
                  low = mid + 1;
              }
          }
  
          return result;
      }
  };
  