// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

 

// Constraints:

//     1 <= strs.length <= 200
//     0 <= strs[i].length <= 200
//     strs[i] consists of only lowercase English letters if it is non-empty.

 
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
  public:
      string longestCommonPrefix(vector<string>& strs) {
          // If the input array is empty, there is no common prefix
          if (strs.empty()) return "";
  
          // Start by assuming the whole first string is the common prefix
          string prefix = strs[0];
  
          // Compare this prefix with each string in the array
          for (int i = 1; i < strs.size(); i++) {
              // While the current string does not start with the prefix
              while (strs[i].find(prefix) != 0) {
                  // Remove the last character from the prefix
                  prefix = prefix.substr(0, prefix.size() - 1);
  
                  // If prefix becomes empty, there is no common prefix
                  if (prefix.empty()) return "";
              }
          }
  
          // Return the longest common prefix after comparing with all strings
          return prefix;
      }
  };