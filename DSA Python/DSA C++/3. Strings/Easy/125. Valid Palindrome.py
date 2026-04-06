# 125. Valid Palindrome.py - Python skeleton converted from C++

# Original C++ code:
# // A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
# 
# // Given a string s, return true if it is a palindrome, or false otherwise.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "A man, a plan, a canal: Panama"
# // Output: true
# // Explanation: "amanaplanacanalpanama" is a palindrome.
# 
# // Example 2:
# 
# // Input: s = "race a car"
# // Output: false
# // Explanation: "raceacar" is not a palindrome.
# 
# // Example 3:
# 
# // Input: s = " "
# // Output: true
# // Explanation: s is an empty string "" after removing non-alphanumeric characters.
# // Since an empty string reads the same forward and backward, it is a palindrome.
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 2 * 105
# //     s consists only of printable ASCII characters.
# 
#  
# #include <iostream>
# #include<string>
# using namespace std;
# 
# class Solution {
# public:
#     bool isPalindrome(string s) {
#         int left = 0, right = s.length() - 1;
# 
#         while (left < right) {
#             // Skip non-alphanumeric characters
#             while (left < right && !isalnum(s[left])) left++;
#             while (left < right && !isalnum(s[right])) right--;
# 
#             // Compare lowercase characters
#             if (tolower(s[left]) != tolower(s[right])) {
#                 return false;
#             }
# 
#             left++;
#             right--;
#         }
# 
#         return true;
#     }
# };
# 
# // Driver code for local testing
# int main() {
#     Solution sol;
# 
#     string test1 = "A man, a plan, a canal: Panama";
#     string test2 = "race a car";
#     string test3 = " ";
# 
#     cout << (sol.isPalindrome(test1) ? "true" : "false") << endl; // true
#     cout << (sol.isPalindrome(test2) ? "true" : "false") << endl; // false
#     cout << (sol.isPalindrome(test3) ? "true" : "false") << endl; // true
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
