#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0) return 0;         // 0 coins needed
        if(amount < 0) return INT_MAX;    // impossible

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int c : coins) {
            int sub = helper(coins, amount - c, dp);
            if(sub != INT_MAX) ans = min(ans, 1 + sub);
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = helper(coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
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
