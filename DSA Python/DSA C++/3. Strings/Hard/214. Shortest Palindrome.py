# 214. Shortest Palindrome.py - Python skeleton converted from C++

# Original C++ code:
# // You are given a string s. You can convert s to a by adding characters in front of it.
# 
# // Return the shortest palindrome you can find by performing this transformation.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "aacecaaa"
# // Output: "aaacecaaa"
# 
# // Example 2:
# 
# // Input: s = "abcd"
# // Output: "dcbabcd"
# 
#  
# 
# // Constraints:
# 
# //     0 <= s.length <= 5 * 104
# //     s consists of lowercase English letters only.
# #include <iostream>
# #include <string>
# #include <algorithm>
# using namespace std;
# 
# bool isPalindrome(const string &s, int i, int j) {
#     while (i < j) {
#         if (s[i] != s[j]) return false;
#         i++;
#         j--;
#     }
#     return true;
# }
# 
# string shortestPalindrome(string s) {
#     int n = s.size();
# 
#     // find longest prefix palindrome
#     int end = n - 1;
#     while (end >= 0) {
#         if (isPalindrome(s, 0, end)) break;
#         end--;
#     }
# 
#     // remaining part
#     string suffix = s.substr(end + 1);
# 
#     // reverse suffix
#     reverse(suffix.begin(), suffix.end());
# 
#     // add in front
#     return suffix + s;
# }
# 
# 
# class Solution {
#   public:
#   
#   vector<int> computeLPS(string s) {
#       int n = s.size();
#       vector<int> lps(n, 0);
#   
#       for (int i = 1, len = 0; i < n; ) {
#           if (s[i] == s[len]) {
#               lps[i++] = ++len;
#           } else {
#               if (len != 0) {
#                   len = lps[len - 1];
#               } else {
#                   lps[i++] = 0;
#               }
#           }
#       }
#       return lps;
#   }
#   
#       string shortestPalindrome(string s) {
#           
#      string rev = s;
#       reverse(rev.begin(), rev.end());
#   
#       string temp = s + "#" + rev;
#   
#       vector<int> lps = computeLPS(temp);
#   
#       int len = lps.back(); // longest palindromic prefix
#   
#       return rev.substr(0, s.size() - len) + s;
#       }
#   };
#   int main() {
#     string s;
#     cin >> s;
#     cout << shortestPalindrome(s);
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
