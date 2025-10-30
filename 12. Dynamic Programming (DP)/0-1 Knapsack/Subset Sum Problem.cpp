#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      bool helper(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
          if(sum == 0) return true;
          if(n == 0) return false;
          
          if(dp[n][sum] != -1) return dp[n][sum]; // already computed
          
          if(arr[n-1] > sum)
              return dp[n][sum] = helper(arr, n-1, sum, dp);
          else
              return dp[n][sum] = helper(arr, n-1, sum, dp) || helper(arr, n-1, sum - arr[n-1], dp);
      }
      
      bool isSubsetSum(vector<int>& arr, int sum) {
          int n = arr.size();
          vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
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
    