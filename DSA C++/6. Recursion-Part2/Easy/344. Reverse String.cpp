// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

 

// Constraints:

//     1 <= s.length <= 105
//     s[i] is a printable ascii character.


#include<iostream>

#include<vector>
using namespace std;
class Solution {
  public:
      void helper(vector<char>& s, int left, int right) {
          // Base case: when pointers cross, stop recursion
          if (left >= right) return;
  
          // Swap characters
          swap(s[left], s[right]);
  
          // Recursive call for next positions
          helper(s, left + 1, right - 1);
      }
  
      void reverseString(vector<char>& s) {
          helper(s, 0, s.size() - 1);
      }
  };