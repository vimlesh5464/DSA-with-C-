#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n == 0) return 1; // 1 way to stay at step 0
        if (n == 1) return 1; // 1 way to reach step 1

        // Recursive relation:
        // Ways = ways(n-1) + ways(n-2)
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
//Recursion + Memoization (Fast)
class Solution {
  public:
      int solve(int n, vector<int>& dp) {
          if (n == 0) return 1;
          if (n == 1) return 1;
  
          if (dp[n] != -1) return dp[n];  // Return already computed value
  
          // Memoized recurrence
          return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
      }
  
      int climbStairs(int n) {
          vector<int> dp(n + 1, -1);
          return solve(n, dp);
      }
  };
  //Tabulation (Bottom-Up DP)
class Solution {
  public:
      int climbStairs(int n) {
          if (n == 0 || n == 1) return 1;
          vector<int> dp(n + 1);
          dp[0] = dp[1] = 1;
          for (int i = 2; i <= n; i++) {
              dp[i] = dp[i - 1] + dp[i - 2];
          }
          return dp[n];
      }
  };
 
int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    Solution obj;
    cout << "Number of ways = " << obj.climbStairs(n) << endl;

    return 0;
}
