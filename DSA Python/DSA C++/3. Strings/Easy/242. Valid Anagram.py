# 242. Valid Anagram.py - Python skeleton converted from C++

# Original C++ code:
# // Given two strings s and t, return true if t is an of s, and false otherwise.
# 
#  
# 
# // Example 1:
# 
# // Input: s = "anagram", t = "nagaram"
# 
# // Output: true
# 
# // Example 2:
# 
# // Input: s = "rat", t = "car"
# 
# // Output: false
# 
#  
# 
# // Constraints:
# 
# //     1 <= s.length, t.length <= 5 * 104
# //     s and t consist of lowercase English letters.
# 
#  
# 
# // Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
# #include <iostream>
# #include<string>
# #include<vector>
# using namespace std;
# 
# class Solution {
#   public:
#       bool isAnagram(string s, string t) {
#           if (s.length() != t.length()) return false;
#           for( int i = 0; i < s.length(); i++){
#               bool found = false;
#               for(int j = 0; j < t.length(); j++){
#                   if(s[i]==t[j]){
#                       t[j]='#';
#                       found = true;
#                       break;
#                   }
#               }
#               if (!found) return false;
#           }
#           return true;
#       }
#   };
# class Solution {
# public:
#     bool isAnagram(string s, string t) {
#         if (s.length() != t.length()) return false;
# 
#         vector<int> count(26, 0); // for lowercase a-z
# 
#         for (int i = 0; i < s.length(); i++) {
#             count[s[i] - 'a']++;
#             count[t[i] - 'a']--;
#         }
# 
#         for (int i = 0; i < 26; i++) {
#             if (count[i] != 0) return false;
#         }
# 
#         return true;
#     }
# };
# 
# // Driver code for testing
# int main() {
#     Solution sol;
# 
#     string s1 = "anagram", t1 = "nagaram";
#     string s2 = "rat", t2 = "car";
#     string s3 = "listen", t3 = "silent";
# 
#     cout << (sol.isAnagram(s1, t1) ? "true" : "false") << endl; // true
#     cout << (sol.isAnagram(s2, t2) ? "true" : "false") << endl; // false
#     cout << (sol.isAnagram(s3, t3) ? "true" : "false") << endl; // true
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
