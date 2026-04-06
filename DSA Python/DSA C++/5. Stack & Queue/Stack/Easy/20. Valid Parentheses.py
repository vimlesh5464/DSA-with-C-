# 20. Valid Parentheses.py - Python skeleton converted from C++

# Original C++ code:
# // Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
# // determine if the input string is valid.
# 
# // An input string is valid if:
# //     Open brackets must be closed by the same type of brackets.
# //     Open brackets must be closed in the correct order.
# //     Every close bracket has a corresponding open bracket of the same type.
# 
#  
# 
# // Example 1:
# // Input: s = "()"
# // Output: true
# 
# // Example 2:
# // Input: s = "()[]{}"
# // Output: true
# 
# // Example 3:
# // Input: s = "(]"
# // Output: false
# 
# // Example 4:
# // Input: s = "([])"
# // Output: true
# 
# // Example 5:
# // Input: s = "([)]"
# // Output: false
# // Constraints:
# 
# //     1 <= s.length <= 104
# //     s consists of parentheses only '()[]{}'.
# 
# 
# #include <iostream>
# #include <stack>
# #include <vector>
# #include <string>
# using namespace std;
# 
# //[Approach 1] Using Stack - O(n) Time and O(n) Space
# bool isBalanced(string& s) {
#    
#     stack<char> st; 
#    
#     for (char c : s) {
#         if (c == '(' || c == '{' || c == '[') {
#             st.push(c);
#         }
#         
#         else if (c == ')' || c == '}' || c == ']') {
#             
#             // No opening bracket
#             if (st.empty()) return false; 
#             char top = st.top();
#             if ((c == ')' && top != '(') ||
#                 (c == '}' && top != '{') ||
#                 (c == ']' && top != '[')) {
#                 return false;
#             }
#             
#             // Pop matching opening bracket
#             st.pop(); 
#         }
#     }
#     
#     // Balanced if stack is empty
#     return st.empty(); 
# }
# 
# //[Approach 2] Without using Stack - O(n) Time and O(1) Space
# bool isBalanced(string& s) {
#     
#   // stack top index in string
#   int top = -1;
#   for (int i = 0; i < s.length(); i++) {
#       if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
#           
#           // push opening bracket
#           s[++top] = s[i]; 
#       } 
#       else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
#           
#           // no opening bracket
#           if (top == -1) return false; 
#           if ((s[i] == ')' && s[top] != '(') ||
#               (s[i] == '}' && s[top] != '{') ||
#               (s[i] == ']' && s[top] != '[')) {
#               return false;
#           }
#           top--;
#       }
#   }
#   
#   // balanced if stack empty
#   return top == -1; 
# }
# 
# int main() {
#   string s;
#   cin >> s;  // take input from user
# 
#   cout << (isBalanced(s) ? "true" : "false") << endl;
# 
#   return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
