// Given two strings s and t of lengths m and n respectively, return the minimum window of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

 

// Constraints:

//     m == s.length
//     n == t.length
//     1 <= m, n <= 105
//     s and t consist of uppercase and lowercase English letters.

 

// Follow up: Could you find an algorithm that runs in O(m + n) time?


#include <iostream>
#include<vector>
using namespace std;

// Time Complexity:O(n3)
// Space Complexity:O(1)
class Solution {
  public:
      bool isValid(string &s, string &t) {
          vector<int> freq(128, 0);
  
          // count characters of substring
          for(char c : s) freq[c]++;
  
          // check if it satisfies t
          for(char c : t) {
              if(freq[c] == 0) return false;
              freq[c]--;
          }
          return true;
      }
  
      string minWindow(string s, string t) {
          int n = s.size();
          int minLen = INT_MAX;
          string ans = "";
  
          for(int i = 0; i < n; i++) {
              for(int j = i; j < n; j++) {
                  string sub = s.substr(i, j - i + 1);
  
                  if(isValid(sub, t)) {
                      if(sub.size() < minLen) {
                          minLen = sub.size();
                          ans = sub;
                      }
                  }
              }
          }
  
          return ans;
      }
  };


  class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char, int> need;
            for(char c : t) need[c]++;
    
            int left = 0, right = 0;
            int count = 0;
            int minLen = INT_MAX, start = 0;
    
            while(right < s.size()) {
                char c = s[right];
    
                if(need[c] > 0) count++;
                need[c]--;
    
                right++;
    
                // when all characters matched
                while(count == t.size()) {
                    if(right - left < minLen) {
                        minLen = right - left;
                        start = left;
                    }
    
                    char leftChar = s[left];
                    need[leftChar]++;
    
                    if(need[leftChar] > 0) count--;
    
                    left++;
                }
            }
    
            return minLen == INT_MAX ? "" : s.substr(start, minLen);
        }
    };