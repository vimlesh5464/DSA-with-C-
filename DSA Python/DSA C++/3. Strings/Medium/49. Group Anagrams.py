# 49. Group Anagrams.py - Python skeleton converted from C++

# Original C++ code:
# // Given an array of strings strs, group the together. You can return the answer in any order.
# 
#  
# 
# // Example 1:
# 
# // Input: strs = ["eat","tea","tan","ate","nat","bat"]
# 
# // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
# 
# // Explanation:
# 
# //     There is no string in strs that can be rearranged to form "bat".
# //     The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
# //     The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
# 
# // Example 2:
# 
# // Input: strs = [""]
# 
# // Output: [[""]]
# 
# // Example 3:
# 
# // Input: strs = ["a"]
# 
# // Output: [["a"]]
# 
#  
# 
# // Constraints:
# 
# //     1 <= strs.length <= 104
# //     0 <= strs[i].length <= 100
# //     strs[i] consists of lowercase English letters.
# 
#  
# #include <iostream>
# #include<string>
# #include<vector>
# #include<unordered_map>
# using namespace std;
# 
# // | Metric               | Complexity   |
# // | -------------------- | ------------ |
# // | **Time Complexity**  | **O(n · k)** |
# // | **Space Complexity** | **O(n · k)** |
# 
# class Solution {
#   public:
#       vector<vector<string>> groupAnagrams(vector<string>& strs) {
#           unordered_map<string, vector<string>> mp;
#           
#           for (string s : strs) {
#               vector<int> freq(26, 0);
#               for (char c : s) freq[c - 'a']++;  // count letters
#   
#               // convert frequency array to string key
#               string key = "";
#               for (int i = 0; i < 26; i++) {
#                   key += to_string(freq[i]) + '#'; // '#' separates counts
#               }
#   
#               mp[key].push_back(s);  // group anagrams
#           }
#   
#           vector<vector<string>> result;
#           //for (const pair<const string, vector<string>>& it : mp)
# 
#           for (auto it : mp) result.push_back(it.second);
#   
#           return result;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
