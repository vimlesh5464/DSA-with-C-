#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
      int countSubstrings(string s) {
          int count = 0;
  
          for (int i = 0; i < s.length(); i++) {
              // Count odd length palindromes
              count += expand(s, i, i);
  
              // Count even length palindromes
              count += expand(s, i, i + 1);
          }
          return count;
      }
  
      int expand(string &s, int left, int right) {
          int cnt = 0;
          while (left >= 0 && right < s.length() && s[left] == s[right]) {
              cnt++;
              left--;
              right++;
          }
          return cnt;
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

class Solution {
  public:
      string longestPalindrome(string s) {
          if (s.empty() || s.length() < 1) return "";
  
          int start = 0, end = 0;
  
          for (int i = 0; i < s.length(); i++) {
              int len1 = expandAroundCenter(s, i, i);     // odd length
              int len2 = expandAroundCenter(s, i, i + 1); // even length
              int len = max(len1, len2);
  
              if (len > end - start) {
                  start = i - (len - 1) / 2;
                  end = i + len / 2;
              }
          }
  
          return s.substr(start, end - start + 1);
      }
  
  private:
      int expandAroundCenter(const string &s, int left, int right) {
          while (left >= 0 && right < s.length() && s[left] == s[right]) {
              left--;
              right++;
          }
          return right - left - 1; // length of palindrome
      }
  };
  

int main() {
    Solution sol;
    string s = "aaa";
    cout << sol.longestPalindrome(s); // Output: 6
}
