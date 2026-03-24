// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"

// Output: 0

// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:

// Input: s = "loveleetcode"

// Output: 2

// Example 3:

// Input: s = "aabb"

// Output: -1

 

// Constraints:

//     1 <= s.length <= 105
//     s consists of only lowercase English letters.

#include <iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// | Approach        | Time   | Space  | Best Use        |
// | --------------- | ------ | ------ | --------------- |
// | Frequency Array | `O(N)` | `O(1)` | ✅ Best          |
// | Queue           | `O(N)` | `O(N)` | Stream problems |

class Solution {
  public:
      int firstUniqChar(string s) {
          vector<int> freq(26, 0);
  
          // Count frequency
          for (char ch : s) {
              freq[ch - 'a']++;
          }
  
          // Find first unique
          for (int i = 0; i < s.size(); i++) {
              if (freq[s[i] - 'a'] == 1) {
                  return i;
              }
          }
  
          return -1;
      }
  };
  
class Solution {
  public:
      int firstUniqChar(string s) {
          vector<int> freq(26, 0);
          queue<int> q;
  
          for (int i = 0; i < s.size(); i++) {
              freq[s[i] - 'a']++;
              q.push(i);
  
              while (!q.empty() && freq[s[q.front()] - 'a'] > 1) {
                  q.pop();
              }
          }
  
          return q.empty() ? -1 : q.front();
      }
  };
