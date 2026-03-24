// In an alien language, surprisingly, they also use English lowercase letters, 
//but possibly in a different order. The order of the alphabet is some permutation 
//of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the 
//alphabet, return true if and only if the given words are sorted lexicographically 
//in this alien language.

 

// Example 1:

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

// Example 2:

// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

// Example 3:

// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

 

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length <= 20
//     order.length == 26
//     All characters in words[i] and order are English lowercase letters.

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
  public:
      bool isAlienSorted(vector<string>& words, string order) {
          // Mapping for alien order
          vector<int> rank(26);
          for (int i = 0; i < 26; i++) {
              rank[order[i] - 'a'] = i;
          }
  
          // Compare each adjacent pair
          for (int i = 0; i < words.size() - 1; i++) {
              if (!inCorrectOrder(words[i], words[i + 1], rank)) {
                  return false;
              }
          }
  
          return true;
      }
  
      bool inCorrectOrder(string& w1, string& w2, vector<int>& rank) {
          int n1 = w1.size(), n2 = w2.size();
  
          for (int i = 0; i < min(n1, n2); i++) {
              if (w1[i] != w2[i]) {
                  // Compare based on alien order
                  return rank[w1[i] - 'a'] < rank[w2[i] - 'a'];
              }
          }
  
          // If all characters matched but lengths differ:
          // shorter word should come first
          return n1 <= n2;
      }
  };
  