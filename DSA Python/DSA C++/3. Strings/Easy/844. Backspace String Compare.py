# 844. Backspace String Compare.py - Python skeleton converted from C++

# Original C++ code:
# // Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
# 
# // Note that after backspacing an empty text, the text will continue empty.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "ab#c", t = "ad#c"
# // Output: true
# // Explanation: Both s and t become "ac".
# 
# // Example 2:
# 
# // Input: s = "ab##", t = "c#d#"
# // Output: true
# // Explanation: Both s and t become "".
# 
# // Example 3:
# 
# // Input: s = "a#c", t = "b"
# // Output: false
# // Explanation: s becomes "c" while t becomes "b".
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length, t.length <= 200
# //     s and t only contain lowercase letters and '#' characters.
# 
# #include <iostream>
# #include<string>
# using namespace std;
# class Solution {
#   public:
#       bool backspaceCompare(string s, string t) {
#           int i = s.size() - 1;
#           int j = t.size() - 1;
#   
#           int skipS = 0;
#           int skipT = 0;
#   
#           while (i >= 0 || j >= 0) {
#               
#               // Process s
#               while (i >= 0) {
#                   if (s[i] == '#') {
#                       skipS++;
#                       i--;
#                   } else if (skipS > 0) {
#                       skipS--;
#                       i--;
#                   } else {
#                       break;
#                   }
#               }
#   
#               // Process t
#               while (j >= 0) {
#                   if (t[j] == '#') {
#                       skipT++;
#                       j--;
#                   } else if (skipT > 0) {
#                       skipT--;
#                       j--;
#                   } else {
#                       break;
#                   }
#               }
#   
#               // Compare characters
#               if (i >= 0 && j >= 0 && s[i] != t[j])
#                   return false;
#   
#               // If one string finished but the other didn’t
#               if ((i >= 0) != (j >= 0))
#                   return false;
#   
#               i--; j--;
#           }
#   
#           return true;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
