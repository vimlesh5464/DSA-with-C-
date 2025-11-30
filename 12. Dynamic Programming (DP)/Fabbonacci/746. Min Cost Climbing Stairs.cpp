#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // pure recursion function
    int solve(int i, vector<int>& cost) {
        int n = cost.size();

        // If beyond last step -> no extra cost
        if (i >= n) return 0;

        // Option 1: take single step
        int one = cost[i] + solve(i + 1, cost);

        // Option 2: take double step
        int two = cost[i] + solve(i + 2, cost);

        return min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // Can start from step 0 OR step 1
        return min(solve(0, cost), solve(1, cost));
    }
};

class Solution {
  public:
      int solve(int i, vector<int>& cost, vector<int>& dp) {
          int n = cost.size();
  
          if (i >= n) return 0;
          if (dp[i] != -1) return dp[i];
  
          int one = cost[i] + solve(i + 1, cost, dp);
          int two = cost[i] + solve(i + 2, cost, dp);
  
          return dp[i] = min(one, two);
      }
  
      int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          vector<int> dp(n, -1);
  
          return min(solve(0, cost, dp), solve(1, cost, dp));
      }
  };
  
  class Solution {
    public:
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            vector<int> dp(n + 1, 0);
    
            for (int i = 2; i <= n; i++) {
                int one = dp[i - 1] + cost[i - 1];
                int two = dp[i - 2] + cost[i - 2];
                dp[i] = min(one, two);
            }
    
            return dp[n];
        }
    };
int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    vector<int> cost(n);
    cout << "Enter cost array: ";
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    Solution obj;
    cout << "Minimum cost to reach top = " 
         << obj.minCostClimbingStairs(cost) << endl;

    return 0;
}
