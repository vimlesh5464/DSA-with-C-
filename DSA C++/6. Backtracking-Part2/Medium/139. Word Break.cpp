// Given a string s and a dictionary of strings wordDict, return true if s can be 
//segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

 

// Constraints:

//     1 <= s.length <= 300
//     1 <= wordDict.length <= 1000
//     1 <= wordDict[i].length <= 20
//     s and wordDict[i] consist of only lowercase English letters.
//     All the strings of wordDict are unique.
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
  public:
  
      // Recursive helper function to check if string can be segmented
      bool wordBreakUtil(string s, unordered_set<string> dict, int start) {
          
          // ✅ Base case: if we reached end of string → valid segmentation
          if (start == s.size())
              return true;
  
          // ⚠️ Optimization: if whole string exists in dictionary
          if (dict.find(s) != dict.end()) {
              return true;
          }
  
          // 🔁 Try all possible substrings starting from 'start'
          for (int end = start + 1; end <= s.size(); end++) {
  
              // ✂️ Extract substring from 'start' to 'end'
              string word = s.substr(start, end - start);
  
              // ✅ If substring exists in dictionary
              // AND remaining string can also be segmented
              if (dict.count(word) &&
                  wordBreakUtil(s, dict, end)) {
                  return true;
              }
          }
  
          // ❌ No valid segmentation found
          return false;
      }
  
      bool wordBreak(string s, vector<string>& wordDict) {
  
          // 🔄 Convert vector to unordered_set for O(1) lookup
          unordered_set<string> dict(wordDict.begin(), wordDict.end());
  
          // 🚀 Start recursion from index 0
          return wordBreakUtil(s, dict, 0);
      }
  };

  class Solution {
    public:
        bool wordBreakUtil(string &s, unordered_set<string> &dict, int start, vector<int> &dp) {
            if(start == s.size()) return true;
            if(dp[start] != -1) return dp[start];
    
            for(int end = start+1; end <= s.size(); end++) {
                if(dict.count(s.substr(start, end-start)) && wordBreakUtil(s, dict, end, dp))
                    return dp[start] = 1;
            }
            return dp[start] = 0;
        }
    
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            vector<int> dp(s.size(), -1);
            return wordBreakUtil(s, dict, 0, dp);
        }
    };

    class Solution {
      public:
          bool wordBreak(string &s, vector<string> &dictionary) {
              unordered_set<string> dict(dictionary.begin(), dictionary.end());
              int n = s.size();
              vector<bool> dp(n + 1, false);
              dp[0] = true; // empty string is valid
      
              for (int i = 1; i <= n; i++) {
                  for (int j = 0; j < i; j++) {
                      if (dp[j] && dict.count(s.substr(j, i - j))) {
                          dp[i] = true;
                          break; // early stop for efficiency
                      }
                  }
              }
              return dp[n];
          }
      };