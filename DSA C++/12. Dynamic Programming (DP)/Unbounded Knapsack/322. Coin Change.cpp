// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:

// Input: coins = [2], amount = 3
// Output: -1

// Example 3:

// Input: coins = [1], amount = 0
// Output: 0

 

// Constraints:

//     1 <= coins.length <= 12
//     1 <= coins[i] <= 231 - 1
//     0 <= amount <= 104

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
  public:
      int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
          
          if (amount == 0) return 0;
          if (i >= coins.size() || amount < 0) return 1e9;
          
          if (dp[i][amount] != -1) return dp[i][amount];
          
          int take = 1 + solve(coins, amount - coins[i], i, dp);
          int notTake = solve(coins, amount, i + 1, dp);
          
          return dp[i][amount] = min(take, notTake);
      }
      
      int coinChange(vector<int>& coins, int amount) {
          int n = coins.size();
          vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
          
          int ans = solve(coins, amount, 0, dp);
          
          return (ans >= 1e9) ? -1 : ans;
      }
  };

class Solution {
  public:
      int coinChange(vector<int>& coins, int amount) {
          vector<int> dp(amount + 1, amount + 1); // initialize with "infinity"
          dp[0] = 0; // 0 coins needed for amount 0
  
          for(int i = 1; i <= amount; i++) {
              for(int c : coins) {
                  if(i - c >= 0) {
                      dp[i] = min(dp[i], dp[i - c] + 1);
                  }
              }
          }
  
          return (dp[amount] > amount) ? -1 : dp[amount];
      }
  };
  
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution sol;
    cout << "Minimum coins needed: " << sol.coinChange(coins, amount) << endl; // Output: 3
    return 0;
}
