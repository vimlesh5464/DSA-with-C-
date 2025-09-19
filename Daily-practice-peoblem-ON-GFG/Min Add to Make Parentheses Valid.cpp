// Min Add to Make Parentheses Valid
// Difficulty: MediumAccuracy: 73.56%Submissions: 2K+Points: 4

// You are given a string s consisting only of the characters '(' and ')'. Your task is to determine the minimum number of parentheses (either '(' or ')') that must be inserted at any positions to make the string s a valid parentheses string.

// A parentheses string is considered valid if:

//     Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
//     Every closing parenthesis ')' has a corresponding opening parenthesis '('.
//     Parentheses are properly nested.

// Examples:

// Input: s = "(()("
// Output: 2
// Explanation: There are two unmatched '(' at the end, so we need to add two ')' to make the string valid.

// Input: s = ")))"
// Output: 3
// Explanation: Three '(' need to be added at the start to make the string valid.

// Input: s = ")()()"
// Output: 1 
// Explanation: The very first ')' is unmatched, so we need to add one '(' at the beginning.

// Constraints:
// 1 ≤ s.size() ≤ 105
// s[i] ∈ { '(' , ')' }

#include <iostream>     
#include<string>
#include<vector>
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


//Optimized Code (O(1) space)
class Solution {
  public:
      int minParentheses(string& s) {
          int open = 0;   // unmatched '(' ka count
          int count = 0;  // extra ')' ka count
  
          for (char c : s) {
              if (c == '(') {
                  open++;
              } else { // c == ')'
                  if (open > 0) {
                      open--;   // ek '(' match ho gaya
                  } else {
                      count++;  // extra ')' mila
                  }
              }
          }
  
          // count = extra ')'
          // open = leftover '('
          return count + open;
      }
  };
  
int main() {
    Solution sol;
    
    string s1 = "())(";
    cout << "Input: " << s1 << " -> Min Add = " << sol.minParentheses(s1) << endl;

    string s2 = "(((";
    cout << "Input: " << s2 << " -> Min Add = " << sol.minParentheses(s2) << endl;

    string s3 = "(()())";
    cout << "Input: " << s3 << " -> Min Add = " << sol.minParentheses(s3) << endl;

    string s4 = ")(";
    cout << "Input: " << s4 << " -> Min Add = " << sol.minParentheses(s4) << endl;

    return 0;
}
