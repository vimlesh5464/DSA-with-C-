#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int minRemoval(vector<int>& nums, int k) {
          sort(nums.begin(), nums.end());
          
          int n = nums.size();
          int l = 0;
          int maxLen = 1;
  
          for (int r = 0; r < n; r++) {
              // shrink window until balanced
              while ((long long)nums[r] > (long long)nums[l] * k) {
                  l++;
              }
              maxLen = max(maxLen, r - l + 1);
          }
  
          return n - maxLen;
      }
  };