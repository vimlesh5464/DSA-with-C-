#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to find the nth catalan number.
    int findCatalan(int n) {
        if (n == 0 || n == 1) return 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += findCatalan(i) * findCatalan(n - 1 - i);
        }
        return ans;
    }
};
class Solution {
  public:
    vector<long long> dp;
    
    long long solve(int n) {
        if (n == 0 || n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += solve(i) * solve(n - 1 - i);
        }
        return dp[n] = ans;
    }
    
    // Function to find the nth catalan number.
    long long findCatalan(int n) {
        dp.assign(n+1, -1);
        return solve(n);
    }
};


class Solution {
  public:
    // Function to find the nth catalan number using DP (Tabulation).
    long long findCatalan(int n) {
        vector<long long> dp(n+1, 0);

        // Base cases
        dp[0] = dp[1] = 1;

        // Fill table from 2 to n
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-1-j];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Catalan(" << n << ") = " << sol.findCatalan(n) << endl;
    return 0;
}
