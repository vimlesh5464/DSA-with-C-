#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int change(int amount, vector<int>& coins) {
          int n = coins.size();
          vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
  
          // Base case: 0 amount → 1 way
          for(int i = 0; i <= n; i++)
              dp[i][0] = 1;
  
          for(int i = 1; i <= n; i++) {
              for(int j = 1; j <= amount; j++) {
                  if(coins[i-1] <= j)
                      dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                  else
                      dp[i][j] = dp[i-1][j];
              }
          }
  
          return dp[n][amount];
      }
  };
  

class Solution {
public:
    int helper(vector<int>& coins, int W, int n, vector<vector<int>>& dp) {
        if(W == 0) return 1;   // Found a valid combination
        if(n == 0) return 0;   // No coins left

        if(dp[n][W] != -1) return dp[n][W];

        if(coins[n-1] <= W) {
            // Include current coin + Exclude current coin
            int include = helper(coins, W - coins[n-1], n, dp);
            int exclude = helper(coins, W, n-1, dp);
            dp[n][W] = include + exclude;
        } else {
            // Cannot include current coin, only exclude
            dp[n][W] = helper(coins, W, n-1, dp);
        }

        return dp[n][W];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return helper(coins, amount, n, dp);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Number of ways: " << sol.change(amount, coins) << endl; // Output: 4
    return 0;
}
