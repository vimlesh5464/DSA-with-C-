# 1021. Remove Outermost Parentheses.py - Python skeleton converted from C++

# Original C++ code:
# // A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
# 
# //     For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
# 
# // A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
# 
# // Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
# 
# // Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "(()())(())"
# // Output: "()()()"
# // Explanation: 
# // The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
# // After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
# 
# // Example 2:
# 
# // Input: s = "(()())(())(()(()))"
# // Output: "()()()()(())"
# // Explanation: 
# // The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
# // After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
# 
# // Example 3:
# 
# // Input: s = "()()"
# // Output: ""
# // Explanation: 
# // The input string is "()()", with primitive decomposition "()" + "()".
# // After removing outer parentheses of each part, this is "" + "" = "".
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 105
# //     s[i] is either '(' or ')'.
# //     s is a valid parentheses string.
# 
# #include<iostream>
# #include<stack>
# #include<string>
#  using namespace std;
# 
# // | Approach          | Time | Space | Notes                           |
# // | ----------------- | ---- | ----- | ------------------------------- |
# // | **Stack**         | O(n) | O(n)  | More intuitive, but extra stack |
# // | **Depth Counter** | O(n) | O(n)  | Cleaner, faster, preferred      |
# 
# 
# class Solution {
#   public:
#       string removeOuterParentheses(string s) {
#           stack<char> st;
#           string ans = "";
#   
#           for (char c : s) {
#               if (c == '(') {
#                   if (!st.empty())
#                       ans += c;
#                   st.push(c);
#               } else { // ')'
#                   st.pop();
#                   if (!st.empty())
#                       ans += c;
#               }
#           }
#           return ans;
#       }
#   };
# 
#   class Solution {
#     public:
#         string removeOuterParentheses(string s) {
#             string result = "";
#             int depth = 0;
#     
#             for (char c : s) {
#                 if (c == '(') {
#                     if (depth > 0) result += c;
#                     depth++;
#                 } else {
#                     depth--;
#                     if (depth > 0) result += c;
#                 }
#             }
#             return result;
#         }
#     };
#   int main() {
#     Solution obj;
#     string s;
# 
#     cout << "Enter parentheses string: ";
#     cin >> s;
# 
#     cout << "Result: " << obj.removeOuterParentheses(s) << endl;
#     return 0;
# }  

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
