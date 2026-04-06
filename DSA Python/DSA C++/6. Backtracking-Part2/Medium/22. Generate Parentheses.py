# 22. Generate Parentheses.py - Python skeleton converted from C++

# Original C++ code:
# // Given n pairs of parentheses, write a function to generate all combinations of well-formed 
# //parentheses.
# 
# // Example 1:
# // Input: n = 3
# // Output: ["((()))","(()())","(())()","()(())","()()()"]
# 
# // Example 2:
# // Input: n = 1
# // Output: ["()"]
# 
# // Constraints:
# 
# //     1 <= n <= 8
# 
# #include<iostream>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#       void backtrack(vector<string>& result, string current, int open, int close, int n) {
#           if (current.size() == 2 * n) {
#               result.push_back(current);
#               return;
#           }
#   
#           if (open < n) {
#               backtrack(result, current + '(', open + 1, close, n);
#           }
#   
#           if (close < open) {
#               backtrack(result, current + ')', open, close + 1, n);
#           }
#       }
#   
#       vector<string> generateParenthesis(int n) {
#           vector<string> result;
#           backtrack(result, "", 0, 0, n);
#           return result;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
