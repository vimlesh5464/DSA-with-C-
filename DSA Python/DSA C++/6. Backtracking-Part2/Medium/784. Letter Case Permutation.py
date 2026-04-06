# 784. Letter Case Permutation.py - Python skeleton converted from C++

# Original C++ code:
# // Given a string s, you can transform every letter individually to be 
# //lowercase or uppercase to create another string.
# 
# // Return a list of all possible strings we could create. Return the output
# // in any order.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "a1b2"
# // Output: ["a1b2","a1B2","A1b2","A1B2"]
# 
# // Example 2:
# 
# // Input: s = "3z4"
# // Output: ["3z4","3Z4"]
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 12
# //     s consists of lowercase English letters, uppercase English letters, and digits.
# 
# #include<iostream>
# #include<vector>
# #include<string>
# using namespace std;
# class Solution {
#   public:
#       void solve(string &s, int idx, string &current, vector<string> &ans) {
#   
#           // If full string processed → push answer
#           if (idx == s.size()) {
#               ans.push_back(current);
#               return;
#           }
#   
#           char c = s[idx];
#   
#           // If digit → only one choice
#           if (isdigit(c)) {
#               current.push_back(c);
#               solve(s, idx + 1, current, ans);
#               current.pop_back();
#           } 
#           else {
#               // Lowercase branch
#               current.push_back(tolower(c));
#               solve(s, idx + 1, current, ans);
#               current.pop_back();
#   
#               // Uppercase branch
#               current.push_back(toupper(c));
#               solve(s, idx + 1, current, ans);
#               current.pop_back();
#           }
#       }
#   
#       vector<string> letterCasePermutation(string s) {
#           vector<string> ans;
#           string current = "";
#           solve(s, 0, current, ans);
#           return ans;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
