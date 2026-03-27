// Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
// Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

// Note: Each item can be taken any number of times.

// Examples:

// Input: val[] = [1, 1], wt[] = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times.

// Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
// Output: 110
// Explanation: The optimal choice is to pick the 2nd element and the 4th element.

// Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
// Output: 0
// Explanation: We can't pick any element. Hence, total profit is 0.

// Constraints:
// 1 ≤ val.size() = wt.size() ≤ 1000
// 1 ≤ capacity ≤ 1000
// 1 ≤ val[i], wt[i] ≤ 100
#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int knapSackRecursive(vector<int>& val, vector<int>& wt, int W, int n) {
        // Base case
        if(n == 0 || W == 0) return 0;

        if(wt[n-1] <= W) {
            // Include item (n stays same) or exclude it
            int include = val[n-1] + knapSackRecursive(val, wt, W - wt[n-1], n);
            int exclude = knapSackRecursive(val, wt, W, n-1);
            return max(include, exclude);
        } else {
            return knapSackRecursive(val, wt, W, n-1);
        }
    }
};

class Solution {
  public:
      int helper(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>& dp) {
          if(n == 0 || W == 0) return 0;
          if(dp[n][W] != -1) return dp[n][W];
  
          if(wt[n-1] <= W) {
              int include = val[n-1] + helper(val, wt, W - wt[n-1], n, dp);
              int exclude = helper(val, wt, W, n-1, dp);
              return dp[n][W] = max(include, exclude);
          } else {
              return dp[n][W] = helper(val, wt, W, n-1, dp);
          }
      }
  
      int knapSack(vector<int>& val, vector<int>& wt, int W) {
          int n = val.size();
          vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
          return helper(val, wt, W, n, dp);
      }
  };
  
int main() {
    Solution sol;
    vector<int> val = {10, 30, 20};
    vector<int> wt = {5, 10, 15};
    int W = 100;

    //cout << "Maximum value = " << sol.knapSackRecursive(val, wt, W, val.size()) << endl;
    return 0;
}
