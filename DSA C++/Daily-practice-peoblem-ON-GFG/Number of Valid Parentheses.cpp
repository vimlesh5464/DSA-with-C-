#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
  long long catalan(int n) {
        if (n <= 1) return 1;

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += catalan(i) * catalan(n - i - 1);
        }
        return res;
    }
    int findWays(int n) {
        // code here
        if (n % 2 != 0) return 0;
        return catalan(n / 2);
    }
};

class Solution {
  public:
    long long catalan(int n, vector<long long> &dp) {
        if (n <= 1) return 1;

        if (dp[n] != -1) return dp[n];   // memo check

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += catalan(i, dp) * catalan(n - i - 1, dp);
        }

        return dp[n] = res;  // store result
    }

    int findWays(int n) {
        if (n % 2 != 0) return 0;

        int pairs = n / 2;
        vector<long long> dp(pairs + 1, -1);

        return catalan(pairs, dp);
    }
};


class Solution {
  public:
    int findWays(int n) {
        // code here
        // If length is odd, no valid parentheses
        if (n % 2 != 0) return 0;

        int pairs = n / 2;
        vector<long long> dp(pairs + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= pairs; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[pairs];
    }
};