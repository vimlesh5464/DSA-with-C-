// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.

// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

// Constraints:
// 1 <= arr.size() <= 200
// 1<= arr[i] <= 200
// 1<= sum <= 104
#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      bool helper(vector<int>& arr, int n, int sum) {
          // Base cases
          if (sum == 0) return true;
          if (n == 0) return false;
  
          // If current element is less than or equal to sum
          if (arr[n - 1] <= sum) {
              return helper(arr, n - 1, sum) || 
                     helper(arr, n - 1, sum - arr[n - 1]);
          } else {
              return helper(arr, n - 1, sum);
          }
      }
  
      bool isSubsetSum(vector<int>& arr, int sum) {
          int n = arr.size();
          return helper(arr, n, sum);
      }
  };

  class Solution {
    public:
        bool helper(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
            // Base cases
            if (sum == 0) return true;
            if (n == 0) return false;
    
            // If already computed
            if (dp[n][sum] != -1) return dp[n][sum];
    
            if (arr[n - 1] <= sum) {
                return dp[n][sum] = helper(arr, n - 1, sum, dp) || 
                                    helper(arr, n - 1, sum - arr[n - 1], dp);
            } else {
                return dp[n][sum] = helper(arr, n - 1, sum, dp);
            }
        }
    
        bool isSubsetSum(vector<int>& arr, int sum) {
            int n = arr.size();
            
            // dp[n+1][sum+1] initialized with -1
            vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
            
            return helper(arr, n, sum, dp);
        }
    };

  class Solution {
    public:
        bool isSubsetSum(vector<int>& arr, int sum) {
            int n = arr.size();
            vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
            
            // Base case: sum = 0 is always possible
            for(int i = 0; i <= n; i++)
                dp[i][0] = true;
            
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= sum; j++){
                    if(j < arr[i-1]){
                        dp[i][j] = dp[i-1][j];  // cannot include arr[i-1]
                    } else {
                        dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                    }
                }
            }
            
            return dp[n][sum];
        }
    };
    
    int main() {
      vector<int> arr = {4, 2, 7, 1, 3};
      int target = 10;
  
      Solution sol;
      cout << (sol.isSubsetSum(arr, target) ? "True" : "False") << endl;
  
      return 0;
  }
  