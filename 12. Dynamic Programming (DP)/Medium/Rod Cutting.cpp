#include <iostream>
#include<vector>
using namespace std;


class Solution {
  public:
      int cutRod(int price[], int n) {
          int length[n];
          for(int i = 0; i < n; i++) length[i] = i+1; // lengths 1..n
  
          vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  
          for(int i = 1; i <= n; i++) {
              for(int j = 1; j <= n; j++) {
                  if(length[i-1] <= j) {
                      dp[i][j] = max(
                          price[i-1] + dp[i][j - length[i-1]],
                          dp[i-1][j]
                      );
                  } else {
                      dp[i][j] = dp[i-1][j];
                  }
              }
          }
  
          return dp[n][n];
      }
  };
  
class Solution {
public:
    int helper(int length[], int price[], int n, int W, vector<vector<int>>& dp) {
        if(n == 0 || W == 0) return 0;

        if(dp[n][W] != -1) return dp[n][W];

        if(length[n-1] <= W) {
            // Include the current piece or exclude it
            int include = price[n-1] + helper(length, price, n, W - length[n-1], dp);
            int exclude = helper(length, price, n-1, W, dp);
            dp[n][W] = max(include, exclude);
        } else {
            dp[n][W] = helper(length, price, n-1, W, dp);
        }

        return dp[n][W];
    }

    int cutRod(int price[], int n) {
        int length[n];
        for(int i = 0; i < n; i++) length[i] = i+1; // lengths 1,2,...n

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(length, price, n, n, dp);
    }
};

int main() {
    Solution sol;
    int price[] = {1,5,8,9,10,17,17,20};
    int n = 8;
    cout << "Maximum obtainable price: " << sol.cutRod(price, n) << endl;
    return 0;
}
