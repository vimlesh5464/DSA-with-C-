#include<iostream>
#include <string>
#include<stack>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> st;

      // Push -1 as the initial index to 
      // handle the edge case
      st.push(-1);
      int maxLen = 0;
      
      for (int i = 0; i < s.length(); i++) {
          
          // If we encounter an opening parenthesis,
          // push its index
          if (s[i] == '(') {
              st.push(i);
          } 
          else {
              
              // If we encounter a closing parenthesis,
              // pop the stack
              st.pop();
  
              // If stack is empty, push the current index 
              // as a base for the next valid substring
              if (st.empty()) {
                  st.push(i);
              } else {
                  
                  // Update maxLength with the current length 
                  // of the valid parentheses substring
                  maxLen = max(maxLen, i - st.top());
              }
          }
      }
      return maxLen;
    }
};

// ---------------- MAIN ----------------
int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.longestValidParentheses(s) << endl;

    return 0;
}
