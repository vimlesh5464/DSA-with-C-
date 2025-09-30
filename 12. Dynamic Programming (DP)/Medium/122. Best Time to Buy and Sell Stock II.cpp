#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int n = prices.size();
          if (n == 0) return 0;
  
          int hold = -prices[0];   // Bought stock on day 0
          int notHold = 0;         // Haven't bought any stock
  
          for (int i = 1; i < n; i++) {
              int prevHold = hold;
              int prevNotHold = notHold;
  
              hold = max(prevHold, prevNotHold - prices[i]);  // Buy or hold
              notHold = max(prevNotHold, prevHold + prices[i]); // Sell or stay
          }
  
          return notHold;
      }
  };
  
int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << "Max Profit: " << sol.maxProfit(prices) << endl; // Output: 7
    return 0;
}
