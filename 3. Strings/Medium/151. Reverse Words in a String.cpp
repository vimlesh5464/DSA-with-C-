#include <iostream>
#include<string>
using namespace std;
//leetcode style
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
  
//gfg style
  //Reverse each word in a given string

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string result = "";
        int i = 0;

        while (i < n) {
            // 1️⃣ Skip leading / multiple spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // 2️⃣ Find the word
            int start = i;
            while (i < n && s[i] != ' ') i++;
            int end = i - 1;

            // 3️⃣ Reverse the word
            for (int j = end; j >= start; j--) {
                result += s[j];
            }

            // 4️⃣ Add space after each word
            result += ' ';
        }

        // 5️⃣ Remove trailing space
        if (!result.empty()) result.pop_back();

        return result;
    }
};
