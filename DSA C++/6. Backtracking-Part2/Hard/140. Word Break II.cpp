// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.

// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []

 

// Constraints:

//     1 <= s.length <= 20
//     1 <= wordDict.length <= 1000
//     1 <= wordDict[i].length <= 10
//     s and wordDict[i] consist of only lowercase English letters.
//     All the strings of wordDict are unique.
//     Input is generated in a way that the length of the answer doesn't exceed 105.
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
  public:
  vector<string> dfs(string &s,unordered_set<string> dict){
      if(s.empty()){
          return {""};
      }
      vector<string>result;
      for(int i = 1; i <= s.size(); i++){
          string currentword = s.substr(0,i);
          if(dict.count(currentword)){
              string remaininfword = s.substr(i);
              vector<string> remainasns = dfs(remaininfword,dict);
              for(string &word : remainasns){
                  string add = currentword + (word.empty()?"": " ") + word;
                  result.push_back(add);
              }
          }
      }
  
      return result;
  }
      vector<string> wordBreak(string s, vector<string>& wordDict) {
          
          unordered_set<string> dict(wordDict.begin(), wordDict.end());
          return dfs(s,dict);
      }
  };

  class Solution {
    public:
        // dfs with memoization
        vector<string> dfs(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
            if(memo.count(s)) return memo[s];  // return memoized result
            vector<string> result;
    
            if(s.empty()) {
                result.push_back("");  // base case
                return result;
            }
    
            for(int i = 1; i <= s.size(); i++) {
                string currentWord = s.substr(0, i);
                if(dict.count(currentWord)) {
                    string remaining = s.substr(i);
                    vector<string> sublist = dfs(remaining, dict, memo);  // recursive call
                    for(string &word : sublist) {
                        string sentence = currentWord + (word.empty() ? "" : " " + word);
                        result.push_back(sentence);
                    }
                }
            }
    
            return memo[s] = result;  // store result in memo
        }
    
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            unordered_map<string, vector<string>> memo;  // memoization map
            return dfs(s, dict, memo);
        }
    };