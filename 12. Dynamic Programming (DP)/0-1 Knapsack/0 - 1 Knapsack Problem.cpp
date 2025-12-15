#include <iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int helper(int W, vector<int> &val, vector<int> &wt, int n) {
        // Base case
        if (n == 0 || W == 0)
            return 0;

        // If weight of current item is more than the capacity → cannot include
        if (wt[n-1] > W)
            return helper(W, val, wt, n-1);

        // Two choices: include or exclude the item
        int include = val[n-1] + helper(W - wt[n-1], val, wt, n-1);
        int exclude = helper(W, val, wt, n-1);

        return max(include, exclude);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        return helper(W, val, wt, n);
    }
};

class Solution {
public:
    int helper(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp) {
        // Base case
        if (n == 0 || W == 0) return 0;
        
        // Already calculated
        if (dp[n][W] != -1) return dp[n][W];
        
        if (wt[n-1] <= W) {
            // Option 1: include item
            int include = val[n-1] + helper(W - wt[n-1], val, wt, n-1, dp);
            // Option 2: exclude item
            int exclude = helper(W, val, wt, n-1, dp);
            return dp[n][W] = max(include, exclude);
        } 
        else {
            // Cannot include this item
            return dp[n][W] = helper(W, val, wt, n-1, dp);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return helper(W, val, wt, n, dp);
    }
};

//Tabulation (Bottom-Up DP)
class Solution {
  public:
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n = val.size();
  
          // DP table: (n+1) × (W+1)
          vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
  
          // Build table bottom-up
          for (int i = 1; i <= n; i++) {          // items
              for (int w = 1; w <= W; w++) {      // capacity
                  if (wt[i - 1] <= w) {
                      int include = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                      int exclude = dp[i - 1][w];
                      dp[i][w] = max(include, exclude);
                  } else {
                      dp[i][w] = dp[i - 1][w];
                  }
              }
          }
  
          return dp[n][W];
      }
  };
  

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    vector<int> val(n), wt(n);
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    Solution sol;
    cout << "Maximum value in Knapsack = " << sol.knapsack(W, val, wt) << endl;
    return 0;
}
