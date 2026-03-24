// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

// Example 1:

// Input: s = "IceCreAm"

// Output: "AceCreIm"

// Explanation:

// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Example 2:

// Input: s = "leetcode"

// Output: "leotcede"

 

// Constraints:

//     1 <= s.length <= 3 * 105
//     s consist of printable ASCII characters.

#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Solution {
  public:
      bool isVowel(char c) {
          c = tolower(c);
          return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
      }
  
      string reverseVowels(string s) {
          int l = 0, r = s.size() - 1;
  
          while (l < r) {
              while (l < r && !isVowel(s[l])) l++;
              while (l < r && !isVowel(s[r])) r--;
  
              swap(s[l], s[r]);
              l++; r--;
          }
          return s;
      }
  };
  