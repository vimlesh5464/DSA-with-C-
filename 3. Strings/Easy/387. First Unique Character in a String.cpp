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
