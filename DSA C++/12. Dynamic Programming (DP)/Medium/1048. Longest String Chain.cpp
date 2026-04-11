// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

//     For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

 

// Constraints:

//     1 <= words.length <= 1000
//     1 <= words[i].length <= 16
//     words[i] only consists of lowercase English letters.



#include <iostream>
#include<vector>
using namespace std;
// Time Complexity: O(n^2 * m) , where n is the number of words and m is the average length of the words. This is because we are checking each word against all previous words to see if it can be formed by adding one character.

// Space Complexity: O(n) , where n is the number of words. This is due to the storage of the DP array which keeps track of the longest chain length for each word. 
class Solution {
  public:
      // Function to return the length of the longest string chain possible
      int longestStrChain(vector<string>& words) {
          int n = words.size(); // Size of the array
          sort(words.begin(), words.end(), compare);
          vector<int> dp(n, 1); // DP array
  
          // To store the length of longest string chain
          int maxLen = 0;
  
          // Computing the DP array
          for (int i = 0; i < n; i++) {
  
              // For each previous index
              for (int j = 0; j < i; j++) {
  
                  /* If the element at index i can be
                  included in the chain ending at index j */
                  if (checkPossible(words[i], words[j]) && dp[i] < dp[j] + 1) {
                      dp[i] = dp[j] + 1; // Update the DP value
                  }
              }
  
              // If a longer chain is found, update the values
              if (dp[i] > maxLen)
                  maxLen = dp[i];
          }
  
          return maxLen;
      }
  
  private:
      // Custom comparator function
      bool static compare(string& s, string& t) { return s.size() < t.size(); }
  
      // Function to check if the string can be added to the chain
      bool checkPossible(string& s, string& t) {
          //  Base case
          if (s.size() != t.size() + 1)
              return false;
  
          int i = 0, j = 0; // Pointers
  
          // Traverse until the first string is exhausted
          while (i < s.size()) {
  
              // Move both pointers if characters matches
              if (j < t.size() && s[i] == t[j]) {
                  i++, j++;
              }
              // Otherwise
              else {
                  i++;
              }
          }
  
          // Return true if both the string gets exhausted
          if (i == s.size() && j == t.size())
              return true;
          return false; // Return false otherwise
      }
  };