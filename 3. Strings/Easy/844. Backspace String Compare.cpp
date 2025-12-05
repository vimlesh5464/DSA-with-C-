#include <iostream>
#include<string>
using namespace std;
class Solution {
  public:
      bool backspaceCompare(string s, string t) {
          int i = s.size() - 1;
          int j = t.size() - 1;
  
          int skipS = 0;
          int skipT = 0;
  
          while (i >= 0 || j >= 0) {
              
              // Process s
              while (i >= 0) {
                  if (s[i] == '#') {
                      skipS++;
                      i--;
                  } else if (skipS > 0) {
                      skipS--;
                      i--;
                  } else {
                      break;
                  }
              }
  
              // Process t
              while (j >= 0) {
                  if (t[j] == '#') {
                      skipT++;
                      j--;
                  } else if (skipT > 0) {
                      skipT--;
                      j--;
                  } else {
                      break;
                  }
              }
  
              // Compare characters
              if (i >= 0 && j >= 0 && s[i] != t[j])
                  return false;
  
              // If one string finished but the other didn’t
              if ((i >= 0) != (j >= 0))
                  return false;
  
              i--; j--;
          }
  
          return true;
      }
  };
  