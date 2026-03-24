// Given a string s of '(' , ')' and lowercase English characters.

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions )
// so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

//     It is the empty string, contains only lowercase characters, or
//     It can be written as AB (A concatenated with B), where A and B are valid strings, or
//     It can be written as (A), where A is a valid string.

 

// Example 1:
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

// Example 2:
// Input: s = "a)b(c)d"
// Output: "ab(c)d"

// Example 3:
// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.

 

// Constraints:
//     1 <= s.length <= 105
//     s[i] is either '(' , ')', or lowercase English letter.

#include<iostream>
#include <string>
#include<stack>
using namespace std;

class Solution {
  public:
      string minRemoveToMakeValid(string s) {
          stack<int> st; // indices of '('
  
          // Step 1: Traverse string
          for (int i = 0; i < s.size(); i++) {
              if (s[i] == '(') {
                  st.push(i); // possible unmatched '('
              } 
              else if (s[i] == ')') {
                  if (!st.empty()) st.pop(); // matched '('
                  else s[i] = '#';          // unmatched ')', mark for removal
              }
          }
  
          // Step 2: Any '(' left in stack are unmatched
          while (!st.empty()) {
              s[st.top()] = '#';
              st.pop();
          }
  
          // Step 3: Build result skipping '#'
          string res = "";
          for (char c : s) {
              if (c != '#') res += c;
          }
  
          return res;
      }
  };

// ---------------- MAIN ----------------
int main() {
    string s;
    getline(cin, s); // read full line including spaces

    Solution sol;
    string valid = sol.minRemoveToMakeValid(s);

    cout << valid << endl;

    return 0;
}
