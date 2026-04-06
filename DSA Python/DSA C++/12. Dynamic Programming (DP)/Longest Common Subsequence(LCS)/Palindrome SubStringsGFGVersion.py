# Palindrome SubStringsGFGVersion.py - Python skeleton converted from C++

# Original C++ code:
# // Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2.
# 
# // Note: A substring is palindromic if it reads the same forwards and backwards.
# 
# // Examples:
# 
# // Input: s = "abaab"
# // Output: 3
# // Explanation: All palindromic substrings (of length > 1) are: "aba", "aa", "baab".
# 
# // Input: s = "aaa"
# // Output: 3
# // Explanation: All palindromic substrings (of length > 1) are: "aa", "aa", "aaa".
# 
# // Input: s = "abbaeae"
# // Output: 4
# // Explanation: All palindromic substrings (of length > 1) are: "bb", "abba", "aea", "eae".
# 
# // Constraints:
# // 2 ≤ s.size() ≤ 5 * 103
# // s contains only lowercase english characters
# 
# #include <iostream>
# #include<string>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#       int countPS(string &s) {
#           int n = s.size();
#           vector<vector<bool>> dp(n, vector<bool>(n, false));
#           int count = 0;
#   
#           for (int gap = 0; gap < n; gap++) {
#               for (int i = 0, j = gap; j < n; i++, j++) {
#                   
#                   if (gap == 0)
#                       dp[i][j] = true;
#                   else if (gap == 1)
#                       dp[i][j] = (s[i] == s[j]);
#                   else
#                       dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
#   
#                   // ✅ Count only length >= 2
#                   if (gap >= 1 && dp[i][j])
#                       count++;
#               }
#           }
#   
#           return count;
#       }
#   };
#   
# class Solution {
#   public:
#       int countPS(string &s) {
#           int n = s.size();
#           int count = 0;
#   
#           for (int center = 0; center < n; center++) {
#               
#               // Odd length palindromes
#               int left = center, right = center;
#               while (left >= 0 && right < n && s[left] == s[right]) {
#                   if (right - left + 1 >= 2) count++; // length >= 2
#                   left--;
#                   right++;
#               }
#   
#               // Even length palindromes
#               left = center;
#               right = center + 1;
#               while (left >= 0 && right < n && s[left] == s[right]) {
#                   if (right - left + 1 >= 2) count++; // length >= 2
#                   left--;
#                   right++;
#               }
#           }
#   
#           return count;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
