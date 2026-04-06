# Longest Common Substring.py - Python skeleton converted from C++

# Original C++ code:
# // You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.
# 
# // Examples:
# 
# // Input: s1 = "ABCDGH", s2 = "ACDGHR"
# // Output: 4
# // Explanation: The longest common substring is "CDGH" with a length of 4.
# 
# // Input: s1 = "abc", s2 = "acb"
# // Output: 1
# // Explanation: The longest common substrings are "a", "b", "c" all having length 1.
# 
# // Input: s1 = "YZ", s2 = "yz"
# // Output: 0
# 
# // Constraints:
# // 1 <= s1.size(), s2.size() <= 103
# // Both strings may contain upper and lower case alphabets.
# #include <iostream>
# #include<vector>
# using namespace std;
# 
# class Solution {
#   public:
#    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &maxLen) {
#         if (i < 0 || j < 0) return 0;
# 
#         if (dp[i][j] != -1) return dp[i][j];
# 
#         int len = 0;
#         if (s1[i] == s2[j]) {
#             len = 1 + solve(i - 1, j - 1, s1, s2, dp, maxLen);
#         }
# 
#         dp[i][j] = len;
#         maxLen = max(maxLen, dp[i][j]);
#         return dp[i][j];
#     }
#     int longCommSubstr(string& s1, string& s2) {
#         // your code here
#          int n = s1.size();
#         int m = s2.size();
# 
#         vector<vector<int>> dp(n, vector<int>(m, -1));
#         int maxLen = 0;
# 
#         for (int i = 0; i < n; i++) {
#             for (int j = 0; j < m; j++) {
#                 solve(i, j, s1, s2, dp, maxLen);
#             }
#         }
# 
#         return maxLen;
#     }
# };
# int longestCommonSubstring(string s1, string s2) {
#     int n = s1.size(), m = s2.size();
#     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
#     int result = 0;
# 
#     for(int i=1; i<=n; i++) {
#         for(int j=1; j<=m; j++) {
#             if(s1[i-1] == s2[j-1]) {
#                 dp[i][j] = 1 + dp[i-1][j-1];
#                 result = max(result, dp[i][j]);
#             }
#             else {
#                 dp[i][j] = 0; // reset if chars don’t match
#             }
#         }
#     }
#     return result;
# }
# 
# int main() {
#     string s1 = "zxabcdezy", s2 = "yzabcdezx";
#     cout << "Length of Longest Common Substring: " 
#          << longestCommonSubstring(s1, s2) << endl;
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
