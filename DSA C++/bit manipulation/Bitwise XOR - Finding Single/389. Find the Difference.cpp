#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
  public:
      char findTheDifference(string s, string t) {
          char result = 0;
          
          for(char c : s)
              result ^= c;
          
          for(char c : t)
              result ^= c;
          
          return result;
      }
  };

  class Solution {
    public:
        char findTheDifference(string s, string t) {
            vector<int> freq(26, 0);
            
            for(char c : s)
                freq[c - 'a']++;
            
            for(char c : t) {
                freq[c - 'a']--;
                if(freq[c - 'a'] < 0)
                    return c;
            }
            
            return ' ';
        }
    };