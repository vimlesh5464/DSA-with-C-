# Postfix to Prefix Conversion.py - Python skeleton converted from C++

# Original C++ code:
# // You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.
# 
# // Example 1:
# 
# // Input: 
# // ABC/-AK/L-*
# // Output: 
# // *-A/BC-/AKL
# // Explanation: 
# // The above output is its valid prefix form.
# 
# // Example 2:
# 
# // Input: 
# // ab+
# // Output: 
# // +ab
# // Explanation: 
# // The above output is its valid prefix form.
# 
# // Your Task:
# 
# // Complete the function string postToPre(string post_exp), which takes a postfix string as input and returns its prefix form.
# 
# // Expected Time Complexity: O(post_exp.length()).
# 
# // Expected Auxiliary Space: O(post_exp.length()).
# 
# // Constraints:
# 
# // 3<=post_exp.length()<=16000
# //Postfix to Prefix Conversion
# // Time Complexity: O(N)
# // (We traverse the expression once, each operation is constant time.)
# // Auxiliary Space: O(N)
# // (Stack stores up to N elements in the worst case.)
# // CPP Program to convert postfix to prefix
# #include <iostream>
# #include <stack>
# using namespace std;
# 
# // function to check if character is operator or not
# bool isOperator(char x)
# {
#     switch (x) {
#     case '+':
#     case '-':
#     case '/':
#     case '*':
#         return true;
#     }
#     return false;
# }
# 
# // Convert postfix to Prefix expression
# string postToPre(string post_exp)
# {
#     stack<string> s;
# 
#     // length of expression
#     int length = post_exp.size();
# 
#     // reading from left to right
#     for (int i = 0; i < length; i++) {
# 
#         // check if symbol is operator
#         if (isOperator(post_exp[i])) {
# 
#             // pop two operands from stack
#             string op1 = s.top();
#             s.pop();
#             string op2 = s.top();
#             s.pop();
# 
#             // concat the operands and operator
#             string temp = post_exp[i] + op2 + op1;
# 
#             // Push string temp back to stack
#             s.push(temp);
#         }
# 
#         // if symbol is an operand
#         else {
# 
#             // push the operand to the stack
#             s.push(string(1, post_exp[i]));
#         }
#     }
# 
#     string ans = "";
#     while (!s.empty()) {
#         ans += s.top();
#         s.pop();
#     }
#     return ans;
# }
# 
# // Driver Code
# int main()
# {
#     string post_exp = "ABC/-AK/L-*";
# 
#     // Function call
#     cout << "Prefix : " << postToPre(post_exp);
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
