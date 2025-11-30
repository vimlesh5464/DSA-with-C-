#include <iostream>
#include<string>
using namespace std;

class Solution {
  public:
      bool isPalindromeRange(string &s, int left, int right) {
          while (left < right) {
              if (s[left] != s[right]) return false;
              left++;
              right--;
          }
          return true;
      }
  
      bool validPalindrome(string s) {
          int left = 0, right = s.size() - 1;
  
          while (left < right) {
              if (s[left] == s[right]) {
                  left++;
                  right--;
              } 
              else {
                  // delete left OR delete right
                  return isPalindromeRange(s, left + 1, right) ||
                         isPalindromeRange(s, left, right - 1);
              }
          }
          return true;
      }
  };
  int main() {
    Solution sol;

    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = " ";

    cout << (sol.validPalindrome(test1) ? "true" : "false") << endl; // true
    cout << (sol.validPalindrome(test2) ? "true" : "false") << endl; // false
    cout << (sol.validPalindrome(test3) ? "true" : "false") << endl; // true

    return 0;
}