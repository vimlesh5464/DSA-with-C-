# 205. Isomorphic Strings.py - Python skeleton converted from C++

# Original C++ code:
# // Given two strings s and t, determine if they are isomorphic.
# 
# // Two strings s and t are isomorphic if the characters in s can be replaced to get t.
# 
# // All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "egg", t = "add"
# 
# // Output: true
# 
# // Explanation:
# 
# // The strings s and t can be made identical by:
# 
# //     Mapping 'e' to 'a'.
# //     Mapping 'g' to 'd'.
# 
# // Example 2:
# 
# // Input: s = "f11", t = "b23"
# 
# // Output: false
# 
# // Explanation:
# 
# // The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.
# 
# // Example 3:
# 
# // Input: s = "paper", t = "title"
# 
# // Output: true
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length <= 5 * 104
# //     t.length == s.length
# //     s and t consist of any valid ascii character.
# 
#  
# 
# #include<iostream>
# #include<unordered_map>
# using namespace std;
# 
# class Solution {
#   public:
#       bool isIsomorphic(string s, string t) {
#           if (s.length() != t.length()) return false;
#   
#           unordered_map<char, char> mp1, mp2;
#   
#           for (int i = 0; i < s.length(); i++) {
#               char a = s[i], b = t[i];
#   
#               if (mp1.find(a)!=mp1.end() && mp1[a] != b) return false;
#               if (mp2.find(b) !=mp2.end() && mp2[b] != a) return false;
#   
#               mp1[a] = b;
#               mp2[b] = a;
#           }
#           return true;
#       }
#   };
#   int main() {
#     Solution obj;
#     string s, t;
# 
#     cout << "Enter first string: ";
#     cin >> s;
#     cout << "Enter second string: ";
#     cin >> t;
# 
#     if (obj.isIsomorphic(s, t))
#         cout << "Strings are Isomorphic" << endl;
#     else
#         cout << "Strings are NOT Isomorphic" << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
