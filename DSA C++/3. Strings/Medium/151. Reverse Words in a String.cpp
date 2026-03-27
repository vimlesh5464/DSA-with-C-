// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

 

// Constraints:

//     1 <= s.length <= 104
//     s contains English letters (upper-case and lower-case), digits, and spaces ' '.
//     There is at least one word in s.

 

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
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
