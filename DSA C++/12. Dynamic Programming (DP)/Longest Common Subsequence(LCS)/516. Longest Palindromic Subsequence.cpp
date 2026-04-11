// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting 
//some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

 

// Constraints:

//     1 <= s.length <= 1000
//     s consists only of lowercase English letters.
#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      // Check if string is palindrome
      bool isPalindrome(string &s) {
          int i = 0, j = s.length() - 1;
          while (i < j) {
              if (s[i] != s[j]) return false;
              i++; j--;
          }
          return true;
      }
  
      void generate(string &s, int idx, string curr, int &maxLen) {
          if (idx == s.length()) {
              if (isPalindrome(curr)) {
                  maxLen = max(maxLen, (int)curr.length());
              }
              return;
          }
  
          // Take
          generate(s, idx + 1, curr + s[idx], maxLen);
  
          // Not take
          generate(s, idx + 1, curr, maxLen);
      }
  
      int longestPalindromeSubseq(string s) {
          int maxLen = 0;
          generate(s, 0, "", maxLen);
          return maxLen;
      }
  };
  class Solution {
    public:
    
        int solve(int i, int j, string &s1, string &s2,
                  vector<vector<int>> &dp) {
    
            if (i < 0 || j < 0) return 0;
    
            if (dp[i][j] != -1) return dp[i][j];
    
            if (s1[i] == s2[j]) {
                return dp[i][j] =
                    1 + solve(i - 1, j - 1, s1, s2, dp);
            }
    
            return dp[i][j] =
                max(solve(i - 1, j, s1, s2, dp),
                    solve(i, j - 1, s1, s2, dp));
        }
    
        int lcs(string s1, string s2) {
            int n = s1.size();
            int m = s2.size();
    
            vector<vector<int>> dp(n, vector<int>(m, -1));
    
            return solve(n - 1, m - 1, s1, s2, dp);
        }
    
        int longestPalinSubseq(string &s) {
    
            string t = s;
            reverse(t.begin(), t.end());  // FIX: reverse t, not s
    
            return lcs(s, t);
        }
    };
class Solution {
  public:
  int lcs(string s1, string s2) {
          int n = s1.size();
          int m = s2.size();
  
          // Declare a 2D DP array to store length of the LCS
          vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  
          // Initialize first row and first column to 0
          for (int i = 0; i <= n; i++) {
              dp[i][0] = 0;
          }
          for (int i = 0; i <= m; i++) {
              dp[0][i] = 0;
          }
  
          // Fill in the DP array
          for (int ind1 = 1; ind1 <= n; ind1++) {
              for (int ind2 = 1; ind2 <= m; ind2++) {
                  if (s1[ind1 - 1] == s2[ind2 - 1])
                      dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                  else
                      dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
              }
          }
          // The value at dp[n][m] contains length of the LCS
          return dp[n][m];
      }
      int longestPalindromeSubseq(string s) {
           // Store a reversed copy of the string
          string t = s;
          reverse(s.begin(), s.end());
  
          /* Call the LCS function to find the 
          length of the Longest Common Subsequence*/
          return lcs(s, t);
      }
  };