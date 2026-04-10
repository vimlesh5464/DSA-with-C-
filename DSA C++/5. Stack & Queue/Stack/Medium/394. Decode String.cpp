// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square 
//brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, 
//square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.
// Example 1:
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Example 2:
// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Example 3:
// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

// Constraints:
//     1 <= s.length <= 30
//     s consists of lowercase English letters, digits, and square brackets '[]'.
//     s is guaranteed to be a valid input.
//     All the integers in s are in the range [1, 300]
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
  public:
      string decodeString(string s) {
          // Stack to store characters of string
          stack<char> st;
  
          // Traverse the entire string
          for (int i = 0; i < s.size(); i++) {
  
              // If current char is not ']', push into stack
              if (s[i] != ']') {
                  st.push(s[i]);
              }
              else {
                  // When we find ']', we start decoding
  
                  string word;
  
                  // Step 1: Extract the encoded string inside [ ]
                  while (!st.empty() && st.top() != '[') {
                      word.push_back(st.top());
                      st.pop();
                  }
  
                  // Reverse because stack gives reverse order
                  reverse(word.begin(), word.end());
  
                  // Remove '[' from stack
                  st.pop();
  
                  // Step 2: Extract the number (k) before '['
                  string k;
  
                  while (!st.empty() && isdigit(st.top())) {
                      k.push_back(st.top());
                      st.pop();
                  }
  
                  // Reverse to get correct number order
                  reverse(k.begin(), k.end());
  
                  // Convert string to integer
                  int num = stoi(k);
  
                  // Step 3: Repeat decoded string num times
                  string repeated;
  
                  for (int j = 0; j < num; j++) {
                      repeated.append(word);
                  }
  
                  // Push repeated string back into stack
                  for (char c : repeated) {
                      st.push(c);
                  }
              }
          }
  
          // Step 4: Build final answer from stack
          string ans;
  
          while (!st.empty()) {
              ans.push_back(st.top());
              st.pop();
          }
  
          // Reverse because stack gives reverse order
          reverse(ans.begin(), ans.end());
  
          return ans;
      }
  };