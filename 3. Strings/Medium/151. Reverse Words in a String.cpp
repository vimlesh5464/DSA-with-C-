#include <iostream>
#include<string>
using namespace std;
class Solution {
  public:
      string reverseWords(string s) {
          // Step 1: Remove extra spaces
          string temp = "";
          int n = s.size();
          for(int i=0; i<n; i++){
              if(s[i] != ' ')
                  temp += s[i];
              else if(!temp.empty() && temp.back() != ' ')
                  temp += ' ';
          }
          if(temp.back() == ' ') temp.pop_back();
          
          // Step 2: Reverse whole string
          reverse(temp.begin(), temp.end());
  
          // Step 3: Reverse each word
          int i = 0;
          int start = 0;
          while(i <= temp.size()) {
              if(i == temp.size() || temp[i] == ' ') {
                  reverse(temp.begin() + start, temp.begin() + i);
                  start = i + 1;
              }
              i++;
          }
  
          return temp;
      }
  };
  