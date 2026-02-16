#include<iostream>
#include <string>
#include<stack>
using namespace std;


//Time Complexity = O(n)
//Space Complexity = O(n)
class Solution {
  public:
      int minParentheses(string& s) {
          stack<char> st; 
          int count = 0;
  
          for (char c : s) {
              if (c == '(') {
                  st.push(c);
              }
              else if (c == ')') {
                  if (!st.empty() && st.top() == '(') {
                      st.pop();   // match mila, remove '('
                  } else {
                      count++;   // extra ')' mila
                  }
              }
          }
  
          // count = extra ')'
          // st.size() = unmatched '('
          return count + st.size(); 
      }
  };


//Time Complexity = O(n)
//Space Complexity = O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, res = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else { // c == ')'
                if (balance > 0) balance--;
                else res++;
            }
        }
        return res + balance;
    }
};

// ---------------- MAIN ----------------
int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minAddToMakeValid(s) << endl;

    return 0;
}
