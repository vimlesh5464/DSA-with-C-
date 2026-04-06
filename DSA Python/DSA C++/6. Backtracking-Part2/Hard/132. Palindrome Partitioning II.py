# 132. Palindrome Partitioning II.py - Python skeleton converted from C++

# Original C++ code:
# 
# // Given a string s, partition s such that every of the partition is a .
# 
# // Return the minimum cuts needed for a palindrome partitioning of s.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "aab"
# // Output: 1
# // Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
# 
# // Example 2:
# 
# // Input: s = "a"
# // Output: 0
# 
# // Example 3:
# 
# // Input: s = "ab"
# // Output: 1
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 2000
# //     s consists of lowercase English letters only.
# 
# // User function Template for C++
# #include<iostream>
# #include<vector>
# #include<string>
# using namespace std;
# #include <climits>   // IMPORTANT for INT_MAX
# 
# class Solution {
# public:
#     bool isPalindrome(string &s, int start, int end) {
#         while (start < end) {
#             if (s[start] != s[end]) return false;
#             start++;
#             end--;
#         }
#         return true;
#     }
# 
#     void helper(string &s, int index, int cuts, int &minCuts) {
#         if (index == s.size()) {
#             minCuts = min(minCuts, cuts - 1); 
#             return;
#         }
# 
#         for (int i = index; i < s.size(); i++) {
#             if (isPalindrome(s, index, i)) {
#                 helper(s, i + 1, cuts + 1, minCuts);
#             }
#         }
#     }
# 
#     int palPartition(string &s) {
#         int minCuts = INT_MAX;
#         helper(s, 0, 0, minCuts);
#         return minCuts;
#     }
# };
# 
# class Solution {
#   public:
#       int minCut(string s) {
#           int n = s.size();
#           vector<vector<bool>> pal(n, vector<bool>(n, false));
#   
#           // STEP 1: Precompute palindrome table pal[i][j]
#           for (int gap = 0; gap < n; gap++) {
#               for (int i = 0; i + gap < n; i++) {
#                   int j = i + gap;
#                   if (gap == 0) 
#                       pal[i][j] = true;
#                   else if (gap == 1) 
#                       pal[i][j] = (s[i] == s[j]);
#                   else 
#                       pal[i][j] = (s[i] == s[j] && pal[i+1][j-1]);
#               }
#           }
#   
#           // STEP 2: DP array for minimum cuts
#           vector<int> dp(n, INT_MAX);
#   
#           for (int i = 0; i < n; i++) {
#               if (pal[0][i]) {
#                   // if entire string 0..i is palindrome → zero cut
#                   dp[i] = 0;
#               } else {
#                   // try all possible partitions
#                   for (int j = 0; j < i; j++) {
#                       if (pal[j+1][i] && dp[j] + 1 < dp[i]) {
#                           dp[i] = dp[j] + 1;
#                       }
#                   }
#               }
#           }
#   
#           return dp[n-1];
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
