//Approach 1: Brute Force (Check All Pairs)
// Time Complexity: O(n^2)
// Space Complexity: O(1)
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }
};

//🔹 Approach 2: One Pass (Optimal) ✅
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int minPrice = INT_MAX;
          int maxProfit = 0;
          for(int price : prices){
              minPrice = min(minPrice, price);
              maxProfit = max(maxProfit, price - minPrice);
          }
          return maxProfit;
      }
  };

int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Maximum Profit: " << s.maxProfit(prices) << endl;
    return 0;
}
