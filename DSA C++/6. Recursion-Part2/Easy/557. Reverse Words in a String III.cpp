// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

// Example 2:

// Input: s = "Mr Ding"
// Output: "rM gniD"

 

// Constraints:

//     1 <= s.length <= 5 * 104
//     s contains printable ASCII characters.
//     s does not contain any leading or trailing spaces.
//     There is at least one word in s.
//     All the words in s are separated by a single space.
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      string reverseWords(string s) {
          int n = s.size();
  
          int i = 0;
          while(i < n) {
              int j = i;
  
              // find end of word
              while(j < n && s[j] != ' ') {
                  j++;
              }
  
              // reverse current word
              reverse(s.begin() + i, s.begin() + j);
  
              // move to next word
              i = j + 1;
          }
  
          return s;
      }
  };