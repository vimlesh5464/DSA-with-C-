// Given an integer array nums, return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing.

 

// Example 1:

// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

// Example 2:

// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

 

// Constraints:

//     1 <= nums.length <= 2000
//     -106 <= nums[i] <= 106
//     The answer is guaranteed to fit inside a 32-bit integer.

 

#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int findNumberOfLIS(vector<int>& arr) {
           int n = arr.size();
  
          // Store the length of the increasing subsequence ending at each position
          vector<int> dp(n, 1);
  
          // Store the count of increasing subsequences ending at each position
          vector<int> ct(n, 1);
  
          // Track the maximum subsequence length found so far
          int maxi = 1;
  
          // Loop through each position in the sequence
          for (int i = 0; i < n; i++) {
              // Compare the current position with all previous positions
              for (int j = 0; j < i; j++) {
                  // If an increasing sequence is found that is longer than the current best for this position
                  if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                      // Update the best subsequence length for this position
                      dp[i] = dp[j] + 1;
  
                      // Reset the count to match the source subsequence count
                      ct[i] = ct[j];
                  }
                  // If an increasing sequence of the same best length is found
                  else if (arr[j] < arr[i] && dp[j] + 1 == dp[i]) {
                      // Add the count of subsequences from the previous position
                      ct[i] = ct[i] + ct[j];
                  }
              }
              // Update the global maximum subsequence length if needed
              maxi = max(maxi, dp[i]);
          }
  
          // Store the total number of subsequences of maximum length
          int countLIS = 0;
  
          // Sum the counts of all positions where the length equals the maximum length
          for (int i = 0; i < n; i++) {
              if (dp[i] == maxi) {
                  countLIS += ct[i];
              }
          }
  
          // Return the total number of longest increasing subsequences
          return countLIS;
      }
  };