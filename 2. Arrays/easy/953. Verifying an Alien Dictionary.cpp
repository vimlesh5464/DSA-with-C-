#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
  public:
      bool isAlienSorted(vector<string>& words, string order) {
          // Mapping for alien order
          vector<int> rank(26);
          for (int i = 0; i < 26; i++) {
              rank[order[i] - 'a'] = i;
          }
  
          // Compare each adjacent pair
          for (int i = 0; i < words.size() - 1; i++) {
              if (!inCorrectOrder(words[i], words[i + 1], rank)) {
                  return false;
              }
          }
  
          return true;
      }
  
      bool inCorrectOrder(string& w1, string& w2, vector<int>& rank) {
          int n1 = w1.size(), n2 = w2.size();
  
          for (int i = 0; i < min(n1, n2); i++) {
              if (w1[i] != w2[i]) {
                  // Compare based on alien order
                  return rank[w1[i] - 'a'] < rank[w2[i] - 'a'];
              }
          }
  
          // If all characters matched but lengths differ:
          // shorter word should come first
          return n1 <= n2;
      }
  };
  