# 921. Minimum Add to Make Parentheses Valid.py - Python skeleton converted from C++

# Original C++ code:
# // A parentheses string is valid if and only if:
# 
# //     It is the empty string,
# //     It can be written as AB (A concatenated with B), where A and B are valid strings, or
# //     It can be written as (A), where A is a valid string.
# 
# // You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
# 
# //     For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
# 
# // Return the minimum number of moves required to make s valid.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "())"
# // Output: 1
# 
# // Example 2:
# 
# // Input: s = "((("
# // Output: 3
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 1000
# //     s[i] is either '(' or ')'.
# 
# #include<iostream>
# #include <string>
# #include<stack>
# using namespace std;
# 
# 
# //Time Complexity = O(n)
# //Space Complexity = O(n)
# class Solution {
#   public:
#       int minParentheses(string& s) {
#           stack<char> st; 
#           int count = 0;
#   
#           for (char c : s) {
#               if (c == '(') {
#                   st.push(c);
#               }
#               else if (c == ')') {
#                   if (!st.empty() && st.top() == '(') {
#                       st.pop();   // match mila, remove '('
#                   } else {
#                       count++;   // extra ')' mila
#                   }
#               }
#           }
#   
#           // count = extra ')'
#           // st.size() = unmatched '('
#           return count + st.size(); 
#       }
#   };
# 
# 
# //Time Complexity = O(n)
# //Space Complexity = O(1)
# class Solution {
# public:
#     int minAddToMakeValid(string s) {
#         int balance = 0, res = 0;
#         for (char c : s) {
#             if (c == '(') {
#                 balance++;
#             } else { // c == ')'
#                 if (balance > 0) balance--;
#                 else res++;
#             }
#         }
#         return res + balance;
#     }
# };
# 
# // ---------------- MAIN ----------------
# int main() {
#     string s;
#     cin >> s;
# 
#     Solution sol;
#     cout << sol.minAddToMakeValid(s) << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
