# 5. Longest Palindromic Substring.py - Python skeleton converted from C++

# Original C++ code:
# // Given a string s, return the longest in s.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "babad"
# // Output: "bab"
# // Explanation: "aba" is also a valid answer.
# 
# // Example 2:
# 
# // Input: s = "cbbd"
# // Output: "bb"
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 1000
# //     s consist of only digits and English letters.
# 
# #include <iostream>
# #include<string>
# using namespace std;
# 
# class Solution {
#   public:
#       string longestPalindrome(string s) {
#           if (s.length() <= 1) return s;
#   
#           int start = 0, maxLen = 1;
#   
#           for (int i = 0; i < s.length(); i++) {
#               // Odd length
#               expand(s, i, i, start, maxLen);
#   
#               // Even length
#               expand(s, i, i + 1, start, maxLen);
#           }
#           return s.substr(start, maxLen);
#       }
#   
#       void expand(string &s, int left, int right, int &start, int &maxLen) {
#           while (left >= 0 && right < s.length() && s[left] == s[right]) {
#               left--;
#               right++;
#           }
#   
#           int len = right - left - 1;
#           if (len > maxLen) {
#               maxLen = len;
#               start = left + 1;
#           }
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
