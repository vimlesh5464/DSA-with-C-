// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.

// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

 

// Constraints:

//     1 <= prices.length <= 3 * 104
//     0 <= prices[i] <= 104

#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  long getAns(vector<int>& prices, int ind, int buy, int n, vector<vector<long>> &dp) {
      // Base case: When we reach the end of the array, there are no more decisions to make.
      if (ind == n) {
          return 0;
      }
  
      // If the result for this state has already been calculated, return it
      if (dp[ind][buy] != -1) {
          return dp[ind][buy];
      }
  
      long profit = 0;
  
      if (buy == 0) { // We can buy the stock
          profit = max(0 + getAns(prices, ind + 1, 0, n, dp), -prices[ind] + getAns(prices, ind + 1, 1, n, dp));
      }
  
      if (buy == 1) { // We can sell the stock
          profit = max(0 + getAns(prices, ind + 1, 1, n, dp), prices[ind] + getAns(prices, ind + 1, 0, n, dp));
      }
  
      // Store the calculated profit in the DP table and return it
      return dp[ind][buy] = profit;
  }
  
      int maxProfit(vector<int>& prices) {
           // Create a DP table to memoize results
           int n = prices.size();
      vector<vector<long>> dp(n, vector<long>(2, -1));
  
      if (n == 0) {
          return 0;
      }
  
      long ans = getAns(prices, 0, 0, n, dp);
      return ans;
      }
  };
  
class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int profit = 0;
          int n = prices.size();
          for(int i = 1; i < n; i++){
              if(prices[i] > prices[i-1]){
                  profit += prices[i] - prices[i-1];
              }
          }
          return profit;
      }
  };