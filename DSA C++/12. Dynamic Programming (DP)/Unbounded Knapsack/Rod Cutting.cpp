// Given a rod of length n inches and an array price[], where price[i] denotes the 
//value of a piece of length i. Your task is to determine the maximum value 
//obtainable by cutting up the rod and selling the pieces.

// Note: n = size of price, and price[] is 1-indexed array.

// Example:

// Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Output: 22
// Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

// Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
// Output: 24
// Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.

// Input: price[] = [3]
// Output: 3
// Explanation: There is only 1 way to pick a piece of length 1.

// Constraints:
// 1 ≤ price.size() ≤ 103
// 1 ≤ price[i] ≤ 106

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
