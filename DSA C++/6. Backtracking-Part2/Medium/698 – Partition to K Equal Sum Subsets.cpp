// Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

// Example 1:

// Input: nums = [4,3,2,3,5,2,1], k = 4
// Output: true
// Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

// Example 2:

// Input: nums = [1,2,3,4], k = 3
// Output: false

 

// Constraints:

//     1 <= k <= nums.length <= 16
//     1 <= nums[i] <= 104
//     The frequency of each element is in the range [1, 4].
//I use backtracking to form k subsets each having sum equal to total/k. I track used
// elements and recursively build subsets. When one subset reaches target, I move to 
//the next. I also use pruning like sorting and early stopping to optimize.
#include <iostream>     
#include<vector>
using namespace std;
class Solution {
  public:
      bool backtrack(int idx, int k, int currSum, int target, vector<int>& nums,
                     vector<bool>& used) {
          // if only 1 subset left → valid
          if (k == 1)
              return true;
  
          // if current subset reaches target
          if (currSum == target)
              return backtrack(0, k - 1, 0, target, nums, used);
  
          for (int i = idx; i < nums.size(); i++) {
              if (used[i]) {
                  continue;
              }
  
              // skip if exceeds
              if (currSum + nums[i] > target) {
                  continue;
              }
  
              used[i] = true;
  
              if (backtrack(i + 1, k, currSum + nums[i], target, nums, used)) {
                  return true;
              }
  
              used[i] = false;
  
              // pruning 🔥
              if (currSum == 0) {
                  break;
              }
          }
  
          return false;
      }
      bool canPartitionKSubsets(vector<int>& nums, int k) {
          int total = 0;
          for (int num : nums)
              total += num;
  
          if (total % k != 0)
              return false;
  
          int target = total / k;
  
          sort(nums.rbegin(), nums.rend()); // descending (optimization)
  
          vector<bool> used(nums.size(), false);
  
          return backtrack(0, k, 0, target, nums, used);
      }
  };