# 14. Longest Common Prefix.py - Python skeleton converted from C++

# Original C++ code:
# // Write a function to find the longest common prefix string amongst an array of strings.
# 
# // If there is no common prefix, return an empty string "".
# 
#  
# 
# // Example 1:
# 
# // Input: strs = ["flower","flow","flight"]
# // Output: "fl"
# 
# // Example 2:
# 
# // Input: strs = ["dog","racecar","car"]
# // Output: ""
# // Explanation: There is no common prefix among the input strings.
# 
#  
# 
# // Constraints:
# 
# //     1 <= strs.length <= 200
# //     0 <= strs[i].length <= 200
# //     strs[i] consists of only lowercase English letters if it is non-empty.
# 
# #include<iostream>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#       string longestCommonPrefix(vector<string>& strs) {
#           if(strs.empty()){
#               return " ";
#           }
#          int n = strs.size();
#          string str = strs[0];
#          for(int i = 1; i < n; i++){
#           while(strs[i].find(str)!=0){
#               str=str.substr(0, str.size() - 1);
#           }
#          }
#          return str;
#       }
#   };
# 
# //   📊 Priority (Follow This Order)
# // 🥇 Must Do First:
# // Next Permutation
# // Largest Number
# // Lexicographical Numbers
# // K-th Smallest Lexicographical
# // 🥈 Then:
# // Reorder Logs
# // Alien Dictionary
# // Remove Duplicate Letters
# // 🥉 Advanced:
# // Orderly Queue
# // Smallest String With Swaps

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
