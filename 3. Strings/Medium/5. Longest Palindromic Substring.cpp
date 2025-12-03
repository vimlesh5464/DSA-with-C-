#include <iostream>
#include<string>
using namespace std;

class Solution {
  public:
      string longestPalindrome(string s) {
          if (s.length() <= 1) return s;
  
          int start = 0, maxLen = 1;
  
          for (int i = 0; i < s.length(); i++) {
              // Odd length
              expand(s, i, i, start, maxLen);
  
              // Even length
              expand(s, i, i + 1, start, maxLen);
          }
          return s.substr(start, maxLen);
      }
  
      void expand(string &s, int left, int right, int &start, int &maxLen) {
          while (left >= 0 && right < s.length() && s[left] == s[right]) {
              left--;
              right++;
          }
  
          int len = right - left - 1;
          if (len > maxLen) {
              maxLen = len;
              start = left + 1;
          }
      }
  };
  