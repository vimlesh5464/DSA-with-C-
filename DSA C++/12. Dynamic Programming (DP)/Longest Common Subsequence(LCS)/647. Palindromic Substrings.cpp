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