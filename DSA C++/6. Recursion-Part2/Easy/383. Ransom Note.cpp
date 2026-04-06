// Given two strings ransomNote and magazine, return true if ransomNote 
//can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

 

// Constraints:

//     1 <= ransomNote.length, magazine.length <= 105
//     ransomNote and magazine consist of lowercase English letters.

#include<iostream>

#include<vector>
using namespace std;

class Solution {
  public:
      bool canConstruct(string ransomNote, string magazine) {
          int n = ransomNote.size();
          int m = magazine.size();
  
          for(int i = 0; i < n; i++) {
              bool found = false;
  
              for(int j = 0; j < m; j++) {
                  if(ransomNote[i] == magazine[j]) {
                      found = true;
                      magazine[j] = '#'; // mark as used
                      break;
                  }
              }
  
              if(!found) return false;
          }
  
          return true;
      }
  };

  class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            // frequency array for 26 lowercase letters
            int freq[26] = {0};
    
            // Step 1: count characters in magazine
            for(char ch : magazine) {
                freq[ch - 'a']++;
            }
    
            // Step 2: use characters for ransomNote
            for(char ch : ransomNote) {
                freq[ch - 'a']--;
    
                // if count goes negative → not enough characters
                if(freq[ch - 'a'] < 0) {
                    return false;
                }
            }
    
            return true;
        }
    };