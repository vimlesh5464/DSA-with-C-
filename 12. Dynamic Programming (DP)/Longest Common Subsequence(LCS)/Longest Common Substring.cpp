#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
   int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &maxLen) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int len = 0;
        if (s1[i] == s2[j]) {
            len = 1 + solve(i - 1, j - 1, s1, s2, dp, maxLen);
        }

        dp[i][j] = len;
        maxLen = max(maxLen, dp[i][j]);
        return dp[i][j];
    }
    int longCommSubstr(string& s1, string& s2) {
        // your code here
         int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(i, j, s1, s2, dp, maxLen);
            }
        }

        return maxLen;
    }
};
int longestCommonSubstring(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int result = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                result = max(result, dp[i][j]);
            }
            else {
                dp[i][j] = 0; // reset if chars don’t match
            }
        }
    }
    return result;
}

int main() {
    string s1 = "zxabcdezy", s2 = "yzabcdezx";
    cout << "Length of Longest Common Substring: " 
         << longestCommonSubstring(s1, s2) << endl;
    return 0;
}
