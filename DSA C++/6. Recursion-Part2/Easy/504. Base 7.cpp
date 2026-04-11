// Given an integer num, return a string of its base 7 representation.

 

// Example 1:

// Input: num = 100
// Output: "202"

// Example 2:

// Input: num = -7
// Output: "-10"

 

// Constraints:

//     -107 <= num <= 107

#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      string convertToBase7(int num) {
          if(num == 0) return "0";   // fix 1
  
          bool negative = num < 0;   // fix 2
          num = abs(num);
  
          string s = "";
  
          while(num != 0){
              int digit = num % 7;
              s += (digit + '0');   // faster than to_string
              num /= 7;
          }
  
          reverse(s.begin(), s.end());  // fix 3
  
          if(negative) s = "-" + s;     // handle negative
  
          return s;
      }
  };