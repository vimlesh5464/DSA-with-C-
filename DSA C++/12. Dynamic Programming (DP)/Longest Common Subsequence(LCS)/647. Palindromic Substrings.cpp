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
      
      // Check palindrome using recursion
      bool isPalindrome(string &s, int left, int right) {
          if (left >= right) return true;
          
          if (s[left] != s[right]) return false;
          
          return isPalindrome(s, left + 1, right - 1);
      }
      
      // Generate all substrings using recursion
      int solve(string &s, int i, int j) {
          int n = s.length();
          
          // If i reaches end
          if (i == n) return 0;
          
          // If j reaches end, move to next i
          if (j == n) return solve(s, i + 1, i + 1);
          
          int count = 0;
          
          // Check current substring
          if (isPalindrome(s, i, j))
              count = 1;
          
          // Move j forward
          return count + solve(s, i, j + 1);
      }
      
      int countSubstrings(string s) {
          return solve(s, 0, 0);
      }
  };
  class Solution {
    public:
        int countSubstrings(string s) {
            int n = s.length();
            int count = 0;
    
            for (int center = 0; center < n; center++) {
                
                // Odd length palindrome
                int left = center, right = center;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
                }
    
                // Even length palindrome
                left = center;
                right = center + 1;
                while (left >= 0 && right < n && s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
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