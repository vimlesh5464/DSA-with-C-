// Given an array arr[] and an integer k, find the count of subsets whose sum is equals to k.

// Note: It is guaranteed that the no of valid subsets will fit within a 32-bit integer.

// Examples:

// Input: arr[] = [1, 3, 2], k = 3
// Output: 2
// Explanation: The two subsets whose sum is equals to k are [1, 2] and [3].

// Input: arr[] = [4, 2, 3, 1, 2], k = 4
// Output: 3
// Explanation: The three subsets whose sum is equals to k are [4], [2, 2] and [3, 1].

// Input: arr[] = [10, 20, 30], k = 25
// Output: 0
// Explanation: No subsets exits with sum equals to k.

// Constraints:
// 1 ≤ arr.size() ≤ 40
// -107 ≤ arr[i], k ≤ 107
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
  public:
      int helper(int index, int target, vector<int>& arr) {
          // Base case
          if (index == 0) {
              if (target == 0 && arr[0] == 0) return 2; // either take or not take zero
              if (target == 0 || target == arr[0]) return 1;
              return 0;
          }
  
          // Choice 1: exclude current element
          int notTake = helper(index - 1, target, arr);
  
          // Choice 2: include current element (if possible)
          int take = 0;
          take = helper(index - 1, target - arr[index], arr);
  
          return take + notTake;
      }
  
      int countSubsets(vector<int>& arr, int k) {
          int n = arr.size();
          return helper(n - 1, k, arr);
      }
  };
  
  class Solution {
    public:
        int helper(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
            // Base case
            if (index == 0) {
                if (target == 0 && arr[0] == 0) return 2; // take or not take 0
                if (target == 0 || target == arr[0]) return 1;
                return 0;
            }
    
            if (dp[index][target] != -1) return dp[index][target];
    
            // Choice 1: exclude current element
            int notTake = helper(index - 1, target, arr, dp);
    
            // Choice 2: include current element (if possible)
            int take = 0;
            if (target >= arr[index])
                take = helper(index - 1, target - arr[index], arr, dp);
    
            return dp[index][target] = take + notTake;
        }
    
        int countSubset(vector<int> &arr, int k) {
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(k + 1, -1));
            return helper(n - 1, k, arr, dp);
        }
    };
    
//gfg Version
    class Solution {
      public:
      // Recursive helper with memoization
          int helper(int index, long long target, vector<int>& arr, vector<unordered_map<long long,int>>& dp) {
              if (index == 0) {
                  // Base case
                  if (target == 0 && arr[0] == 0) return 2;  // take or not take zero
                  if (target == 0 || target == arr[0]) return 1;
                  return 0;
              }
      
              // Check memo
              if (dp[index].find(target) != dp[index].end())
                  return dp[index][target];
      
              // Not take current element
              int notTake = helper(index - 1, target, arr, dp);
      
              // Take current element
              int take = helper(index - 1, target - arr[index], arr, dp);
      
              return dp[index][target] = take + notTake;
          }
      
         int countSubset(vector<int>& arr, int k) {
         int n = arr.size();
      
              // Early termination: impossible target
              long long minSum = 0, maxSum = 0;
              for (int x : arr) {
                  if (x > 0) maxSum += x;
                  if (x < 0) minSum += x;
              }
              if (k < minSum || k > maxSum) return 0;  // impossible target
      
              vector<unordered_map<long long,int>> dp(n);
              return helper(n - 1, k, arr, dp);
      }
      
      };