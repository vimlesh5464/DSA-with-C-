// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

 

// Constraints:

//     1 <= s.length <= 1000
//     s consists of lowercase English letters.

#include <iostream>
#include<string>
#include<vector>
using namespace std;

  class Solution {
    public:
    
        int expand(string &s, int left, int right) {
            int count = 0;
    
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
    
            return count;
        }
    
        int countSubstrings(string s) {
            int n = s.size();
            int total = 0;
    
            for (int i = 0; i < n; i++) {
    
                // odd length palindromes (center = i)
                total += expand(s, i, i);
    
                // even length palindromes (center = i, i+1)
                total += expand(s, i, i + 1);
            }
    
            return total;
        }
    };

    class Solution {
      public:
      
          bool solve(int i, int j, string &s, vector<vector<int>> &dp) {
              if (i >= j) return true;
      
              if (dp[i][j] != -1) return dp[i][j];
      
              if (s[i] == s[j]) {
                  return dp[i][j] = solve(i + 1, j - 1, s, dp);
              }
      
              return dp[i][j] = false;
          }
      
          int countSubstrings(string s) {
              int n = s.size();
      
              vector<vector<int>> dp(n, vector<int>(n, -1));
              int count = 0;
      
              for (int i = 0; i < n; i++) {
                  for (int j = i; j < n; j++) {
                      if (solve(i, j, s, dp)) {
                          count++;
                      }
                  }
              }
      
              return count;
          }
      };
class Solution {
  public:
      int countSubstrings(string s) {
          int n = s.size();
          int count = 0;
  
          vector<vector<bool>> dp(n, vector<bool>(n, false));
  
          // Fill the table
          for (int len = 1; len <= n; len++) {
              for (int i = 0; i <= n - len; i++) {
                  int j = i + len - 1;
  
                  if (len == 1) {
                      dp[i][j] = true; // single character
                  } else if (len == 2) {
                      dp[i][j] = (s[i] == s[j]); // two characters
                  } else {
                      dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]); // length > 2
                  }
  
                  if (dp[i][j]) count++;
              }
          }
  
          return count;
      }
  };