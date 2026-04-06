# 1614. Maximum Nesting Depth of the Parentheses.py - Python skeleton converted from C++

# Original C++ code:
# // Given a valid parentheses string s, return the nesting depth of s. 
# //The nesting depth is the maximum number of nested parentheses.
# // Example 1:
# 
# // Input: s = "(1+(2*3)+((8)/4))+1"
# 
# // Output: 3
# 
# // Explanation:
# 
# // Digit 8 is inside of 3 nested parentheses in the string.
# 
# // Example 2:
# 
# // Input: s = "(1)+((2))+(((3)))"
# 
# // Output: 3
# 
# // Explanation:
# 
# // Digit 3 is inside of 3 nested parentheses in the string.
# 
# // Example 3:
# 
# // Input: s = "()(())((()()))"
# 
# // Output: 3
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 100
# //     s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
# //     It is guaranteed that parentheses expression s is a VPS.
# 
#  
# #include <iostream>
# #include <string>
# 
# using namespace std;
# 
# int user_logic(int n, string s) {
#     int count = 0;
#     int max_count = 0;
#     for(int i = 0; i < n; i++){
#         if(s[i]=='('){
#             count++;
#         }else if (s[i]==')'){ 
#             max_count = max(max_count,count);
#             count = 0;
#         }
#     }
#     return max_count;
# }
# 
# int main() {
#     int n;
#     string s;
#     cin >> n >> s;
#     int result = user_logic(n, s);
#     cout << result << endl;
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
