# Reverse a String using Stack.py - Python skeleton converted from C++

# Original C++ code:
# // You are given a string s , the task is to reverse the string using stack.
# 
# // Examples:
# 
# // Input: s ="GeeksforGeeks"
# // Output:  skeeGrofskeeG
# 
# // Input: s ="Geek"
# // Output: keeG
# 
# // Constraints:
# // 1 ≤ s.length() ≤ 100
# 
# //Reverse a String using Stack
# // Time Complexity: O(n) Only one traversal to push and one to pop so O(n)+O(n) = O(n).
# // Auxiliary Space: O(n) Due to the stack 
# 
# #include <iostream>
# #include <stack>
# using namespace std;
# 
# string reverse(string s) {
#     stack<char> st;
#     
#     // Push all characters onto the stack
#     for (char c : s)
#         st.push(c);
#     
#     // Pop characters to form reversed string
#     string res;
#     while (!st.empty()) {
#         res += st.top();
#         st.pop();
#     }
#     return res;
# }
# 
# int main() {
#     string s = "geeksforgeeks";
#     cout << s << endl;
#     cout << reverse(s) << endl;
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
