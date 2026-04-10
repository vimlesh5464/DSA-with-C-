// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

// Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

 

// Constraints:

//     1 <= k <= 100
//     1 <= prices.length <= 1000
//     0 <= prices[i] <= 1000

#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
  int getAns(vector<int>& prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>> &dp) {
      // Base case
      if (ind == n || cap == 0) return 0;
  
      // Check if the result is already computed
      if (dp[ind][buy][cap] != -1)
          return dp[ind][buy][cap];
  
      int profit;
  
      if (buy == 0) { // We can buy the stock
          profit = max(0 + getAns(prices, n, ind + 1, 0, cap, dp),
                       -prices[ind] + getAns(prices,n, ind + 1, 1, cap, dp));
      }
  
      if (buy == 1) { // We can sell the stock
          profit = max(0 + getAns(prices, n, ind + 1, 1, cap, dp),
                       prices[ind] + getAns(prices, n, ind + 1, 0, cap - 1, dp));
      }
  
      // Store the result in the DP array and return
      return dp[ind][buy][cap] = profit;
  }
      int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
  
          vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
          return getAns(prices, n, 0, 0, k, dp);
      }
  };

  class Solution {
    public:
    
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
    
            // 🔥 Fix: n+1
            vector<vector<vector<int>>> dp(
                n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0))
            );
    
            // Base case already handled (dp[n][...] = 0)
    
            for (int ind = n - 1; ind >= 0; ind--) {
                for (int buy = 0; buy <= 1; buy++) {
                    for (int cap = 1; cap <= k; cap++) {
    
                        if (buy == 0) { // Buy allowed
                            dp[ind][buy][cap] = max(
                                dp[ind + 1][0][cap],                    // skip
                                -prices[ind] + dp[ind + 1][1][cap]      // buy
                            );
                        } 
                        else { // Sell allowed
                            dp[ind][buy][cap] = max(
                                dp[ind + 1][1][cap],                    // skip
                                prices[ind] + dp[ind + 1][0][cap - 1]   // sell
                            );
                        }
                    }
                }
            }
    
            return dp[0][0][k];
        }
    };