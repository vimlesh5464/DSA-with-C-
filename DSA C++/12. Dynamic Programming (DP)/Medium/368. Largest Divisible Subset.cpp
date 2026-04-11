// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

//     answer[i] % answer[j] == 0, or
//     answer[j] % answer[i] == 0

// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]

 

// Constraints:

//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 2 * 109
//     All the integers in nums are unique.

#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      vector<int> largestDivisibleSubset(vector<int>& nums) {
          int n = nums.size(); // Size of the array 
  
          sort(nums.begin(), nums.end());
  
          vector<int> ans; // To store the LDS
          vector<int> dp(n, 1); // DP array 
          vector<int> parent(n); // Array to keep record of the parent
  
          // To store the index of last element in the LDS
          int lastIndex = 0; 
  
          // To store the length of LDS
          int maxLen = 0;
  
          // Computing the DP array 
          for(int i = 0; i < n; i++) {
              parent[i] = i; // Assign the parent to itself
  
              // For each previous index
              for(int prevInd = 0; prevInd < i; prevInd++) {
                  
                  // If the element at index i can be included in the LDS ending at index j
                  if(nums[i] % nums[prevInd] == 0 && dp[i] < dp[prevInd] + 1) {
  
                      dp[i] = dp[prevInd] + 1; // Update the DP value
                      parent[i] = prevInd; // Store the parent
                  }
              }
  
              // If a longer LDS is found, update the values
              if(dp[i] > maxLen) {
                  lastIndex = i;
                  maxLen = dp[i];
              }
          }
  
          // Backtracking
          int i = lastIndex;
  
          // Until we reach an index which is its own parent
          while(parent[i] != i) {
              ans.push_back(nums[i]); // Add the element at current index
              i = parent[i]; 
          }
          ans.push_back(nums[i]); // Adding the last element 
  
          // Return the computed result
          return ans;
      }
  };