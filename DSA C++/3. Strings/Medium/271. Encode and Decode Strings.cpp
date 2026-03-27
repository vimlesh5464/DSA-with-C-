// Given an array of strings s[], you are required to create an algorithm in the encode() function that can convert the given strings into a single encoded string, which can be transmitted over the network and then decoded back into the original array of strings. The decoding will happen in the decode() function.

// You need to implement two functions:
// 1. encode(): This takes an array of strings s[] and encodes it into a single string. 
// 2. decode(): This takes the encoded string as input and returns an array of strings containing the original array as given in the encode method.

// Note: You are not allowed to use any inbuilt serialize method.  

// Examples:

// Input: s = ["Hello","World"]
// Output: ["Hello","World"]
// Explanation: The encode() function will have the str as input, it will be encoded by one machine. Then another machine will receive the encoded string as the input parameter and then will decode it to its original form.

// Input: s = ["abc","!@"]
// Output: ["abc","!@"]
// Explanation: The encode() function will have the str as input, here there are two strings, one is "abc" and the other one has some special characters. It will be encoded by one machine. Then another machine will receive the encoded string as the input parameter and then will decode it to its original form.

// Constraints:
// 1<=s.size()<=100
// 1<=s[i].size()<=100
// s[i] contains any possible characters out of the 256 ASCII characters.

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