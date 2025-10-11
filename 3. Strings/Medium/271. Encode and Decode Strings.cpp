#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
      // Function to encode a list of strings into a single string
      string encode(vector<string>& s) {
          string encoded = "";
          for (string str : s) {
              // Add length of string + '#' + actual string
              encoded += to_string(str.size()) + "#" + str;
          }
          return encoded;
      }
  
      // Function to decode the encoded string back into list of strings
      vector<string> decode(string& s) {
          vector<string> result;
          int i = 0;
          while (i < s.size()) {
              int j = i;
              // find position of '#'
              while (s[j] != '#') {
                  j++;
              }
              int len = stoi(s.substr(i, j - i));   // extract the length
              string word = s.substr(j + 1, len);   // extract the next 'len' chars
              result.push_back(word);
              i = j + 1 + len;                      // move to the next string
          }
          return result;
      }
  };