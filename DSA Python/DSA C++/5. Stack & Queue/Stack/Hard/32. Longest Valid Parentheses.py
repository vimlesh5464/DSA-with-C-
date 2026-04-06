# 32. Longest Valid Parentheses.py - Python skeleton converted from C++

# Original C++ code:
# #include<iostream>
# #include<vector>
# #include<stack>
# using namespace std;
# 
# class Solution {
#   public:
#       int longestValidParentheses(string s) {
#           stack<int> st;
#           st.push(-1);
#           int ans = 0;
#   
#           for (int i = 0; i < s.length(); i++) {
#               if (s[i] == '(') {
#                   st.push(i);
#               } else {
#                   st.pop();
#                   if (st.empty()) {
#                       st.push(i);
#                   } else {
#                       ans = max(ans, i - st.top());
#                   }
#               }
#           }
#           return ans;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
