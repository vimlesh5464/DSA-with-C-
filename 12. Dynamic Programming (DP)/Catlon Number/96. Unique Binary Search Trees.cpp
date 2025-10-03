#include <iostream>
#include <vector>
using namespace std;
//tabulation
class Solution {
public:
    int numTrees(int n) {
        // dp[i] will store number of unique BSTs possible with i nodes
        vector<int> dp(n + 1, 0);

        // Base cases
        dp[0] = 1; // Empty tree
        dp[1] = 1; // Single node tree

        // Fill dp table
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // Choosing j nodes for left subtree and (i-j-1) for right
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
//memorization
class Solution {
  public:
      vector<int> dp;
  
      int countBST(int n) {
          // Base cases
          if (n == 0 || n == 1) return 1;
  
          // If already computed
          if (dp[n] != -1) return dp[n];
  
          int ans = 0;
          for (int i = 0; i < n; i++) {
              ans += countBST(i) * countBST(n - 1 - i);  // left * right
          }
  
          return dp[n] = ans;  // store in dp array
      }
  
      int numTrees(int n) {
          dp.assign(n + 1, -1);  // initialize dp array
          return countBST(n);
      }
  };
  
int main() {
    Solution sol;
    int n = 4;  // Example input
    cout << "Number of unique BSTs with " << n << " nodes = " 
         << sol.numTrees(n) << endl;
    return 0;
}
