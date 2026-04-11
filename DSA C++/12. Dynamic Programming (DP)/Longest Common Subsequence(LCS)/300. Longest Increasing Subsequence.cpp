// Given an integer array nums, return the length of the longest strictly increasing .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

 

// Constraints:

//     1 <= nums.length <= 2500
//     -104 <= nums[i] <= 104

#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int solve(int i, int prevIndex, vector<int>& nums, vector<vector<int>>& dp) {
          if (i == nums.size()) return 0;
  
          if (dp[i][prevIndex + 1] != -1) return dp[i][prevIndex + 1];
  
          int notPick = solve(i + 1, prevIndex, nums, dp);
          int pick = 0;
          if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
              pick = 1 + solve(i + 1, i, nums, dp);
          }
  
          return dp[i][prevIndex + 1] = max(pick, notPick);
      }
  
      int lengthOfLIS(vector<int>& nums) {
          int n = nums.size();
          vector<vector<int>> dp(n, vector<int>(n + 1, -1));
          return solve(0, -1, nums, dp);
      }
  };
  
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1); // dp[i] = LIS ending at i
        int maxLen = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

//Time Complexity: O(N^2), nested loops are used to compute dp array and prev array.
// Space Complexity: O(N), space used to store DP array and previous array. 
// Solution class for LIS with reconstruction using DP
class Solution {
  public:
      // Function to return the LIS as a sequence (vector)
      vector<int> longestIncreasingSubsequence(vector<int> &nums) {
          int n = nums.size();
  
          // DP array to store length of LIS ending at each index
          vector<int> dp(n, 1);
  
          // Array to store previous index of LIS element for reconstruction
          vector<int> prev(n, -1);
  
          // Compute LIS length for each index
          for (int i = 1; i < n; i++) {
              for (int j = 0; j < i; j++) {
                  if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                      // Update dp[i] and store previous index
                      dp[i] = dp[j] + 1;
                      prev[i] = j;
                  }
              }
          }
  
          // Find the index of maximum LIS length
          int maxLen = 0, maxIndex = 0;
          for (int i = 0; i < n; i++) {
              if (dp[i] > maxLen) {
                  maxLen = dp[i];
                  maxIndex = i;
              }
          }
  
          // Reconstruct LIS sequence
          vector<int> lisSeq;
          int curr = maxIndex;
          while (curr != -1) {
              lisSeq.push_back(nums[curr]);
              curr = prev[curr];
          }
  
          // Reverse sequence as it was built backwards
          reverse(lisSeq.begin(), lisSeq.end());
  
          return lisSeq;
      }
  };
