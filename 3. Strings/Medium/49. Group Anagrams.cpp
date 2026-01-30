#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// | Metric               | Complexity   |
// | -------------------- | ------------ |
// | **Time Complexity**  | **O(n · k)** |
// | **Space Complexity** | **O(n · k)** |

class Solution {
  public:
      vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map<string, vector<string>> mp;
          
          for (string s : strs) {
              vector<int> freq(26, 0);
              for (char c : s) freq[c - 'a']++;  // count letters
  
              // convert frequency array to string key
              string key = "";
              for (int i = 0; i < 26; i++) {
                  key += to_string(freq[i]) + '#'; // '#' separates counts
              }
  
              mp[key].push_back(s);  // group anagrams
          }
  
          vector<vector<string>> result;
          //for (const pair<const string, vector<string>>& it : mp)

          for (auto it : mp) result.push_back(it.second);
  
          return result;
      }
  };
  