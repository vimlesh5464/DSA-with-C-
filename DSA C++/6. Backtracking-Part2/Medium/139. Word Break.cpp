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
      bool wordBreakUtil(string s, unordered_set<string> dict, int start) {
          if (start == s.size())
              return true;
  
          if(dict.find(s)!=dict.end()){
              return true;
          }    
          for (int end = start + 1; end <= s.size(); end++) {
              if (dict.count(s.substr(start, end - start)) &&
                  wordBreakUtil(s, dict, end))
                  return true;
          }
          return false;
      }
      bool wordBreak(string s, vector<string>& wordDict) {
          unordered_set<string> dict(wordDict.begin(), wordDict.end());
          // vector<int> dp(s.size(), -1);
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